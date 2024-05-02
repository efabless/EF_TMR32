from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from EF_UVM.bus_env.bus_item import bus_item
from uvm.base.uvm_config_db import UVMConfigDb
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random
from tmr32_seq_lib.timer_config import timer_config


class pwm_actions_seq(timer_config):

    def __init__(self, name="pwm_actions_seq"):
        super().__init__(name)

    async def body(self):
        # get register names/address conversion dict
        await super().body()
        await self.pwm0_seq()
        await self.pwm_delay()
        await self.send_reset()
        await self.pwm1_seq()
        await self.pwm_delay()
        for _ in range(10):
            await self.send_reset()
            await self.pwm_seq()
            await self.pwm_delay()

    async def pwm0_seq(self):
        await self.config_regs()
        is_inverted = random.randint(0, 1)
        await self.start_timer(pwm_enable=[1, 0], pwm_inverted=[is_inverted, 0])

    async def pwm1_seq(self):
        await self.config_regs()
        is_inverted = random.randint(0, 1)
        await self.start_timer(pwm_enable=[0, 1], pwm_inverted=[0, is_inverted])

    async def pwm_seq(self):
        await self.config_regs()
        is_inverted0 = random.randint(0, 1)
        is_inverted1 = random.randint(0, 1)
        await self.start_timer(
            pwm_enable=[1, 1], pwm_inverted=[is_inverted0, is_inverted1]
        )

    async def config_regs(self):
        await self.set_timer_pr()
        await self.set_timer_mode(is_periodic=True)
        await self.config_timer_regs()
        await self.set_pwm_actions()

    async def pwm_delay(self):
        await Timer(500, "us")


uvm_object_utils(pwm_actions_seq)
