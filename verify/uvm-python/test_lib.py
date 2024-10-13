import cocotb
from uvm.comps import UVMTest
from uvm import UVMCoreService
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.base.uvm_printer import UVMTablePrinter
from uvm.base.sv import sv
from uvm.base.uvm_object_globals import UVM_FULL, UVM_LOW, UVM_ERROR
from uvm.base.uvm_globals import run_test
from EF_UVM.top_env import top_env
from tmr32_interface.tmr32_if import tmr32_if
from EF_UVM.bus_env.bus_interface.bus_if import (
    bus_ahb_if,
    bus_apb_if,
    bus_wb_if,
    bus_irq_if,
)
from cocotb_coverage.coverage import coverage_db
from cocotb.triggers import Event, First
from EF_UVM.bus_env.bus_regs import bus_regs
from uvm.base.uvm_report_server import UVMReportServer
from uvm.base import UVMRoot

# seq
from EF_UVM.bus_env.bus_seq_lib.write_read_regs import write_read_regs
from tmr32_seq_lib.pwm_actions_seq import pwm_actions_seq
from tmr32_seq_lib.pwm_pr_seq import pwm_pr_seq
from tmr32_seq_lib.pwm_tmr_seq import pwm_tmr_seq
from tmr32_seq_lib.timer_vary import timer_vary
from tmr32_seq_lib.temp import temp

# override classes
from EF_UVM.ip_env.ip_agent.ip_driver import ip_driver
from tmr32_agent.tmr32_driver import tmr32_driver
from EF_UVM.ip_env.ip_agent.ip_monitor import ip_monitor
from tmr32_agent.tmr32_monitor import tmr32_monitor
from EF_UVM.ref_model.ref_model import ref_model
from ref_model.ref_model import tmr32_VIP
from EF_UVM.ip_env.ip_coverage.ip_coverage import ip_coverage
from tmr32_coverage.tmr32_coverage import tmr32_coverage
from EF_UVM.ip_env.ip_logger.ip_logger import ip_logger
from tmr32_logger.tmr32_logger import tmr32_logger
from EF_UVM.scoreboard import scoreboard
from tmr32_coverage.tmr32_bus_coverage import tmr32_bus_coverage
from EF_UVM.bus_env.bus_coverage.bus_coverage import bus_coverage

#
from EF_UVM.bus_env.bus_agent.bus_ahb_driver import bus_ahb_driver
from EF_UVM.bus_env.bus_agent.bus_apb_driver import bus_apb_driver
from EF_UVM.bus_env.bus_agent.bus_wb_driver import bus_wb_driver
from EF_UVM.bus_env.bus_agent.bus_ahb_monitor import bus_ahb_monitor
from EF_UVM.bus_env.bus_agent.bus_apb_monitor import bus_apb_monitor
from EF_UVM.bus_env.bus_agent.bus_wb_monitor import bus_wb_monitor

from EF_UVM.base_test import base_test


@cocotb.test()
async def module_top(dut):
    # profiler = cProfile.Profile()
    # profiler.enable()

    pif = tmr32_if(dut)
    BUS_TYPE = cocotb.plusargs["BUS_TYPE"]
    if BUS_TYPE == "APB":
        w_if = bus_apb_if(dut)
    elif BUS_TYPE == "AHB":
        w_if = bus_ahb_if(dut)
    elif BUS_TYPE == "WISHBONE":
        w_if = bus_wb_if(dut)
    else:
        uvm_fatal("module_top", f"unknown bus type {BUS_TYPE}")
    w_irq_if = bus_irq_if(dut)
    UVMConfigDb.set(None, "*", "ip_if", pif)
    UVMConfigDb.set(None, "*", "bus_if", w_if)
    UVMConfigDb.set(None, "*", "bus_irq_if", w_irq_if)
    yaml_file = []
    UVMRoot().clp.get_arg_values("+YAML_FILE=", yaml_file)
    yaml_file = yaml_file[0]
    regs = bus_regs(yaml_file)
    UVMConfigDb.set(None, "*", "bus_regs", regs)
    UVMConfigDb.set(None, "*", "irq_exist", regs.get_irq_exist())
    UVMConfigDb.set(None, "*", "insert_glitches", False)
    UVMConfigDb.set(None, "*", "collect_coverage", True)
    UVMConfigDb.set(None, "*", "disable_logger", False)
    test_path = []
    UVMRoot().clp.get_arg_values("+TEST_PATH=", test_path)
    test_path = test_path[0]
    await run_test()
    coverage_db.export_to_yaml(filename=f"{test_path}/coverage.yalm")
    # profiler.disable()
    # profiler.dump_stats("profile_result.prof")


