from uvm.macros.uvm_message_defines import uvm_info
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW
from cocotb_coverage.coverage import CoverPoint, CoverCross
from uvm.macros import uvm_component_utils
from tmr32_item.tmr32_item import tmr32_pwm_item


class tmr32_cov_groups:
    def __init__(self, hierarchy, regs) -> None:
        self.hierarchy = hierarchy
        self.regs = regs
        self.actions = self.actions_combinations()
        self.ip_cov(None, do_sampling=False)

    def ip_cov(self, tr, do_sampling=True):
        @self.apply_decorators(decorators=self.actions)
        @CoverPoint(
            f"{self.hierarchy}.Prescaler",
            xf=lambda tr: (self.regs.read_reg_value("PR")),
            bins=[(i * 10, ((i + 1) * 10) - 1) for i in range(7)],
            bins_labels=[(i * 10, ((i + 1) * 10) - 1) for i in range(7)],
            # at_least=3,
            rel=lambda val, b: b[0] <= val <= b[1],
        )
        @CoverPoint(
            f"{self.hierarchy}.Compare Values.Relaod",
            xf=lambda tr: (self.regs.read_reg_value("RELOAD")),
            bins=[(i * 1000, ((i + 1) * 1000) - 1) for i in range(5)],
            bins_labels=[(i * 1000, ((i + 1) * 1000) - 1) for i in range(5)],
            # at_least=3,
            rel=lambda val, b: b[0] <= val <= b[1],
        )
        @CoverPoint(
            f"{self.hierarchy}.Compare Values.Compare Reg X",
            xf=lambda tr: (self.regs.read_reg_value("CMPX")),
            bins=[(i * 1000, ((i + 1) * 1000) - 1) for i in range(5)],
            bins_labels=[(i * 1000, ((i + 1) * 1000) - 1) for i in range(5)],
            # at_least=3,
            rel=lambda val, b: b[0] <= val <= b[1],
        )
        @CoverPoint(
            f"{self.hierarchy}.Compare Values.Compare Reg Y",
            xf=lambda tr: (self.regs.read_reg_value("CMPX")),
            bins=[(i * 1000, ((i + 1) * 1000) - 1) for i in range(5)],
            bins_labels=[(i * 1000, ((i + 1) * 1000) - 1) for i in range(5)],
            # at_least=3,
            rel=lambda val, b: b[0] <= val <= b[1],
        )
        @CoverPoint(
            f"{self.hierarchy}.PWM Deadtime Enable",
            xf=lambda tr: (self.regs.read_reg_value("CTRL") & 0b10000 == 0b10000),
            bins=[True, False],
            bins_labels=[
                "deadtime enabled" if i else "deadtime disabled" for i in [True, False]
            ],
            # at_least=3,
        )
        @CoverPoint(
            f"{self.hierarchy}.PWM0.Invert",
            xf=lambda tr: (self.regs.read_reg_value("CTRL") & 0b100000 == 0b100000),
            bins=[True, False],
            bins_labels=[
                "PWM0 output inverted" if i else "PWM0 output not inverted"
                for i in [True, False]
            ],
            # at_least=3,
        )
        @CoverPoint(
            f"{self.hierarchy}.PWM1.Invert",
            xf=lambda tr: (self.regs.read_reg_value("CTRL") & 0b1000000 == 0b1000000),
            bins=[True, False],
            bins_labels=[
                "PWM1 output inverted" if i else "PWM1 output not inverted"
                for i in [True, False]
            ],
            # at_least=3,
        )
        # @CoverPoint(
        #     f"{self.hierarchy}.PWM0.Patterns.Up Count",
        #     xf=lambda tr: ((self.regs.read_reg_value("CFG") & 0b11)==0b10 , self.regs.read_reg_value("PWM0CFG") , self.regs.read_reg_value("PWM0CFG")),
        #     bins=[ (True ,i, j) for i in range(4) for j in range(4) if j>i ],
        #     bins_labels=[( f"{i[1]}" , f"{j[1]}") for i in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] for j in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] if j[0]>i[0]],
        #     # at_least=3,
        #     rel=lambda val , b  : val[0]==b[0] and self.is_action_present(val[1], b[1], DownCount=False) is True and self.is_action_present(val[2], b[2], DownCount=False) is True
        # )
        # @CoverPoint(
        #     f"{self.hierarchy}.PWM0.Patterns.Down Count",
        #     xf=lambda tr: ((self.regs.read_reg_value("CFG") & 0b11)==0b01 , self.regs.read_reg_value("PWM0CFG") , self.regs.read_reg_value("PWM0CFG")),
        #     bins=[ (True ,i, j) for i in range(4) for j in range(4) if j>i ],
        #     bins_labels=[( f"{i[1]}" , f"{j[1]}") for i in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] for j in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] if j[0]>i[0]],
        #     # at_least=3,
        #     rel=lambda val , b  : val[0]==b[0] and self.is_action_present(val[1], b[1], DownCount=True) is True and self.is_action_present(val[2], b[2], DownCount=True) is True
        # )
        # @CoverPoint(
        #     f"{self.hierarchy}.PWM0.Patterns.Up Down Count",
        #     xf=lambda tr: ((self.regs.read_reg_value("CFG") & 0b11)==0b11 , self.regs.read_reg_value("PWM0CFG") , self.regs.read_reg_value("PWM0CFG")),
        #     bins=[ (True ,i, j) for i in range(4) for j in range(4) if j>i ],
        #     bins_labels=[( f"{i[1]}" , f"{j[1]}") for i in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] for j in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] if j[0]>i[0]],
        #     # at_least=3,
        #     rel=lambda val , b  : val[0]==b[0] and self.is_action_present(val[1], b[1], DownCount=False) is True and self.is_action_present(val[2], b[2], DownCount=False) is True
        # )
        # @CoverPoint(
        #     f"{self.hierarchy}.PWM1.Patterns.Up Count",
        #     xf=lambda tr: ((self.regs.read_reg_value("CFG") & 0b11)==0b10 , self.regs.read_reg_value("PWM1CFG") , self.regs.read_reg_value("PWM1CFG")),
        #     bins=[ (True ,i, j) for i in range(4) for j in range(4) if j>i ],
        #     bins_labels=[( f"{i[1]}" , f"{j[1]}") for i in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] for j in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] if j[0]>i[0]],
        #     # at_least=3,
        #     rel=lambda val , b  : val[0]==b[0] and self.is_action_present(val[1], b[1], DownCount=False) is True and self.is_action_present(val[2], b[2], DownCount=False) is True
        # )
        # @CoverPoint(
        #     f"{self.hierarchy}.PWM1.Patterns.Down Count",
        #     xf=lambda tr: ((self.regs.read_reg_value("CFG") & 0b11)==0b01 , self.regs.read_reg_value("PWM1CFG") , self.regs.read_reg_value("PWM1CFG")),
        #     bins=[ (True ,i, j) for i in range(4) for j in range(4) if j>i ],
        #     bins_labels=[( f"{i[1]}" , f"{j[1]}") for i in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] for j in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] if j[0]>i[0]],
        #     # at_least=3,
        #     rel=lambda val , b  : val[0]==b[0] and self.is_action_present(val[1], b[1], DownCount=True) is True and self.is_action_present(val[2], b[2], DownCount=True) is True
        # )
        # @CoverPoint(
        #     f"{self.hierarchy}.PWM1.Patterns.Up Down Count",
        #     xf=lambda tr: ((self.regs.read_reg_value("CFG") & 0b11)==0b11 , self.regs.read_reg_value("PWM1CFG") , self.regs.read_reg_value("PWM1CFG")),
        #     bins=[ (True ,i, j) for i in range(4) for j in range(4) if j>i ],
        #     bins_labels=[( f"{i[1]}" , f"{j[1]}") for i in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] for j in [(0,"No action"), (1,"Low"), (2,"High"), (3,"Invert")] if j[0]>i[0]],
        #     # at_least=3,
        #     rel=lambda val , b  : val[0]==b[0] and self.is_action_present(val[1], b[1], DownCount=False) is True and self.is_action_present(val[2], b[2], DownCount=False) is True
        # )

        def sample(tr):
            uvm_info("coverage_ip", f"tr = {tr}", UVM_LOW)

        if do_sampling:
            sample(tr)

    def actions_combinations(self):
        cov_points = []
        action_labels = {0: "No action", 1: "Low", 2: "High", 3: "Invert"}
        for action1 in range(4):
            for action2 in range(action1 + 1, 4):
                if action1 != action2:
                    action1_label = action_labels[action1]
                    action2_label = action_labels[action2]
                    print(action1, action2)
                    # PWM0
                    # Up Count
                    cov_points.append(
                        CoverPoint(
                            f"{self.hierarchy}.PWM0.Patterns.Up Count.{action1_label} , {action2_label}",
                            xf=lambda tr, action1=action1, action2=action2: (
                                (self.regs.read_reg_value("CFG") & 0b11) == 0b10,
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM0CFG"),
                                    action1,
                                    DownCount=False,
                                ),
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM0CFG"),
                                    action2,
                                    DownCount=False,
                                ),
                            ),
                            bins=[(True, True, True)],
                            bins_labels=[(f"{action1_label}", f"{action2_label}")],
                            # at_least=3,
                            rel=lambda val, b: val[0] == b[0]
                            and val[1] == b[1]
                            and val[2] == b[2],
                        )
                    )
                    # Down Count
                    cov_points.append(
                        CoverPoint(
                            f"{self.hierarchy}.PWM0.Patterns.Down Count.{action1_label} , {action2_label}",
                            xf=lambda tr, action1=action1, action2=action2: (
                                (self.regs.read_reg_value("CFG") & 0b11) == 0b01,
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM0CFG"),
                                    action1,
                                    DownCount=True,
                                ),
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM0CFG"),
                                    action2,
                                    DownCount=True,
                                ),
                            ),
                            bins=[(True, True, True)],
                            bins_labels=[(f"{action1_label}", f"{action2_label}")],
                            # at_least=3,
                            rel=lambda val, b: val[0] == b[0]
                            and val[1] == b[1]
                            and val[2] == b[2],
                        )
                    )
                    # Up Down Count
                    cov_points.append(
                        CoverPoint(
                            f"{self.hierarchy}.PWM0.Patterns.Up Down Count.{action1_label} , {action2_label}",
                            xf=lambda tr, action1=action1, action2=action2: (
                                (self.regs.read_reg_value("CFG") & 0b11) == 0b11,
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM0CFG"),
                                    action1,
                                    DownCount=False,
                                ),
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM0CFG"),
                                    action2,
                                    DownCount=False,
                                ),
                            ),
                            bins=[(True, True, True)],
                            bins_labels=[(f"{action1_label}", f"{action2_label}")],
                            # at_least=3,
                            rel=lambda val, b: val[0] == b[0]
                            and val[1] == b[1]
                            and val[2] == b[2],
                        )
                    )
                    # PWM1
                    # Up Count
                    cov_points.append(
                        CoverPoint(
                            f"{self.hierarchy}.PWM1.Patterns.Up Count.{action1_label} , {action2_label}",
                            xf=lambda tr, action1=action1, action2=action2: (
                                (self.regs.read_reg_value("CFG") & 0b11) == 0b10,
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM1CFG"),
                                    action1,
                                    DownCount=False,
                                ),
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM1CFG"),
                                    action2,
                                    DownCount=False,
                                ),
                            ),
                            bins=[(True, True, True)],
                            bins_labels=[(f"{action1_label}", f"{action2_label}")],
                            # at_least=3,
                            rel=lambda val, b: val[0] == b[0]
                            and val[1] == b[1]
                            and val[2] == b[2],
                        )
                    )
                    # Down Count
                    cov_points.append(
                        CoverPoint(
                            f"{self.hierarchy}.PWM1.Patterns.Down Count.{action1_label} , {action2_label}",
                            xf=lambda tr, action1=action1, action2=action2: (
                                (self.regs.read_reg_value("CFG") & 0b11) == 0b01,
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM1CFG"),
                                    action1,
                                    DownCount=True,
                                ),
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM1CFG"),
                                    action2,
                                    DownCount=True,
                                ),
                            ),
                            bins=[(True, True, True)],
                            bins_labels=[(f"{action1_label}", f"{action2_label}")],
                            # at_least=3,
                            rel=lambda val, b: val[0] == b[0]
                            and val[1] == b[1]
                            and val[2] == b[2],
                        )
                    )
                    # Up Down Count
                    cov_points.append(
                        CoverPoint(
                            f"{self.hierarchy}.PWM1.Patterns.Up Down Count.{action1_label} , {action2_label}",
                            xf=lambda tr, action1=action1, action2=action2: (
                                (self.regs.read_reg_value("CFG") & 0b11) == 0b11,
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM1CFG"),
                                    action1,
                                    DownCount=False,
                                ),
                                self.is_action_present(
                                    self.regs.read_reg_value("PWM1CFG"),
                                    action2,
                                    DownCount=False,
                                ),
                            ),
                            bins=[(True, True, True)],
                            bins_labels=[(f"{action1_label}", f"{action2_label}")],
                            # at_least=3,
                            rel=lambda val, b: val[0] == b[0]
                            and val[1] == b[1]
                            and val[2] == b[2],
                        )
                    )
        return cov_points

    def is_action_present(self, reg, action, DownCount):
        action_list = [((reg >> i) & 0b11) for i in range(0, 12, 2)]
        if DownCount:
            action_list[1] = -1
            action_list[2] = -1

        if action in action_list:
            return True
        else:
            return False

    def get_event_with_action(self, reg, action, DownCount):
        action_list = [((reg >> i) & 0b11) for i in range(0, 12, 2)]
        if DownCount:
            action_list[1] = -1
            action_list[2] = -1
        try:
            event = action_list.index(action)
        except ValueError:
            event = -1
        return event

    def apply_decorators(self, decorators):
        def decorator_wrapper(func):
            for decorator in decorators:
                func = decorator(func)
            return func

        return decorator_wrapper
