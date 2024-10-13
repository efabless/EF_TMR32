from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from EF_UVM.bus_env.bus_item import bus_item
from uvm.base.uvm_config_db import UVMConfigDb
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random
from tmr32_seq_lib.timer_config import timer_config
from cocotb_coverage.coverage import coverage_db
from uvm.base.uvm_object_globals import UVM_FULL, UVM_LOW, UVM_ERROR
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info


class pwm_tmr_seq(timer_config):
    def __init__(self, name="pwm_tmr_seq"):
        super().__init__(name)

    async def body(self):
        # get register names/address conversion dict
        await super().body()
        counter = 0
        while True:
            reload_vals = self.update_reload_from_cov()
            if len(reload_vals) == 0:
                break
            for reload_val in reload_vals:
                await self.send_reset()
                await self.pwm_seq(reload_val)
                await self.wait_pwm_deteced()
            counter += 1
            if counter == 7:
                break

    def update_reload_from_cov(self):
        reload_vals = []
        coverage_dict, _ = self.get_coverage()
        for cov_point in coverage_dict.items():
            if cov_point[1] == 0:
                reload_vals.append(cov_point[0][1])
        uvm_info(self.tag, f"reload largest values: {reload_vals}", UVM_LOW)
        return reload_vals

    async def pwm_seq(self, largest_reload):
        await self.config_regs(largest_reload)
        is_inverted0 = random.randint(0, 1)
        is_inverted1 = random.randint(0, 1)
        await self.start_timer(
            pwm_enable=[1, 1], pwm_inverted=[is_inverted0, is_inverted1]
        )

    async def config_regs(self, largest_reload):
        await self.send_req(is_write=True, reg="CLKGATE", data_condition=lambda data: data == 1)
        await self.set_timer_pr()
        await self.set_timer_mode(is_periodic=True)
        await self.config_timer_regs(largest_reload)
        await self.set_pwm_actions()

    async def pwm_delay(self, relaod_large_val):
        clock_period = 10
        pr = 10
        largest_reload = relaod_large_val
        extended_factor = 20
        await Timer(pr * clock_period * extended_factor * largest_reload, "ns")

    def get_coverage(self):
        detailed_coverage = coverage_db[
            "top.pwm.Compare Values.Relaod"
        ].detailed_coverage
        cover_percentage = coverage_db["top.pwm.Compare Values.Relaod"].cover_percentage
        uvm_info(
            self.tag,
            f"cover_percentage: {cover_percentage}, detailed_coverage: {detailed_coverage}",
            UVM_LOW,
        )
        return detailed_coverage, cover_percentage


uvm_object_utils(pwm_tmr_seq)
