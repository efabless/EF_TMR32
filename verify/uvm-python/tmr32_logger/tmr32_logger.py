from EF_UVM.ip_env.ip_logger.ip_logger import ip_logger
import cocotb
from uvm.macros import uvm_component_utils
from tmr32_item.tmr32_item import tmr32_pwm_item


class tmr32_logger(ip_logger):
    def __init__(self, name="tmr32_logger", parent=None):
        super().__init__(name, parent)
        self.header = ["Time (ns)", "Source", "Pattern"]
        self.col_widths = [10] * len(self.header)

    def logger_formatter(self, transaction):
        sim_time = f"{cocotb.utils.get_sim_time(units='ns')} ns"
        if type(transaction) is tmr32_pwm_item:
            source = f"{transaction.source}"
            pattern = f"{transaction.pattern}"
            return [sim_time, source, pattern]
        else:
            timeout = str(transaction.timeout)
            return [sim_time, "Timer timeout", timeout]


uvm_component_utils(tmr32_logger)
