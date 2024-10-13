from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from EF_UVM.bus_env.bus_item import bus_item
from uvm.base.uvm_config_db import UVMConfigDb
from EF_UVM.bus_env.bus_seq_lib.bus_seq_base import bus_seq_base
from cocotb.triggers import Timer, Combine
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random
import cocotb

class timer_config(bus_seq_base):

    def __init__(self, name="timer_val"):
        super().__init__(name)

    async def body(self):
        # get register names/address conversion dict
        await super().body()
        await self.send_req(is_write=True, reg="CLKGATE", data_condition=lambda data: data == 1)

    async def wait_pwm0_deteced(self):
        self.tr_start0_event.set()
        await self.tr_received0_event.wait()
        self.tr_received0_event.clear()

    async def wait_pwm1_deteced(self):
        self.tr_start1_event.set()
        await self.tr_received1_event.wait()
        self.tr_received1_event.clear()

    async def wait_pwm_deteced(self):
        pwm0 = await cocotb.start(self.wait_pwm0_deteced())
        pwm1 = await cocotb.start(self.wait_pwm1_deteced())
        await Combine(pwm0, pwm1)

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
            data_condition=lambda data: data & 0xFFF  in [self.generate_pwm_action()],
        )  # should start with high or low not realistic to start with no change or invert
        await self.send_req(
            is_write=True,
            reg="PWM1CFG",
            data_condition=lambda data: data & 0xFFF  in [self.generate_pwm_action()],
        )
    
    def generate_pwm_action(self):
        E0 = random.randint(1, 0b11)  # should start with high or low not realistic to start with no change or invert
        E1 = random.randint(0, 0b100)
        E2 = random.randint(0, 0b100)
        E3 = random.randint(0, 0b100)  # better to not be not action
        E4 = random.randint(0, 0b100)
        E5 = random.randint(0, 0b100)
        
        seq_vals = [1, 2, 3]
        counter = 0
        for i in [E0, E1, E2, E3]:
            if i in seq_vals:
                counter += 1
                seq_vals.remove(i)
        if counter < 2:
            return self.generate_pwm_action()
        seq_vals = [1, 2, 3]
        counter = 0
        for i in [E3, E4, E5]:
            if i in seq_vals:
                counter += 1
                seq_vals.remove(i)
        if counter < 2:
            return self.generate_pwm_action()
        return int(E0 | E1 << 2 | E2 << 4 | E3 << 6 | E4 << 8 | E5 << 10)
            
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
                data_condition=lambda data: data >> 2 == is_periodic and data & 0b11 != 0b0,
            )
        else:
            await self.send_req(
                is_write=True,
                reg="CFG",
                data_condition=lambda data: data >> 2 == is_periodic and data & 0b11 != 0b0
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
        await self.send_req(is_write=True, reg="CLKGATE", data_condition=lambda data: data == 1)
        await self.set_timer_pr()
        await self.set_timer_mode()
        await self.config_timer_regs()
        await self.start_timer()


uvm_object_utils(timer_config)
