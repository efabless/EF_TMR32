# EF_TMR32

 A 32-bit timer and PWM generator with the following features:
- 32-bit prescaler.
- Up Counting, Down Counting and Up/Down Counting.
- One-shot and Periodic.
- Two independent PWM channels with two compare registers.
- Optional PWM signal inversion.
- Configurable PWM dead time/band to generate PWM signals such as those required by a half-H bridge driver.
- Fault handeling.

## The wrapped IP


An APB wrapper, generated by the [IP_Utilities](https://github.com/shalan/IP_Utilities) `amba_wrap.py` utility, is provided. Other wrappers, AHB-Lite and WB, will be provided soon. All wrappers provide the same programmer's interface as outlined in the following sections.

### Wrapped IP System Integration

Based on your use case, use one of the provided wrappers or create a wrapper for your system bus type. For an example of how to integrate the APB wrapper:
```verilog
EF_TMR32_APB INST (
        `TB_APB_SLAVE_CONN,
        .pwm0(pwm0)
        .pwm1(pwm1)
        .pwm_fault(pwm_fault)
);
```
> **_NOTE:_** `TB_APB_SLAVE_CONN is a convenient macro provided by [IP_Utilities](https://github.com/shalan/IP_Utilities).

## Implementation example  

The following table is the result for implmenting the EF_TMR32 IP using Sky130 PDK and the [OpenLane2](https://github.com/efabless/openlane2) flow tool. You can find the configuration file used [here]()
|Module | Number of cells | Max. freq |
|---|---|---|
|EF_TMR32|911||
|EF_TMR32_APB|1571||
|EF_TMR32_AHBL|1607||
|EF_TMR32_WB|||
## The Programming Interface


### Registers

|Name|Offset|Reset Value|Access Mode|Description|
|---|---|---|---|---|
|TMR|0000|0x00000000|r|The current value of the Timer.|
|RELOAD|0004|0x00000000|w|The timer reload value. In up counting it is used as the terminal count. For down counting it is used as the initial count.|
|PR|0008|0x00000000|w|The Prescaler. The timer counting frequency is $Clock\ freq/(PR + 1)$|
|CMPX|000c|0x00000000|w|Compare Register X.|
|CMPY|0010|0x00000000|w|Compare Register Y.|
|CTRL|0014|0x00000000|w|Control Register.|
|CFG|0018|0x00000000|w|Configuration Register.|
|PWM0CFG|001c|0x00000000|w|PWM0 Configuration Register.|
|PWM1CFG|0020|0x00000000|w|PWM1 Configuration Register.|
|PWMDT|0024|0x00000000|w|PWM deadtime Register.|
|IM|0f00|0x00000000|w|Interrupt Mask Register; write 1/0 to enable/disable interrupts; check the interrupt flags table for more details|
|RIS|0f08|0x00000000|w|Raw Interrupt Status; reflects the current interrupts status;check the interrupt flags table for more details|
|MIS|0f04|0x00000000|w|Masked Interrupt Status; On a read, this register gives the current masked status value of the corresponding interrupt. A write has no effect; check the interrupt flags table for more details|
|IC|0f0c|0x00000000|w|Interrupt Clear Register; On a write of 1, the corresponding interrupt (both raw interrupt and masked interrupt, if enabled) is cleared; check the interrupt flags table for more details|

### TMR Register [Offset: 0x0, mode: r]

The current value of the Timer.
<img src="https://svg.wavedrom.com/{reg:[{name:'TMR', bits:32},{bits: 0}], config: {lanes: 2, hflip: true}} "/>


### RELOAD Register [Offset: 0x4, mode: w]

The timer reload value. In up counting it is used as the terminal count. For down counting it is used as the initial count.
<img src="https://svg.wavedrom.com/{reg:[{name:'RELOAD', bits:32},{bits: 0}], config: {lanes: 2, hflip: true}} "/>


### PR Register [Offset: 0x8, mode: w]

The Prescaler. The timer counting frequency is $Clock\ freq/(PR + 1)$
<img src="https://svg.wavedrom.com/{reg:[{name:'PR', bits:16},{bits: 16}], config: {lanes: 2, hflip: true}} "/>


### CMPX Register [Offset: 0xc, mode: w]

Compare Register X.
<img src="https://svg.wavedrom.com/{reg:[{name:'CMPX', bits:32},{bits: 0}], config: {lanes: 2, hflip: true}} "/>


### CMPY Register [Offset: 0x10, mode: w]

Compare Register Y.
<img src="https://svg.wavedrom.com/{reg:[{name:'CMPY', bits:32},{bits: 0}], config: {lanes: 2, hflip: true}} "/>


### CTRL Register [Offset: 0x14, mode: w]

Control Register.
<img src="https://svg.wavedrom.com/{reg:[{name:'TE', bits:1},{name:'TS', bits:1},{name:'P0E', bits:1},{name:'P1E', bits:1},{name:'DTE', bits:1},{name:'PI0', bits:1},{name:'PI1', bits:1},{bits: 25}], config: {lanes: 2, hflip: true}} "/>

|bit|field name|width|description|
|---|---|---|---|
|0|TE|1|Timer enable|
|1|TS|1|Timer re-start; used in the one-shot mode to restart the timer. Write 1 then 0 to re-start the timer.|
|2|P0E|1|PWM 0 enable|
|3|P1E|1|PWM 1 enable|
|4|DTE|1|PWM deadtime enable|
|5|PI0|1|Invert PWM0 output.|
|6|PI1|1|Invert PWM1 output.|


### CFG Register [Offset: 0x18, mode: w]

Configuration Register.
<img src="https://svg.wavedrom.com/{reg:[{name:'DIR', bits:2},{name:'P', bits:1},{bits: 29}], config: {lanes: 2, hflip: true}} "/>

|bit|field name|width|description|
|---|---|---|---|
|0|DIR|2|Count direction; 10: Up, 01: Down, 11: Up/Down|
|2|P|1|1: Peiodic, 0: One Shot|


### PWM0CFG Register [Offset: 0x1c, mode: w]

PWM0 Configuration Register.
<img src="https://svg.wavedrom.com/{reg:[{name:'E0', bits:2},{name:'E1', bits:2},{name:'E2', bits:2},{name:'E3', bits:2},{name:'E4', bits:2},{name:'E5', bits:2},{bits: 20}], config: {lanes: 2, hflip: true}} "/>

|bit|field name|width|description|
|---|---|---|---|
|0|E0|2|PWM0 action for matching zero. 00: No Action, 01: Low, 10: High, 11: Invert|
|2|E1|2|PWM0 action for matching CMPX (going up). 00: No Action, 01: Low, 10: High, 11: Invert|
|4|E2|2|PWM0 action for matching CMPY (going up). 00: No Action, 01: Low, 10: High, 11: Invert|
|6|E3|2|PWM0 action for matching RELOAD. 00: No Action, 01: Low, 10: High, 11: Invert|
|8|E4|2|PWM0 action for being matching CMPY (going down). 00: No Action, 01: Low, 10: High, 11: Invert|
|10|E5|2|PWM0 action for being matching CMPX (going down). 00: No Action, 01: Low, 10: High, 11: Invert|


### PWM1CFG Register [Offset: 0x20, mode: w]

PWM1 Configuration Register.
<img src="https://svg.wavedrom.com/{reg:[{name:'E0', bits:2},{name:'E1', bits:2},{name:'E2', bits:2},{name:'E3', bits:2},{name:'E4', bits:2},{name:'E5', bits:2},{bits: 20}], config: {lanes: 2, hflip: true}} "/>

|bit|field name|width|description|
|---|---|---|---|
|0|E0|2|PWM1 action for matching zero. 00: No Action, 01: Low, 10: High, 11: Invert|
|2|E1|2|PWM1 action for matching CMPX (going up). 00: No Action, 01: Low, 10: High, 11: Invert|
|4|E2|2|PWM1 action for matching CMPY (going up). 00: No Action, 01: Low, 10: High, 11: Invert|
|6|E3|2|PWM1 action for matching RELOAD. 00: No Action, 01: Low, 10: High, 11: Invert|
|8|E4|2|PWM1 action for being matching CMPY (going down). 00: No Action, 01: Low, 10: High, 11: Invert|
|10|E5|2|PWM1 action for being matching CMPX (going down). 00: No Action, 01: Low, 10: High, 11: Invert|


### PWMDT Register [Offset: 0x24, mode: w]

PWM deadtime Register.
<img src="https://svg.wavedrom.com/{reg:[{name:'PWMDT', bits:8},{bits: 24}], config: {lanes: 2, hflip: true}} "/>


### Interrupt Flags

The wrapped IP provides four registers to deal with interrupts: IM, RIS, MIS and IC. These registers exist for all wrapper types generated by the [IP_Utilities](https://github.com/shalan/IP_Utilities) `amba_wrap.py` utility. 

Each register has a group of bits for the interrupt sources/flags.
- `IM`: is used to enable/disable inetrrupt sources.

- `RIS`: has the current interrupt status (interruot flags) whether they are enabled or diabled.

- `MIS`: is the result of masking (ANDing) RIS by IM.

- `IC`: is used to clear an inetrrupt flag.


The following are the bit definitions for the interrupt registers:

|Bit|Flag|Width|Description|
|---|---|---|---|
|0|TO|1|Timeout; TMR matches 0 (down clounting) or RELOAD (up counting).|
|1|MX|1|TMR matches CMPX register.|
|2|MY|1|TMR matches CMPY register.|

### The Interface 


#### Module Parameters 

|Parameter|Description|Default Value|
|---|---|---|
|PRW|Number of bits for the prescaler register|16|

#### Ports 

|Port|Direction|Width|Description|
|---|---|---|---|
|pwm0|output|1|The generated PWM0 signal|
|pwm1|output|1|The generated PWM1 signal|
|pwm_fault|input|1|PWM fault input|
|tmr_en|input|1|Flag to enable timer|
|tmr_start|input|1|Flag to make tmr start in one shot mode|
|pwm0_en|input|1|Enable signal for PWM0 generation|
|pwm1_en|input|1|Enable signal for PWM1 generation|
|tmr_reload|input|32|The reload value which the counter will reach or start from|
|cmpx|input|32|The compare value X|
|cmpy|input|32|The compare value Y|
|prescaler|input|PRW|Prescaler value; Timer frequency = clock frequency / (prescaler + 1)|
|tmr_cfg|input|3|Timer configuration value; periodic or one shot and counting direction|
|pwm0_cfg|input|12|Actions configuration for pwm0|
|pwm1_cfg|input|12|Actions configuration for pwm1|
|pwm0_inv|input|1|Invert pwm0 signal|
|pwm1_inv|input|1|Invert pwm1 signal|
|pwm_dt|input|8|Deadtime for pwm|
|pwm_fault_clr|input|16|PWM fault input|
|pwm_dt_en|input|1|PWM deadtime enable|
|tmr|output|32|The actual value for the timer|
|matchx_flag|output|1|Flag raised when matching compare value x|
|matchy_flag|output|1|Flag raised when matching compare value x|
|timeout_flag|output|1|Flag raised when timeout happen|
## F/W Usage Guidelines:
## Installation:
You can either clone repo or use [IPM](https://github.com/efabless/IPM) which is an open-source IPs Package Manager
* To clone repo:
```git clone https://https://github.com/shalan/AUCOHL_TMR32.git```
* To download via IPM , follow installation guides [here](https://github.com/efabless/IPM/blob/main/README.md) then run 
```ipm install EF_TMR32```
## Simulation:
### Run Verilog Testbench:
1. Clone [IP_Utilities](https://github.com/shalan/IP_Utilities) repo in the same directory as the IP
2. In the directory ``EF_TMR32/verify/utb/`` run ``make APB-RTL`` to run testbench for APB or ``make AHBL-RTL`` to run textbench for AHBL
### Run cocotb UVM Testbench:
TBD
