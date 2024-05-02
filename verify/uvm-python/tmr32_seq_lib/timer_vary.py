from tmr32_seq_lib.timer_config import timer_config
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.macros.uvm_object_defines import uvm_object_utils
import random
from cocotb_coverage.coverage import coverage_db
from uvm.base.uvm_object_globals import UVM_FULL, UVM_LOW, UVM_ERROR


class timer_vary(timer_config):
    def __init__(self, name="timer_vary"):
        super().__init__(name)

    async def body(self):
        # get register names/address conversion dict
        await super().body()
        for i in range(1):
            await self.config_timer()
            for _ in range(random.randint(1, 1000)):
                await self.read_timer_val()
            await self.stop_timer()
        # loop until getting 100% coverage
        for _ in range(30):
            detailed_coverage, cover_percentage = self.get_coverage()
            if cover_percentage == 100:
                return
            for bin, value in detailed_coverage.items():
                if value == 0:
                    uvm_info(self.tag, f"bin {bin} not covered", UVM_LOW)
                    is_periodic = bin[0] == "periodic"
                    dir = bin[1]
                    is_low_speed = bin[2] == "low speed counting"
                    await self.config_timer_with_cond(is_periodic, dir, is_low_speed)
                    for _ in range(random.randint(1, 1000)):
                        await self.read_timer_val()
                    await self.stop_timer()

    def get_coverage(self):
        detailed_coverage = coverage_db[
            "top.tmr32.timer.read timer values"
        ].detailed_coverage
        cover_percentage = coverage_db[
            "top.tmr32.timer.read timer values"
        ].cover_percentage
        uvm_info(
            self.tag,
            f"cover_percentage: {cover_percentage}, detailed_coverage: {detailed_coverage}",
            UVM_LOW,
        )
        return detailed_coverage, cover_percentage

    async def config_timer_with_cond(
        self, is_periodic=True, dir="up counting", is_low_speed=True
    ):
        await self.set_timer_pr((1, 0x6) if not is_low_speed else (0x7, 0xF))
        await self.set_timer_mode(
            is_periodic,
            dir=(
                0b10
                if dir == "up counting"
                else 0b01 if dir == "down counting" else 0b11
            ),
        )
        await self.config_timer_regs()
        await self.start_timer()


uvm_object_utils(timer_vary)
