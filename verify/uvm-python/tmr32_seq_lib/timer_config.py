from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from EF_UVM.bus_env.bus_item import bus_item
from uvm.base.uvm_config_db import UVMConfigDb
from EF_UVM.bus_env.bus_seq_lib.bus_seq_base import bus_seq_base
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random


class timer_config(bus_seq_base):

    def __init__(self, name="timer_val"):
        super().__init__(name)

    async def body(self):
        # get register names/address conversion dict
        await super().body()

    async def read_timer_val(self):
        await self.send_req(is_write=False, reg="TMR")

    async def start_timer(self, pwm_enable=[0, 0], pwm_inverted=[0, 0]):
        value = (
            0b1
            | pwm_enable[0] << 2
            | pwm_enable[1] << 3
            | pwm_inverted[0] << 5
            | pwm_inverted[1] << 6
        )
        await self.send_req(
            is_write=True,
            reg="CTRL",
            data_condition=lambda data: data & 0b1111111 == 0b10,
        )
        await self.send_req(
            is_write=True,
            reg="CTRL",
            data_condition=lambda data: data & 0b1111111 == 0b00,
        )
        await self.send_req(
            is_write=True,
            reg="CTRL",
            data_condition=lambda data: data & 0b1111111 == value,
        )  # restart

    async def config_timer_regs(self, top_val=0xFF):
        three_rand = sorted(random.sample(range(1, top_val), 3))
        await self.send_req(
            is_write=True,
            reg="RELOAD",
            data_condition=lambda data: data == three_rand[2],
        )
        await self.send_req(
            is_write=True, reg="CMPX", data_condition=lambda data: data == three_rand[0]
        )
        await self.send_req(
            is_write=True, reg="CMPY", data_condition=lambda data: data == three_rand[1]
        )

    async def set_pwm_actions(self):
        await self.send_req(
            is_write=True,
            reg="PWM0CFG",
            data_condition=lambda data: data & 0b11 in [0b10, 0b01],
        )  # should start with high or low not realistic to start with no change or invert
        await self.send_req(
            is_write=True,
            reg="PWM1CFG",
            data_condition=lambda data: data & 0b11 in [0b10, 0b01],
        )

    async def set_timer_mode(self, is_periodic=None, dir=None):
        if is_periodic is None and dir is None:
            await self.send_req(
                is_write=True, reg="CFG", data_condition=lambda data: data & 0b11 != 0b0
            )
        elif is_periodic is None:
            await self.send_req(
                is_write=True, reg="CFG", data_condition=lambda data: data & 0b11 == dir
            )
        elif dir is None:
            await self.send_req(
                is_write=True,
                reg="CFG",
                data_condition=lambda data: data >> 2 == is_periodic,
            )
        else:
            await self.send_req(
                is_write=True,
                reg="CFG",
                data_condition=lambda data: data >> 2 == is_periodic
                and data & 0b11 == dir,
            )

    async def set_timer_pr(self, range=[0, 10]):
        await self.send_req(
            is_write=True,
            reg="PR",
            data_condition=lambda data: range[0] < data < range[1],
        )

    async def stop_timer(self):
        await self.send_req(
            is_write=True, reg="CTRL", data_condition=lambda data: data == 0b0
        )

    async def config_timer(self):
        await self.set_timer_pr()
        await self.set_timer_mode()
        await self.config_timer_regs()
        await self.start_timer()


uvm_object_utils(timer_config)