class tmr_base_test(base_test):
    def __init__(self, name="flash_first_test", parent=None):
        BUS_TYPE = cocotb.plusargs["BUS_TYPE"]
        super().__init__(name, bus_type=BUS_TYPE, parent=parent)
        self.tag = name

    def build_phase(self, phase):
        super().build_phase(phase)
        # override
        self.set_type_override_by_type(ip_driver.get_type(), tmr32_driver.get_type())
        self.set_type_override_by_type(ip_monitor.get_type(), tmr32_monitor.get_type())
        self.set_type_override_by_type(ref_model.get_type(), tmr32_VIP.get_type())
        self.set_type_override_by_type(
            ip_coverage.get_type(), tmr32_coverage.get_type()
        )
        self.set_type_override_by_type(ip_logger.get_type(), tmr32_logger.get_type())
        self.set_type_override_by_type(
            bus_coverage.get_type(), tmr32_bus_coverage.get_type()
        )


uvm_component_utils(tmr_base_test)


class pwm_actions_test(tmr_base_test):
    def __init__(self, name="pwm_test", parent=None):
        super().__init__(name, parent)
        self.tag = name

    def end_of_elaboration_phase(self, phase):
        super().end_of_elaboration_phase(phase)
        self.update_min_checkers(22)

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = pwm_actions_seq("pwm_actions_seq")
        bus_seq.tr_received0_event = self.top_env.ip_env.ip_agent.monitor.tr_received0_event
        bus_seq.tr_start0_event = self.top_env.ip_env.ip_agent.monitor.tr_start0_event
        bus_seq.tr_received1_event = self.top_env.ip_env.ip_agent.monitor.tr_received1_event
        bus_seq.tr_start1_event = self.top_env.ip_env.ip_agent.monitor.tr_start1_event
        await bus_seq.start(self.bus_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(pwm_actions_test)


class pwm_pr_test(tmr_base_test):
    def __init__(self, name="pwm_test", parent=None):
        super().__init__(name, parent)
        self.tag = name

    def end_of_elaboration_phase(self, phase):
        super().end_of_elaboration_phase(phase)
        self.update_min_checkers(6)

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = pwm_pr_seq("pwm_pr_seq")
        bus_seq.tr_received0_event = self.top_env.ip_env.ip_agent.monitor.tr_received0_event
        bus_seq.tr_start0_event = self.top_env.ip_env.ip_agent.monitor.tr_start0_event
        bus_seq.tr_received1_event = self.top_env.ip_env.ip_agent.monitor.tr_received1_event
        bus_seq.tr_start1_event = self.top_env.ip_env.ip_agent.monitor.tr_start1_event
        await bus_seq.start(self.bus_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(pwm_pr_test)


class pwm_tmr_test(tmr_base_test):
    def __init__(self, name="pwm_tmr_test", parent=None):
        super().__init__(name, parent)
        self.tag = name

    def end_of_elaboration_phase(self, phase):
        super().end_of_elaboration_phase(phase)
        self.update_min_checkers(6)

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = pwm_tmr_seq("pwm_tmr_seq")
        bus_seq.tr_received0_event = self.top_env.ip_env.ip_agent.monitor.tr_received0_event
        bus_seq.tr_start0_event = self.top_env.ip_env.ip_agent.monitor.tr_start0_event
        bus_seq.tr_received1_event = self.top_env.ip_env.ip_agent.monitor.tr_received1_event
        bus_seq.tr_start1_event = self.top_env.ip_env.ip_agent.monitor.tr_start1_event
        await bus_seq.start(self.bus_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(pwm_tmr_test)


class time_vary_test(tmr_base_test):
    def __init__(self, name="tmr32_Try", parent=None):
        super().__init__(name, parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = timer_vary("timer_vary")
        await bus_seq.start(self.bus_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(time_vary_test)


class temp_test(tmr_base_test):
    def __init__(self, name="tmr32_Try", parent=None):
        super().__init__(name, parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = temp("timer_vary")
        await bus_seq.start(self.bus_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(temp_test)
