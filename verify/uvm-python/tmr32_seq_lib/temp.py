from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from EF_UVM.bus_env.bus_item import bus_item
from uvm.base.uvm_config_db import UVMConfigDb
from EF_UVM.bus_env.bus_seq_lib.bus_seq_base import bus_seq_base
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random


class temp(bus_seq_base):

    def __init__(self, name="timer_val"):
        super().__init__(name)

    async def body(self):
        # get register names/address conversion dict
        await super().body()
        three_rand = sorted(random.sample(range(1, 0xFF), 3))
        # enable control
        # await self.send_req(is_write=True, reg="PR", data_condition=lambda data: 0 < data < 4)
        await self.send_req(
            is_write=True, reg="PR", data_condition=lambda data: data == 4
        )
        await self.send_req(
            is_write=True, reg="RELOAD", data_condition=lambda data: data == 0x50
        )
        await self.send_req(
            is_write=True, reg="CFG", data_condition=lambda data: data == 0b010
        )  # has to be periodic
        # await self.send_req(is_write=True, reg="PWM0CFG", data_condition=lambda data: data & 0b11 in [0b10, 0b01]) # should start with high or low not realistic to start with no change or invert
        # await self.send_req(is_write=True, reg="PWM1CFG", data_condition=lambda data: data & 0b11 in [0b10, 0b01])
        # await self.send_req(is_write=True, reg="CMPX", data_condition=lambda data: data == three_rand[0])
        # await self.send_req(is_write=True, reg="CMPY", data_condition=lambda data: data == three_rand[1])
        await self.send_req(
            is_write=True,
            reg="CTRL",
            data_condition=lambda data: data & 0b11111 == 0b1110,
        )
        await self.send_req(
            is_write=True,
            reg="CTRL",
            data_condition=lambda data: data & 0b11111 == 0b1100,
        )
        await self.send_req(
            is_write=True,
            reg="CTRL",
            data_condition=lambda data: data & 0b11111 == 0b1101,
        )  # restart
        for i in range(1000):
            await self.send_req(is_write=False, reg="TMR")
        # await Timer(11500, "ns")
        # await self.send_req(is_write=True, reg="GENA")
        # await Timer(515500, "ns")


uvm_object_utils(temp)
