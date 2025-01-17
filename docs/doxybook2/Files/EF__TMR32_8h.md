---
title: EF_TMR32.h

---

# EF_TMR32.h



## Types

|                | Name           |
| -------------- | -------------- |
| enum| **[actions](Files/EF__TMR32_8h.md#enum-actions)** { NONE = 0b00, LOW = 0b01, HIGH = 0b10, INVERT = 0b11} |

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[EF_TMR32_enable](Files/EF__TMR32_8h.md#function-ef-tmr32-enable)**(uint32_t tmr32_base)<br>enables timer by setting "TE" bit in the CTRL register to 1  |
| void | **[EF_TMR32_restart](Files/EF__TMR32_8h.md#function-ef-tmr32-restart)**(uint32_t tmr32_base)<br>enables timer re-start; used in the one-shot mode to restart the timer.  |
| void | **[EF_TMR32_PWM0Enable](Files/EF__TMR32_8h.md#function-ef-tmr32-pwm0enable)**(uint32_t tmr32_base)<br>enables PWM0 by setting "P0E" bit in the CTRL register to 1  |
| void | **[EF_TMR32_PWM1Enable](Files/EF__TMR32_8h.md#function-ef-tmr32-pwm1enable)**(uint32_t tmr32_base)<br>enables PWM1 by setting "P1E" bit in the CTRL register to 1  |
| void | **[EF_TMR32_deadtimeEnable](Files/EF__TMR32_8h.md#function-ef-tmr32-deadtimeenable)**(uint32_t tmr32_base)<br>enables deadtime by setting "DTE" bit in the CTRL register to 1  |
| void | **[EF_TMR32_PWM0Invert](Files/EF__TMR32_8h.md#function-ef-tmr32-pwm0invert)**(uint32_t tmr32_base)<br>invert PWM0 by setting "P0I" bit in the CTRL register to 1  |
| void | **[EF_TMR32_PWM1Invert](Files/EF__TMR32_8h.md#function-ef-tmr32-pwm1invert)**(uint32_t tmr32_base)<br>invert PWM1 by setting "P1I" bit in the CTRL register to 1  |
| void | **[EF_TMR32_setUpCount](Files/EF__TMR32_8h.md#function-ef-tmr32-setupcount)**(uint32_t tmr32_base)<br>set the timer direction to be up counting  |
| void | **[EF_TMR32_setDownCount](Files/EF__TMR32_8h.md#function-ef-tmr32-setdowncount)**(uint32_t tmr32_base)<br>set the timer direction to be down counting  |
| void | **[EF_TMR32_setUpDownCount](Files/EF__TMR32_8h.md#function-ef-tmr32-setupdowncount)**(uint32_t tmr32_base)<br>set the timer direction to be up/down counting  |
| void | **[EF_TMR32_setPeriodic](Files/EF__TMR32_8h.md#function-ef-tmr32-setperiodic)**(uint32_t tmr32_base)<br>set the timer to be periodic  |
| void | **[EF_TMR32_setOneShot](Files/EF__TMR32_8h.md#function-ef-tmr32-setoneshot)**(uint32_t tmr32_base)<br>set the timer to be one shot  |
| void | **[EF_TMR32_setPWM0MatchingZeroAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm0matchingzeroaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches Zero value  |
| void | **[EF_TMR32_setPWM0MatchingCMPXAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm0matchingcmpxaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPX value while up counting  |
| void | **[EF_TMR32_setPWM0MatchingCMPYAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm0matchingcmpyaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPY value while up counting  |
| void | **[EF_TMR32_setPWM0MatchingRELOADAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm0matchingreloadaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches Reload value  |
| void | **[EF_TMR32_setPWM0MatchingCMPYDownCountAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm0matchingcmpydowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPX value while down counting  |
| void | **[EF_TMR32_setPWM0MatchingCMPXDownCountAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm0matchingcmpxdowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPY value while down counting  |
| void | **[EF_TMR32_setPWM1MatchingZeroAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm1matchingzeroaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches Zero value  |
| void | **[EF_TMR32_setPWM1MatchingCMPXAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm1matchingcmpxaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches CMPX value while up counting  |
| void | **[EF_TMR32_setPWM1MatchingRELOADAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm1matchingreloadaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches Reload value  |
| void | **[EF_TMR32_setPWM1MatchingCMPYDownCountAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm1matchingcmpydowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches CMPX value while down counting  |
| void | **[EF_TMR32_setPWM1MatchingCMPXDownCountAction](Files/EF__TMR32_8h.md#function-ef-tmr32-setpwm1matchingcmpxdowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches CMPY value while down counting  |
| void | **[EF_TMR32_setRELOAD](Files/EF__TMR32_8h.md#function-ef-tmr32-setreload)**(uint32_t tmr32_base, int value)<br>set the timer reload value  |
| int | **[EF_TMR32_getRELOAD](Files/EF__TMR32_8h.md#function-ef-tmr32-getreload)**(uint32_t tmr32_base)<br>get the timer reload value  |
| void | **[EF_TMR32_setCMPX](Files/EF__TMR32_8h.md#function-ef-tmr32-setcmpx)**(uint32_t tmr32_base, int value)<br>set the CMPX register value  |
| int | **[EF_TMR32_getCMPX](Files/EF__TMR32_8h.md#function-ef-tmr32-getcmpx)**(uint32_t tmr32_base)<br>get the CMPX register value  |
| void | **[EF_TMR32_setCMPY](Files/EF__TMR32_8h.md#function-ef-tmr32-setcmpy)**(uint32_t tmr32_base, int value)<br>set the CMPY register value  |
| int | **[EF_TMR32_getCMPY](Files/EF__TMR32_8h.md#function-ef-tmr32-getcmpy)**(uint32_t tmr32_base)<br>get the CMPY register value  |
| int | **[EF_TMR32_getTMR](Files/EF__TMR32_8h.md#function-ef-tmr32-gettmr)**(uint32_t tmr32_base)<br>get the current value of the timer  |
| void | **[EF_TMR32_setDeadtime](Files/EF__TMR32_8h.md#function-ef-tmr32-setdeadtime)**(uint32_t tmr32_base, int value)<br>set the timer deadtime register value  |

## Types Documentation

### enum actions

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| NONE | 0b00|   |
| LOW | 0b01|   |
| HIGH | 0b10|   |
| INVERT | 0b11|   |





## Functions Documentation

### function EF_TMR32_enable

```cpp
void EF_TMR32_enable(
    uint32_t tmr32_base
)
```

enables timer by setting "TE" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_restart

```cpp
void EF_TMR32_restart(
    uint32_t tmr32_base
)
```

enables timer re-start; used in the one-shot mode to restart the timer. 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM0Enable

```cpp
void EF_TMR32_PWM0Enable(
    uint32_t tmr32_base
)
```

enables PWM0 by setting "P0E" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM1Enable

```cpp
void EF_TMR32_PWM1Enable(
    uint32_t tmr32_base
)
```

enables PWM1 by setting "P1E" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_deadtimeEnable

```cpp
void EF_TMR32_deadtimeEnable(
    uint32_t tmr32_base
)
```

enables deadtime by setting "DTE" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM0Invert

```cpp
void EF_TMR32_PWM0Invert(
    uint32_t tmr32_base
)
```

invert PWM0 by setting "P0I" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM1Invert

```cpp
void EF_TMR32_PWM1Invert(
    uint32_t tmr32_base
)
```

invert PWM1 by setting "P1I" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setUpCount

```cpp
void EF_TMR32_setUpCount(
    uint32_t tmr32_base
)
```

set the timer direction to be up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setDownCount

```cpp
void EF_TMR32_setDownCount(
    uint32_t tmr32_base
)
```

set the timer direction to be down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setUpDownCount

```cpp
void EF_TMR32_setUpDownCount(
    uint32_t tmr32_base
)
```

set the timer direction to be up/down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setPeriodic

```cpp
void EF_TMR32_setPeriodic(
    uint32_t tmr32_base
)
```

set the timer to be periodic 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setOneShot

```cpp
void EF_TMR32_setOneShot(
    uint32_t tmr32_base
)
```

set the timer to be one shot 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setPWM0MatchingZeroAction

```cpp
void EF_TMR32_setPWM0MatchingZeroAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches Zero value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPXAction

```cpp
void EF_TMR32_setPWM0MatchingCMPXAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPX value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPYAction

```cpp
void EF_TMR32_setPWM0MatchingCMPYAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPY value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingRELOADAction

```cpp
void EF_TMR32_setPWM0MatchingRELOADAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches Reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPYDownCountAction

```cpp
void EF_TMR32_setPWM0MatchingCMPYDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPX value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPXDownCountAction

```cpp
void EF_TMR32_setPWM0MatchingCMPXDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPY value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingZeroAction

```cpp
void EF_TMR32_setPWM1MatchingZeroAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches Zero value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingCMPXAction

```cpp
void EF_TMR32_setPWM1MatchingCMPXAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches CMPX value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT
  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


set the action of PWM1 when the timer matches CMPY value while up counting


set the action of PWM1 when the timer matches CMPX value while up counting


### function EF_TMR32_setPWM1MatchingRELOADAction

```cpp
void EF_TMR32_setPWM1MatchingRELOADAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches Reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingCMPYDownCountAction

```cpp
void EF_TMR32_setPWM1MatchingCMPYDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches CMPX value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingCMPXDownCountAction

```cpp
void EF_TMR32_setPWM1MatchingCMPXDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches CMPY value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setRELOAD

```cpp
void EF_TMR32_setRELOAD(
    uint32_t tmr32_base,
    int value
)
```

set the timer reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** timer reload value 


### function EF_TMR32_getRELOAD

```cpp
int EF_TMR32_getRELOAD(
    uint32_t tmr32_base
)
```

get the timer reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: reload register value 

### function EF_TMR32_setCMPX

```cpp
void EF_TMR32_setCMPX(
    uint32_t tmr32_base,
    int value
)
```

set the CMPX register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** CMPX value 


### function EF_TMR32_getCMPX

```cpp
int EF_TMR32_getCMPX(
    uint32_t tmr32_base
)
```

get the CMPX register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: CMPX register value 

### function EF_TMR32_setCMPY

```cpp
void EF_TMR32_setCMPY(
    uint32_t tmr32_base,
    int value
)
```

set the CMPY register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** CMPY value 


### function EF_TMR32_getCMPY

```cpp
int EF_TMR32_getCMPY(
    uint32_t tmr32_base
)
```

get the CMPY register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: CMPY register value 

### function EF_TMR32_getTMR

```cpp
int EF_TMR32_getTMR(
    uint32_t tmr32_base
)
```

get the current value of the timer 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: current timer value 

### function EF_TMR32_setDeadtime

```cpp
void EF_TMR32_setDeadtime(
    uint32_t tmr32_base,
    int value
)
```

set the timer deadtime register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** deadtime register value 




## Source code

```cpp
#ifndef EF_TMR32_H
#define EF_TMR32_H

#include <EF_TMR32_regs.h>
#include <stdint.h>
#include <stdbool.h>

enum actions {NONE = 0b00, LOW = 0b01, HIGH = 0b10, INVERT = 0b11};


void EF_TMR32_enable(uint32_t tmr32_base);


void EF_TMR32_restart(uint32_t tmr32_base);


void EF_TMR32_PWM0Enable(uint32_t tmr32_base);


void EF_TMR32_PWM1Enable(uint32_t tmr32_base);


void EF_TMR32_deadtimeEnable(uint32_t tmr32_base);


void EF_TMR32_PWM0Invert(uint32_t tmr32_base);


void EF_TMR32_PWM1Invert(uint32_t tmr32_base);


void EF_TMR32_setUpCount(uint32_t tmr32_base);


void EF_TMR32_setDownCount(uint32_t tmr32_base);


void EF_TMR32_setUpDownCount(uint32_t tmr32_base);


void EF_TMR32_setPeriodic(uint32_t tmr32_base);


void EF_TMR32_setOneShot(uint32_t tmr32_base);


void EF_TMR32_setPWM0MatchingZeroAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM0MatchingCMPXAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM0MatchingCMPYAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM0MatchingRELOADAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM0MatchingCMPYDownCountAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM0MatchingCMPXDownCountAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM1MatchingZeroAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM1MatchingCMPXAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM1MatchingCMPXAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM1MatchingRELOADAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM1MatchingCMPYDownCountAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setPWM1MatchingCMPXDownCountAction(uint32_t tmr32_base, enum actions action);


void EF_TMR32_setRELOAD (uint32_t tmr32_base, int value);


int EF_TMR32_getRELOAD (uint32_t tmr32_base);


void EF_TMR32_setCMPX (uint32_t tmr32_base, int value);


int EF_TMR32_getCMPX (uint32_t tmr32_base);


void EF_TMR32_setCMPY (uint32_t tmr32_base, int value);


int EF_TMR32_getCMPY (uint32_t tmr32_base);


int EF_TMR32_getTMR (uint32_t tmr32_base);


void EF_TMR32_setDeadtime (uint32_t tmr32_base, int value);

#endif
```


-------------------------------

Updated on 2024-04-07 at 13:02:30 +0200
