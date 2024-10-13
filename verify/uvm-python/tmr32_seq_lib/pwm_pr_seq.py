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


class pwm_pr_seq(timer_config):

    def __init__(self, name="pwm_pr_seq"):
        super().__init__(name)

    async def body(self):
        # get register names/address conversion dict
        await super().body()
        counter = 0
        while True:
            pr_ranges = self.update_pr_from_cov()
            if len(pr_ranges) == 0:
                break
            for pr_range in pr_ranges:
                await self.send_reset()
                await self.pwm_seq(pr_range)
                await self.wait_pwm_deteced()
            counter += 1
            if counter == 7:
                break 

    def update_pr_from_cov(self):
        pr_ranges = []
        coverage_dict, _ = self.get_coverage()
        for cov_point in coverage_dict.items():
            if cov_point[1] == 0:
                pr_ranges.append(cov_point[0])
        uvm_info(self.tag, f"pr ranges: {pr_ranges}", UVM_LOW)
        return pr_ranges

    async def pwm_seq(self, pr_range):
        await self.config_regs(pr_range)
        is_inverted0 = random.randint(0, 1)
        is_inverted1 = random.randint(0, 1)
        await self.start_timer(
            pwm_enable=[1, 1], pwm_inverted=[is_inverted0, is_inverted1]
        )

    async def config_regs(self, pr_range):
        await self.send_req(is_write=True, reg="CLKGATE", data_condition=lambda data: data == 1)
        await self.set_timer_pr(pr_range)
        await self.set_timer_mode(is_periodic=True)
        await self.config_timer_regs()
        await self.set_pwm_actions()

    async def pwm_delay(self, largest_pr):
        clock_period = 10
        pr = largest_pr
        largest_reload = 0xFF
        extended_factor = 20
        await Timer(pr * clock_period * extended_factor * largest_reload, "ns")

    def get_coverage(self):
        detailed_coverage = coverage_db["top.pwm.Prescaler"].detailed_coverage
        cover_percentage = coverage_db["top.pwm.Prescaler"].cover_percentage
        uvm_info(
            self.tag,
            f"cover_percentage: {cover_percentage}, detailed_coverage: {detailed_coverage}",
            UVM_LOW,
        )
        return detailed_coverage, cover_percentage


uvm_object_utils(pwm_pr_seq)
