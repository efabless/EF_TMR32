from uvm.base.uvm_component import UVMComponent
from uvm.macros import uvm_component_utils
from uvm.tlm1.uvm_analysis_port import UVMAnalysisImp
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.tlm1.uvm_analysis_port import UVMAnalysisExport
from EF_UVM.ref_model.ref_model import ref_model
from EF_UVM.bus_env.bus_item import bus_item
from tmr32_item.tmr32_item import tmr32_pwm_item
from EF_UVM.ip_env.ip_agent.ip_monitor import ip_monitor
from cocotb.triggers import (
    Timer,
    ClockCycles,
    FallingEdge,
    Event,
    RisingEdge,
    Combine,
    First,
)
import cocotb


class tmr32_VIP(ref_model):
    def __init__(self, name="tmr32_VIP", parent=None):
        super().__init__(name, parent)
        self._timer_first_flag = False
        self.event_calibrate_tmr = Event("event_calibrate_tmr")

    def build_phase(self, phase):
        super().build_phase(phase)
        arr = []
        if not UVMConfigDb.get(self, "", "bus_regs", arr):
            uvm_fatal(self.tag, "No json file wrapper regs")
        else:
            self.regs = arr[0]
        self.bus_write_event = Event("bus_write_event")
        self.clock_period = 10

    async def run_phase(self, phase):
        super().run_phase(phase)
        while True:
            await self.wait_start_counting()
            timer_fork = await cocotb.start(self.timer())
            await self.wait_for_stop_counting()
            timer_fork.kill()
            self._timer_first_flag = False

    def write_bus(self, tr):
        uvm_info(self.tag, "Vip write: " + tr.convert2string(), UVM_HIGH)
        if tr.kind == bus_item.RESET:
            self.bus_bus_export.write(tr)
            uvm_info("vip", "reset from the vip", UVM_LOW)
            self.regs.write_reg_value("CTRL", 0, force_write=True)
            return
        if tr.kind == bus_item.WRITE:
            self.bus_write_event.set()
            self.regs.write_reg_value(tr.addr, tr.data)
            self.bus_bus_export.write(tr)
        elif tr.kind == bus_item.READ:
            if tr.addr == self.regs.reg_name_to_address["TMR"]:
                if not self._timer_first_flag:
                    # calibrate the timer
                    self._timer_first_flag = True
                    self.regs.write_reg_value("TMR", tr.data, force_write=True)
                    self.bus_bus_export.write(tr)
                    self.event_calibrate_tmr.set()
                else:
                    # check if diffrence is 1 ignore it
                    ref_tmr = self.regs.read_reg_value(tr.addr)
                    if (abs(ref_tmr - tr.data) < 2) or (
                        abs(ref_tmr - tr.data) == self.regs.read_reg_value("RELOAD")
                    ):  # ignore this shift and pass the correct value
                        data = tr.data
                    else:  # pass the incorrect value
                        data = ref_tmr
                    td = tr.do_clone()
                    td.data = data
                    self.bus_bus_export.write(td)
            else:
                data = self.regs.read_reg_value(tr.addr)
                td = tr.do_clone()
                td.data = data
                self.bus_bus_export.write(td)
        self.bus_write_event.clear()

    def write_ip(self, tr):
        uvm_info(self.tag, "ip Vip write: " + tr.convert2string(), UVM_HIGH)
        # when monitor detect patterns the vip should also send pattern
        td = tmr32_pwm_item.type_id.create("td", self)
        td.source = tr.source
        td.pattern = self.generate_patterns(tr.source)
        self.ip_export.write(td)

    async def timer(self):
        mode = self.regs.read_reg_value("CFG") & 0b11
        PR = self.regs.read_reg_value("PR")
        counter = (
            0
            if self.regs.read_reg_value("CFG") & 0b10 == 0b10
            else self.regs.read_reg_value("RELOAD")
        )  # 0 counting up or up/down reload count down
        uvm_info(
            self.tag,
            f"function timer mode = {bin(mode)} and PR = {bin(PR)} counter = {counter} ",
            UVM_LOW,
        )
        # await self.event_calibrate_tmr.wait()
        # self.event_calibrate_tmr.clear()
        # counter_calibration_val = self.regs.read_reg_value("TMR")
        # counter = counter_calibration_val + 1 if self.regs.read_reg_value("CFG") & 0b10 == 0b10 else counter_calibration_val - 1
        count_step = (self.regs.read_reg_value("PR") + 1) * self.clock_period
        count_type = "up" if self.regs.read_reg_value("CFG") & 0b10 == 0b10 else "down"
        uvm_info(
            self.tag, f"count_step: {count_step}, count_type: {count_type}", UVM_HIGH
        )
        # if PR >= 2:
        #     await Timer(self.clock_period * 2, 'ns')

        await Timer(self.clock_period, "ns")
        self.regs.write_reg_value("TMR", counter, force_write=True)
        uvm_info(self.tag, f"counter: {hex(counter)}", UVM_HIGH)
        while True:
            if count_type == "up":
                counter += 1
                if counter >= self.regs.read_reg_value("RELOAD"):
                    if (
                        self.regs.read_reg_value("CFG") & 0b11 == 0b11
                    ):  # mode is up/dowm
                        count_type = "down"
                    elif counter == self.regs.read_reg_value("RELOAD") + 1:
                        counter = 0
                        if (
                            self.regs.read_reg_value("CFG") & 0b100 == 0b0
                        ):  # oneshot mode
                            return
            else:
                counter -= 1
                if counter <= 0:
                    if (
                        self.regs.read_reg_value("CFG") & 0b11 == 0b11
                    ):  # mode is up/dowm
                        if (
                            self.regs.read_reg_value("CFG") & 0b100 == 0b0
                        ):  # oneshot mode
                            if counter == -1:
                                return
                        else:
                            count_type = "up"
                    elif counter == -1:
                        counter = self.regs.read_reg_value("RELOAD")
                        if (
                            self.regs.read_reg_value("CFG") & 0b100 == 0b0
                        ):  # oneshot mode
                            return
            await Timer(count_step, "ns")
            self.regs.write_reg_value("TMR", counter, force_write=True)
            uvm_info(self.tag, f"counter: {hex(counter)}", UVM_HIGH)

    async def wait_start_counting(self):
        # start counting when timer enable 1 then 0
        while self.regs.read_reg_value("CTRL") & 0b1 != 0b1:  # wait until timer enable
            await self.bus_write_event.wait()
        uvm_info("vip", f"start counting from vip", UVM_LOW)
        # while self.regs.read_reg_value("CTRL") & 0b11 != 0b01:  # wait until timer restarted
        #     await self.bus_write_event.wait()

    async def wait_for_stop_counting(self):
        while (
            self.regs.read_reg_value("CTRL") & 0b1 != 0b0
        ):  # wait until timer restarted
            await self.bus_write_event.wait()
        uvm_info("vip", f"stop counting from vip", UVM_LOW)

    def calculate_timeout_cycles(self):
        num_cycles = self.regs.read_reg_value("RELOAD") * (
            self.regs.read_reg_value("PR") + 1
        )
        uvm_info(
            self.tag,
            f"[calculate_timeout_cycles] reload = {self.regs.read_reg_value('RELOAD')} and pr = {self.regs.read_reg_value('PR')}",
            UVM_MEDIUM,
        )
        return num_cycles

    def generate_patterns(self, source):
        def merge_similar(pattern1):
            if len(pattern1) < 2:
                return pattern1
            if pattern1[0][0] == pattern1[-1][0]:
                new_element = (pattern1[0][0], pattern1[0][1] + pattern1[-1][1])
                pattern1 = pattern1[:-1]
                pattern1[0] = new_element
            return pattern1

        def rearrange_actions(actions):
            # remove if number of cycles == 0
            # before remove it should affect the next action
            to_remove = []
            for i in range(len(actions)):
                if actions[i][1] == 0:
                    to_remove.append(i)
                    if (
                        actions[i][0] == "no change"
                    ):  # no change should not affect the next action
                        continue
                    elif actions[i + 1][0] == "no change":
                        actions[i + 1] = (actions[i][0], actions[i + 1][1])
                    # elif actions[i + 1][0] == "inverted":
                    #     if actions[i][0] == "high":
                    #         actions[i + 1] = ("low", actions[i + 1][1])
                    #     elif actions[i][0] == "low":
                    #         actions[i + 1][0] = ("high", actions[i + 1][1])
                    #     elif actions[i][0] == "inverted":
                    #         actions[i + 1][0] = ("no change", actions[i + 1][1])
            actions = [i for i in actions if i not in to_remove]
            actions = [action for action in actions if action[1] != 0]
            # can't begin the action with no change
            if actions[0][0] not in ["no change", "inverted"]:
                return actions
            i = 0
            for index, action in enumerate(actions):
                if action[0] not in ["no change", "inverted"]:
                    i = index
                    break
            actions = actions[i:] + actions[:i]
            return actions

        def try_initial(actions, initial):
            for action in actions:
                if action[0] == "no change":
                    continue
                elif action[0] == "high":
                    initial = 1
                elif action[0] == "low":
                    initial = 0
                elif action[0] == "inverted":
                    initial = 1 - initial
            return initial

        def pattern_from_action(actions):
            pattern = []
            # check if the initial value matter
            if actions[0][0] in ["high", "low"]:
                initial_values = [0]  # initial doesn't matter
            elif actions[0][0] in ["inverted"]:
                if (
                    try_initial(actions, 0) == 0 and try_initial(actions, 1) == 1
                ):  # loop the same value
                    initial_values = [0]  # assume 0 is initial value after reset
                elif try_initial(actions, 0) == try_initial(actions, 1):
                    initial_values = [try_initial(actions, 0)]
                else:
                    initial_values = [try_initial(actions, 1), try_initial(actions, 0)]
            else:
                initial_values = [0]
            # for action in actions:
            #     if action[0] == "high":
            #         initial_values = [1]
            #     elif action[0] == "low":
            #         initial_values = [0]
            #     elif action[0] == "inverted":
            #         if len(initial_values) == 1:
            #             initial_values = [1 - initial_values[0]]

            uvm_info(self.tag, f"initial_values: {initial_values}", UVM_MEDIUM)
            # if there is no fixed value 2 initial values are needed
            for i in initial_values:
                old_val = i
                count = 0
                for i, action in enumerate(actions):
                    if action[0] == "no change":
                        val = old_val
                    elif action[0] == "high":
                        val = 1
                    elif action[0] == "low":
                        val = 0
                    elif action[0] == "inverted":
                        val = 1 - old_val
                    if val == old_val or i == 0:
                        count += action[1]
                    elif val != old_val:
                        pattern.append((old_val, count))
                        count = action[1]
                    old_val = val
                if count > 0:
                    pattern.append((old_val, count))
            return pattern

        def invert_pattern(pattern):
            for i in range(len(pattern)):
                if pattern[i][0] == 1:
                    pattern[i] = (0, pattern[i][1])
                elif pattern[i][0] == 0:
                    pattern[i] = (1, pattern[i][1])
            return pattern

        def process_action(actions, is_inverted, name="pwm0"):
            compare_vals = {
                "CMPX": self.regs.read_reg_value("CMPX"),
                "CMPY": self.regs.read_reg_value("CMPY"),
                "RELOAD": self.regs.read_reg_value("RELOAD"),
            }
            actions_types = ["no change", "low", "high", "inverted"]
            clk_div = self.regs.read_reg_value("PR") + 1
            dir = self.regs.read_reg_value("CFG") & 0b11
            mode = self.regs.read_reg_value("CFG") >> 2  # 1 periodic and 0 oneshot
            if (
                mode == 0
            ):  # when oneshot mode the pwm would be generted if the last action is inverted rather than that there would not be a pattern
                return [(1, clk_div), (0, clk_div)]
            action_length = [
                compare_vals["CMPX"],
                compare_vals["CMPY"] - compare_vals["CMPX"],
                compare_vals["RELOAD"] - compare_vals["CMPY"],
            ]
            uvm_info(self.tag, f"actions values {name}: {actions}", UVM_MEDIUM)
            if dir == 0b11:  # periodic
                action_length += action_length[::-1]  # add the other direction
            elif dir == 0b10:  # up
                action_length = action_length + [
                    1
                ]  # this 1 is the cycles needed to go from top value to 0
                actions = actions[:4]
            else:  # down
                action_length = action_length[::-1] + [
                    1
                ]  # this 1 is the cycles needed to go from 0 to top value
                actions = [
                    actions[3],
                    actions[4],
                    actions[5],
                    actions[0],
                ]  # E3, E4, E5,E0
            action_length = [val * clk_div for val in action_length]
            actions = [
                (actions_types[type], action_length[index])
                for index, type in enumerate(actions)
            ]
            # actions = actions[:3]
            actions = rearrange_actions(actions)
            uvm_info(
                self.tag, f"actions after rearrange for {name}: {actions}", UVM_MEDIUM
            )
            pattern = pattern_from_action(actions)
            pattern = merge_similar(pattern)
            if is_inverted:
                pattern = [(1 - pulse_type, cycles) for pulse_type, cycles in pattern]
            return pattern

        if source == tmr32_pwm_item.pwm0:
            # check if pwm0 is disabled don't send patterns
            if self.regs.read_reg_value("CTRL") & 0b100 != 0b100:
                return None
            actions = [
                (self.regs.read_reg_value("PWM0CFG") >> i) & 0b11
                for i in range(0, 12, 2)
            ]
            is_inverted = (self.regs.read_reg_value("CTRL") >> 5) & 0b1
            return process_action(actions, is_inverted)
        elif source == tmr32_pwm_item.pwm1:
            if self.regs.read_reg_value("CTRL") & 0b1000 != 0b1000:
                return None
            actions = [
                (self.regs.read_reg_value("PWM1CFG") >> i) & 0b11
                for i in range(0, 12, 2)
            ]
            is_inverted = (self.regs.read_reg_value("CTRL") >> 6) & 0b1
            return process_action(actions, is_inverted, name="pwm1")


uvm_component_utils(tmr32_VIP)
