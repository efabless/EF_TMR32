from uvm.base.uvm_component import UVMComponent
from uvm.macros import uvm_component_utils
from uvm.tlm1.uvm_analysis_port import UVMAnalysisImp
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.macros.uvm_tlm_defines import uvm_analysis_imp_decl
from EF_UVM.ip_env.ip_coverage.ip_coverage import ip_coverage
from EF_UVM.bus_env.bus_coverage.bus_coverage import bus_coverage
from EF_UVM.bus_env.bus_item import bus_item
from cocotb_coverage.coverage import CoverPoint, CoverCross


class tmr32_bus_coverage(bus_coverage):
    """
    component that initialize the coverage groups and control when to sample the data.
    """

    def __init__(self, name="tmr32_bus_coverage", parent=None):
        super().__init__(name, parent)

    def build_phase(self, phase):
        super().build_phase(phase)
        self.timer_cov_groups = tmr32_TimerSample("top.tmr32", self.regs)

    def write_bus(self, tr):
        super().write_bus(tr)
        if tr.kind == bus_item.READ and tr.addr == 0x00:  # read from tmr val
            self.timer_cov_groups.sample_timer(tr)


uvm_component_utils(tmr32_bus_coverage)


class tmr32_TimerSample:
    def __init__(self, hierarchy, regs) -> None:
        self.hierarchy = hierarchy
        self.regs = regs
        self.sample_timer(None, do_sampling=False)

    def sample_timer(self, tr, do_sampling=True):
        @CoverPoint(
            f"{self.hierarchy}.timer.read values",
            xf=lambda tr: tr.data,
            bins=[(0, 0x3F), (0x40, 0xFF)],
            bins_labels=["read low val", "read high val"],
            rel=lambda val, b: b[0] <= val <= b[1],
        )
        @CoverPoint(
            f"{self.hierarchy}.timer.temp.prescaler",
            xf=lambda tr: self.regs.read_reg_value("PR"),
            bins=[(1, 0x6), (0x7, 0xFFFFFF)],
            bins_labels=["high speed counting", "low speed counting"],
            rel=lambda val, b: b[0] <= val <= b[1],
        )
        @CoverPoint(
            f"{self.hierarchy}.timer.temp.direction",
            xf=lambda tr: self.regs.read_reg_value("CFG") & 0b11,
            bins=[0b10, 0b01, 0b11],
            bins_labels=["up counting", "down counting", "updown counting"],
        )
        @CoverPoint(
            f"{self.hierarchy}.timer.temp.mode",
            xf=lambda tr: self.regs.read_reg_value("CFG") >> 2,
            bins=[0b0, 0b1],
            bins_labels=["one shot", "periodic"],
        )
        @CoverCross(
            f"{self.hierarchy}.timer.read timer values",
            items=[
                f"{self.hierarchy}.timer.temp.mode",
                f"{self.hierarchy}.timer.temp.direction",
                f"{self.hierarchy}.timer.temp.prescaler",
                f"{self.hierarchy}.timer.read values",
            ],
        )
        def sample(tr):
            uvm_info(
                "coverage",
                f"timer_val: {tr.data} prescaler: {self.regs.read_reg_value('PR')} config {self.regs.read_reg_value('CFG')}",
                UVM_LOW,
            )
            pass

        if do_sampling:
            sample(tr)
