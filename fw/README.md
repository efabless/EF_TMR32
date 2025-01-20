# API Reference

## Header files

- [EF_Driver_Common.h](#file-ef_driver_commonh)
- [EF_TMR32.h](#file-ef_tmr32h)
- [EF_TMR32_example.h](#file-ef_tmr32_exampleh)
- [EF_TMR32_regs.h](#file-ef_tmr32_regsh)

## File EF_Driver_Common.h

_C header file for common driver definitions and types._



## Structures and Types

| Type | Name |
| ---: | :--- |
| typedef uint32\_t | [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status)  <br>_A type that is used to return the status of the driver functions._ |


## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_DRIVER\_ERROR**](#define-ef_driver_error)  ((uint32\_t)1)<br>_Unspecified error._ |
| define  | [**EF\_DRIVER\_ERROR\_BUSY**](#define-ef_driver_error_busy)  ((uint32\_t)2)<br>_Driver is busy._ |
| define  | [**EF\_DRIVER\_ERROR\_PARAMETER**](#define-ef_driver_error_parameter)  ((uint32\_t)5)<br>_Parameter error._ |
| define  | [**EF\_DRIVER\_ERROR\_SPECIFIC**](#define-ef_driver_error_specific)  ((uint32\_t)6)<br>_Start of driver specific errors._ |
| define  | [**EF\_DRIVER\_ERROR\_TIMEOUT**](#define-ef_driver_error_timeout)  ((uint32\_t)3)<br>_Timeout occurred._ |
| define  | [**EF\_DRIVER\_ERROR\_UNSUPPORTED**](#define-ef_driver_error_unsupported)  ((uint32\_t)4)<br>_Operation not supported._ |
| define  | [**EF\_DRIVER\_OK**](#define-ef_driver_ok)  ((uint32\_t)0)<br>_Operation succeeded._ |

## Structures and Types Documentation

### typedef `EF_DRIVER_STATUS`

_A type that is used to return the status of the driver functions._
```c
typedef uint32_t EF_DRIVER_STATUS;
```



## Macros Documentation

### define `EF_DRIVER_ERROR`

_Unspecified error._
```c
#define EF_DRIVER_ERROR ((uint32_t)1)
```

### define `EF_DRIVER_ERROR_BUSY`

_Driver is busy._
```c
#define EF_DRIVER_ERROR_BUSY ((uint32_t)2)
```

### define `EF_DRIVER_ERROR_PARAMETER`

_Parameter error._
```c
#define EF_DRIVER_ERROR_PARAMETER ((uint32_t)5)
```

### define `EF_DRIVER_ERROR_SPECIFIC`

_Start of driver specific errors._
```c
#define EF_DRIVER_ERROR_SPECIFIC ((uint32_t)6)
```

### define `EF_DRIVER_ERROR_TIMEOUT`

_Timeout occurred._
```c
#define EF_DRIVER_ERROR_TIMEOUT ((uint32_t)3)
```

### define `EF_DRIVER_ERROR_UNSUPPORTED`

_Operation not supported._
```c
#define EF_DRIVER_ERROR_UNSUPPORTED ((uint32_t)4)
```

### define `EF_DRIVER_OK`

_Operation succeeded._
```c
#define EF_DRIVER_OK ((uint32_t)0)
```


## File EF_TMR32.h

_C header file for TMR32 APIs which contains the function prototypes._




## Functions

| Type | Name |
| ---: | :--- |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_PWM0Enable**](#function-ef_tmr32_pwm0enable) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Enables PWM0 by setting "P0E" bit in the CTRL register to 1._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_PWM0Invert**](#function-ef_tmr32_pwm0invert) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Inverts PWM0 output by setting "P0I" bit in the CTRL register to 1._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_PWM1Enable**](#function-ef_tmr32_pwm1enable) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Enables PWM1 by setting "P1E" bit in the CTRL register to 1._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_PWM1Invert**](#function-ef_tmr32_pwm1invert) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Inverts PWM1 output by setting "P1I" bit in the CTRL register to 1._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_PWMDeadtimeEnable**](#function-ef_tmr32_pwmdeadtimeenable) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_clearCMPXMatchFlag**](#function-ef_tmr32_clearcmpxmatchflag) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Clears the CMPX match flag by writing to the ICR register and setting the MX bit._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_clearCMPYMatchFlag**](#function-ef_tmr32_clearcmpymatchflag) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Clears the CMPY match flag by writing to the ICR register and setting the MY bit._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_clearTimoutFlag**](#function-ef_tmr32_cleartimoutflag) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Clears the timeout flag by writing to the ICR register and setting the TO bit._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_disable**](#function-ef_tmr32_disable) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Disables timer by setting "TE" bit in the CTRL register to 0._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_enable**](#function-ef_tmr32_enable) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Enables timer by setting "TE" bit in the CTRL register to 1._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_getIM**](#function-ef_tmr32_getim) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t \*IM\_value) <br>_Retrieves the interrupt clear register by reading the ICR register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_getMIS**](#function-ef_tmr32_getmis) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t \*MIS\_value) <br>_Retrieves the masked interrupt status by reading the MIS register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_getRIS**](#function-ef_tmr32_getris) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t \*RIS\_value) <br>_Retrieves the raw interrupt status by reading the RIS register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_getTMR**](#function-ef_tmr32_gettmr) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t \*tmr\_value) <br>_Retrieves the current timer value by reading the TMR register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_isCMPXMatch**](#function-ef_tmr32_iscmpxmatch) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t \*match\_status) <br>_Checks if the timer has reached the CMPX value by reading the RIS register and checking the MX flag._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_isCMPYMatch**](#function-ef_tmr32_iscmpymatch) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t \*match\_status) <br>_Checks if the timer has reached the CMPY value by reading the RIS register and checking the MY flag._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_isTimout**](#function-ef_tmr32_istimout) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t \*timeout\_status) <br>_Checks if the timer has reached the RELOAD value if up counting or zero if down counting by reading the RIS register and checking the RT flag._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_restart**](#function-ef_tmr32_restart) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Enables timer re-start; used in the one-shot mode to restart the timer by setting the "TS" bit in the CTRL register to 1 and then to 0._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setCMPX**](#function-ef_tmr32_setcmpx) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t value) <br>_Sets the compare value of a 32-bit timer by writing to the CMPX register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setCMPY**](#function-ef_tmr32_setcmpy) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t value) <br>_Sets the compare value Y of a 32-bit timer by writing to the CMPY register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setDownCount**](#function-ef_tmr32_setdowncount) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Sets the timer direction to be down counting by setting the "DIR" field in the CTRL register to 0b01._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setGclkEnable**](#function-ef_tmr32_setgclkenable) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t value) <br>_Sets the GCLK enable bit in the UART register to a certain value._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setICR**](#function-ef_tmr32_seticr) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t mask) <br>_Sets the interrupt clear register of the timer by writing to the ICR register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setIM**](#function-ef_tmr32_setim) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t mask) <br>_Sets the interrupt mask of the timer by writing to the IM register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setOneShot**](#function-ef_tmr32_setoneshot) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Sets the timer to operate in one-shot mode by clearing the "P" bit in the CFG register to 0._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPR**](#function-ef_tmr32_setpr) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t value) <br>_Sets the prescaler value of the timer by writing to the PR register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0CenterAlignedMode**](#function-ef_tmr32_setpwm0centeralignedmode) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t reload\_value, uint32\_t cmpX\_value) <br>_Sets the PWM0 center-aligned mode._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0EdgeAlignmentMode**](#function-ef_tmr32_setpwm0edgealignmentmode) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t reload\_value, uint32\_t duty\_cycle) <br>_Sets the PWM0 edge alignment mode._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0MatchingCMPXDownCountAction**](#function-ef_tmr32_setpwm0matchingcmpxdowncountaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0MatchingCMPXUpCountAction**](#function-ef_tmr32_setpwm0matchingcmpxupcountaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0MatchingCMPYDownCountAction**](#function-ef_tmr32_setpwm0matchingcmpydowncountaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0MatchingCMPYUpCountAction**](#function-ef_tmr32_setpwm0matchingcmpyupcountaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0MatchingRELOADAction**](#function-ef_tmr32_setpwm0matchingreloadaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM0MatchingZeroAction**](#function-ef_tmr32_setpwm0matchingzeroaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1CenterAlignedMode**](#function-ef_tmr32_setpwm1centeralignedmode) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t reload\_value, uint32\_t cmpY\_value) <br>_Sets the PWM1 center-aligned mode._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1EdgeAlignmentMode**](#function-ef_tmr32_setpwm1edgealignmentmode) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t reload\_value, uint32\_t duty\_cycle) <br>_Sets the PWM1 edge alignment mode._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1MatchingCMPXDownCountAction**](#function-ef_tmr32_setpwm1matchingcmpxdowncountaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1MatchingCMPXUpCountingAction**](#function-ef_tmr32_setpwm1matchingcmpxupcountingaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1MatchingCMPYDownCountAction**](#function-ef_tmr32_setpwm1matchingcmpydowncountaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1MatchingCMPYUpCountingAction**](#function-ef_tmr32_setpwm1matchingcmpyupcountingaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1MatchingRELOADAction**](#function-ef_tmr32_setpwm1matchingreloadaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWM1MatchingZeroAction**](#function-ef_tmr32_setpwm1matchingzeroaction) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t action) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPWMDeadtime**](#function-ef_tmr32_setpwmdeadtime) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t value) <br>_Sets the PWM dead time value of the PWM by writing to the PWMDT register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setPeriodic**](#function-ef_tmr32_setperiodic) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Sets the timer to operate in periodic mode by setting the "P" bit in the CFG register to 1._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setRELOAD**](#function-ef_tmr32_setreload) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32, uint32\_t value) <br>_Sets the reload value of a 32-bit timer by writing to the RELOAD register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setUpCount**](#function-ef_tmr32_setupcount) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Sets the timer direction to be up counting by setting the "DIR" field in the CTRL register to 0b10._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_setUpDownCount**](#function-ef_tmr32_setupdowncount) ([**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) tmr32) <br>_Sets the timer direction to be up/down counting by setting the "DIR" field in the CTRL register to 0b11._ |

## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_TMR32\_ACTION\_HIGH**](#define-ef_tmr32_action_high)  ((uint32\_t)2)<br>_Set output to HIGH when match occurs._ |
| define  | [**EF\_TMR32\_ACTION\_INVERT**](#define-ef_tmr32_action_invert)  ((uint32\_t)3)<br>_Invert the output when match occurs._ |
| define  | [**EF\_TMR32\_ACTION\_LOW**](#define-ef_tmr32_action_low)  ((uint32\_t)1)<br>_Set output to LOW when match occurs._ |
| define  | [**EF\_TMR32\_ACTION\_MAX\_VALUE**](#define-ef_tmr32_action_max_value)  ((uint32\_t)3)<br>_Maximum value for the action field._ |
| define  | [**EF\_TMR32\_ACTION\_NONE**](#define-ef_tmr32_action_none)  ((uint32\_t)0)<br>_No action on match (do nothing)_ |
| define  | [**EF\_TMR32\_ICR\_MAX\_VALUE**](#define-ef_tmr32_icr_max_value)  ((uint32\_t)2)<br>_Maximum value for the ICR register._ |
| define  | [**EF\_TMR32\_IM\_MAX\_VALUE**](#define-ef_tmr32_im_max_value)  ((uint32\_t)2)<br>_Maximum value for the IM register._ |
| define  | [**EF\_TMR32\_PR\_MAX\_VALUE**](#define-ef_tmr32_pr_max_value)  ((uint32\_t)0x0000FFFF)<br>_Maximum value for the PR register._ |
| define  | [**EF\_TMR32\_PWMDT\_MAX\_VALUE**](#define-ef_tmr32_pwmdt_max_value)  ((uint32\_t)0x000000FF)<br>_Maximum value for the deadtime register._ |


## Functions Documentation

### function `EF_TMR32_PWM0Enable`

_Enables PWM0 by setting "P0E" bit in the CTRL register to 1._
```c
EF_DRIVER_STATUS EF_TMR32_PWM0Enable (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_PWM0Invert`

_Inverts PWM0 output by setting "P0I" bit in the CTRL register to 1._
```c
EF_DRIVER_STATUS EF_TMR32_PWM0Invert (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_PWM1Enable`

_Enables PWM1 by setting "P1E" bit in the CTRL register to 1._
```c
EF_DRIVER_STATUS EF_TMR32_PWM1Enable (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_PWM1Invert`

_Inverts PWM1 output by setting "P1I" bit in the CTRL register to 1._
```c
EF_DRIVER_STATUS EF_TMR32_PWM1Invert (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_PWMDeadtimeEnable`

```c
EF_DRIVER_STATUS EF_TMR32_PWMDeadtimeEnable (
    EF_TMR32_TYPE_PTR tmr32
) 
```


Enables PWM dead-time by setting the "DTE" (Dead-Time Enable) bit in the CTRL register to 1. Dead-time is a critical feature in PWM signal generation used to ensure a safe period between switching the high and low states, preventing short circuits or other issues in systems with complementary outputs, such as H-bridge drivers. When enabled, the "DTE" bit introduces a fixed delay between the switching of PWM channels to allow for this safety margin.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_clearCMPXMatchFlag`

_Clears the CMPX match flag by writing to the ICR register and setting the MX bit._
```c
EF_DRIVER_STATUS EF_TMR32_clearCMPXMatchFlag (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_clearCMPYMatchFlag`

_Clears the CMPY match flag by writing to the ICR register and setting the MY bit._
```c
EF_DRIVER_STATUS EF_TMR32_clearCMPYMatchFlag (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_clearTimoutFlag`

_Clears the timeout flag by writing to the ICR register and setting the TO bit._
```c
EF_DRIVER_STATUS EF_TMR32_clearTimoutFlag (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_disable`

_Disables timer by setting "TE" bit in the CTRL register to 0._
```c
EF_DRIVER_STATUS EF_TMR32_disable (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_enable`

_Enables timer by setting "TE" bit in the CTRL register to 1._
```c
EF_DRIVER_STATUS EF_TMR32_enable (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_getIM`

_Retrieves the interrupt clear register by reading the ICR register._
```c
EF_DRIVER_STATUS EF_TMR32_getIM (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t *IM_value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `IM_value` A pointer to a uint32\_t where the interrupt clear value will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_getMIS`

_Retrieves the masked interrupt status by reading the MIS register._
```c
EF_DRIVER_STATUS EF_TMR32_getMIS (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t *MIS_value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `MIS_value` A pointer to a uint32\_t where the masked interrupt status value will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_getRIS`

_Retrieves the raw interrupt status by reading the RIS register._
```c
EF_DRIVER_STATUS EF_TMR32_getRIS (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t *RIS_value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `RIS_value` A pointer to a uint32\_t where the raw interrupt status value will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_getTMR`

_Retrieves the current timer value by reading the TMR register._
```c
EF_DRIVER_STATUS EF_TMR32_getTMR (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t *tmr_value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `tmr_value` A pointer to a uint32\_t where the timer value will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_isCMPXMatch`

_Checks if the timer has reached the CMPX value by reading the RIS register and checking the MX flag._
```c
EF_DRIVER_STATUS EF_TMR32_isCMPXMatch (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t *match_status
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `match_status` A pointer to a uint32\_t where the match status will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_isCMPYMatch`

_Checks if the timer has reached the CMPY value by reading the RIS register and checking the MY flag._
```c
EF_DRIVER_STATUS EF_TMR32_isCMPYMatch (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t *match_status
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `match_status` A pointer to a uint32\_t where the match status will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_isTimout`

_Checks if the timer has reached the RELOAD value if up counting or zero if down counting by reading the RIS register and checking the RT flag._
```c
EF_DRIVER_STATUS EF_TMR32_isTimout (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t *timeout_status
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `timeout_status` A pointer to a uint32\_t where the timeout status will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_restart`

_Enables timer re-start; used in the one-shot mode to restart the timer by setting the "TS" bit in the CTRL register to 1 and then to 0._
```c
EF_DRIVER_STATUS EF_TMR32_restart (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setCMPX`

_Sets the compare value of a 32-bit timer by writing to the CMPX register._
```c
EF_DRIVER_STATUS EF_TMR32_setCMPX (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `value` The compare value to set in the CMPX register.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_setCMPY`

_Sets the compare value Y of a 32-bit timer by writing to the CMPY register._
```c
EF_DRIVER_STATUS EF_TMR32_setCMPY (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `value` The compare value to set in the CMPY register.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_setDownCount`

_Sets the timer direction to be down counting by setting the "DIR" field in the CTRL register to 0b01._
```c
EF_DRIVER_STATUS EF_TMR32_setDownCount (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setGclkEnable`

_Sets the GCLK enable bit in the UART register to a certain value._
```c
EF_DRIVER_STATUS EF_TMR32_setGclkEnable (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `value` The value of the GCLK enable bit


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setICR`

_Sets the interrupt clear register of the timer by writing to the ICR register._
```c
EF_DRIVER_STATUS EF_TMR32_setICR (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t mask
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `mask` The interrupt clear mask value to set in the ICR register. Must not exceed [**EF\_TMR32\_ICR\_MAX\_VALUE**](#define-ef_tmr32_icr_max_value).


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_setIM`

_Sets the interrupt mask of the timer by writing to the IM register._
```c
EF_DRIVER_STATUS EF_TMR32_setIM (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t mask
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `mask` The interrupt mask value to set in the IM register. Must not exceed [**EF\_TMR32\_IM\_MAX\_VALUE**](#define-ef_tmr32_im_max_value).


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_setOneShot`

_Sets the timer to operate in one-shot mode by clearing the "P" bit in the CFG register to 0._
```c
EF_DRIVER_STATUS EF_TMR32_setOneShot (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPR`

_Sets the prescaler value of the timer by writing to the PR register._
```c
EF_DRIVER_STATUS EF_TMR32_setPR (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `value` The prescaler value to set in the PR register. Must not exceed [**EF\_TMR32\_PR\_MAX\_VALUE**](#define-ef_tmr32_pr_max_value).


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_setPWM0CenterAlignedMode`

_Sets the PWM0 center-aligned mode._
```c
EF_DRIVER_STATUS EF_TMR32_setPWM0CenterAlignedMode (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t reload_value,
    uint32_t cmpX_value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `reload_value` The reload value to set in the PWM0CFG register. This determines the period of the PWM signal. 
* `cmpX_value` The value to set in the CMPX register. This value controls the point at which the PWM signal transitions from high to low (or vice versa) in the center-aligned mode.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.

* EF\_DRIVER\_OK: Configuration was successful.
* EF\_DRIVER\_ERROR\_PARAMETER: Invalid input parameters, such as `tmr32` being NULL.



This function configures the specified 32-bit timer (`tmr32`) to generate a PWM signal with center-alignment on PWM0. It sets the timer to up-down counting mode and periodic mode, configures the zero and compare actions, and sets the reload and compare values as specified.

Internal configurations performed by the function:

* Sets the timer to up-down counting mode.
* Configures the timer for periodic operation.
* Sets the zero action to drive the PWM output high.
* Configures the X compare register to drive the PWM output low on up-count.
* Configures the X compare register to drive the PWM output high on down-count.
* Configures the Y compare register to maintain the current output state on both up and down counts.
* Sets the reload value to define the PWM signal period.
* Sets the X compare register value to define the transition point.

Example PWM waveform: 
````cpp
|       /|\
|_____/__|__\
|   / |  |  | \
|_/___|__|__|___\__
      |     |
      V     V
  ____       ____
      |_____|    
````





**Note:**

Ensure the timer instance (`tmr32`) is correctly initialized before calling this function. The reload value and compare value must align with the timer's capabilities and clock settings.



**Note:**

for more information, check [https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/](https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/)
### function `EF_TMR32_setPWM0EdgeAlignmentMode`

_Sets the PWM0 edge alignment mode._
```c
EF_DRIVER_STATUS EF_TMR32_setPWM0EdgeAlignmentMode (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t reload_value,
    uint32_t duty_cycle
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `reload_value` The reload value to set in the PWM0CFG register. This determines the period of the PWM signal. 
* `duty_cycle` The duty cycle value to set in the PWM0CFG register, representing the high time as a percentage of the period (0 to 100).


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.

* EF\_DRIVER\_OK: Configuration was successful.
* EF\_DRIVER\_ERROR\_PARAMETER: Invalid input parameters, such as `tmr32` being NULL or`duty_cycle` &gt; 100.



This function configures the specified 32-bit timer (`tmr32`) to generate a PWM signal with edge alignment. It sets the timer to up-count and periodic modes, configures the zero action to high, and uses the X compare register to control the output signal. The duty cycle and reload values are used to compute the compare register value.

Internal configurations performed by the function:

* Sets the timer to up-count mode.
* Configures the timer for periodic operation.
* Sets the zero action to drive the PWM output high.
* Configures the X compare register to drive the PWM output low on up-count.
* Configures the Y compare register to maintain the current output state.
* Calculates the X compare value based on the duty cycle and reload value.
* Sets the reload value and compare register.
* Ensures no change in output on the top action.

Example PWM waveform: 
````cpp
|       /|      /|
|_____/__|____/  |
|   / |  |  / |  |
|_/___|__|/___|__|____
      |       |
      V       V
  ____    ____    ___   ___
      |__|    |__|   |__|
  duty    duty
  cycle   cycle
````





**Note:**

Ensure the timer instance (`tmr32`) is correctly initialized before calling this function. The reload value and compare value must align with the timer's capabilities and clock settings.



**Note:**

for more information, check [https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/](https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/)
### function `EF_TMR32_setPWM0MatchingCMPXDownCountAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXDownCountAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR0 PWM when the timer matches the CMPX value while down counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting down. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM0 configuration register by modifying EF\_TMR32\_PWM0CFG\_REG\_E5\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPX value while counting down. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM0MatchingCMPXUpCountAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXUpCountAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR0 PWM when the timer matches the CMPX value while up counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting up. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM0 configuration register by modifying EF\_TMR32\_PWM0CFG\_REG\_E1\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPX value while counting up. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM0MatchingCMPYDownCountAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYDownCountAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR0 PWM when the timer matches the CMPY value while down counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting down. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM0 configuration register by modifying EF\_TMR32\_PWM0CFG\_REG\_E4\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPY value while counting down. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM0MatchingCMPYUpCountAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYUpCountAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR0 PWM when the timer matches the CMPY value while up counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting up. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM0 configuration register by modifying EF\_TMR32\_PWM0CFG\_REG\_E2\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPY value while counting up. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM0MatchingRELOADAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingRELOADAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR0 PWM when the timer matches the RELOAD value. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the RELOAD value. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM0 configuration register by modifying EF\_TMR32\_PWM0CFG\_REG\_E3\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the RELOAD value. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM0MatchingZeroAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingZeroAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR0 PWM when the timer matches the Zero value. This function allows the user to specify what happens to the PWM output signal when the timer counter reaches zero. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM0 configuration register by modifying [**EF\_TMR32\_PWM0CFG\_REG\_E0\_BIT**](#define-ef_tmr32_pwm0cfg_reg_e0_bit). This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the Zero value. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM1CenterAlignedMode`

_Sets the PWM1 center-aligned mode._
```c
EF_DRIVER_STATUS EF_TMR32_setPWM1CenterAlignedMode (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t reload_value,
    uint32_t cmpY_value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `reload_value` The reload value to set in the PWM1CFG register. This determines the period of the PWM signal. 
* `cmpY_value` The value to set in the CMPX register. This value controls the point at which the PWM signal transitions from high to low (or vice versa) in the center-aligned mode.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.

* EF\_DRIVER\_OK: Configuration was successful.
* EF\_DRIVER\_ERROR\_PARAMETER: Invalid input parameters, such as `tmr32` being NULL.



This function configures the specified 32-bit timer (`tmr32`) to generate a PWM signal with center-alignment on PWM1. It sets the timer to up-down counting mode and periodic mode, configures the zero and compare actions, and sets the reload and compare values as specified.

Internal configurations performed by the function:

* Sets the timer to up-down counting mode.
* Configures the timer for periodic operation.
* Sets the zero action to drive the PWM output high.
* Configures the Y compare register to drive the PWM output low on up-count.
* Configures the Y compare register to drive the PWM output high on down-count.
* Configures the X compare register to maintain the current output state on both up and down counts.
* Sets the reload value to define the PWM signal period.
* Sets the X compare register value to define the transition point.

Example PWM waveform: 
````cpp
|       /|\
|_____/__|__\
|   / |  |  | \
|_/___|__|__|___\__
      |     |
      V     V
  ____       ____ 
      |_____|    
````





**Note:**

Ensure the timer instance (`tmr32`) is correctly initialized before calling this function. The reload value and compare value must align with the timer's capabilities and clock settings.



**Note:**

for more information, check [https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/](https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/)
### function `EF_TMR32_setPWM1EdgeAlignmentMode`

_Sets the PWM1 edge alignment mode._
```c
EF_DRIVER_STATUS EF_TMR32_setPWM1EdgeAlignmentMode (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t reload_value,
    uint32_t duty_cycle
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `reload_value` The reload value to set in the PWM1CFG register. This determines the period of the PWM signal. 
* `duty_cycle` The duty cycle value to set in the PWM1CFG register, representing the high time as a percentage of the period (0 to 100).


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.

* EF\_DRIVER\_OK: Configuration was successful.
* EF\_DRIVER\_ERROR\_PARAMETER: Invalid input parameters, such as `tmr32` being NULL or`duty_cycle` &gt; 100.



This function configures the specified 32-bit timer (`tmr32`) to generate a PWM signal with edge alignment on PWM1. It sets the timer to up-count and periodic modes, configures the zero action to high, and uses the Y compare register to control the output signal. The duty cycle and reload values are used to compute the compare register value.

Internal configurations performed by the function:

* Sets the timer to up-count mode.
* Configures the timer for periodic operation.
* Sets the zero action to drive the PWM output high.
* Configures the Y compare register to drive the PWM output low on up-count.
* Configures the X compare register to maintain the current output state.
* Calculates the Y compare value based on the duty cycle and reload value.
* Sets the reload value and compare register.
* Ensures no change in output on the top action.

Example PWM waveform: 
````cpp
|       /|      /|
|_____/__|____/  |
|   / |  |  / |  |
|_/___|__|/___|__|____
      |       |
      V       V
  ____    ____    ___   ___
      |__|    |__|   |__|
  duty    duty
  cycle   cycle
````





**Note:**

Ensure the timer instance (`tmr32`) is correctly initialized before calling this function. The reload value and compare value must align with the timer's capabilities and clock settings.



**Note:**

for more information, check [https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/](https://www.linkedin.com/pulse/center-aligned-pwm-vs-edge-aligned-neobionics-tn/)
### function `EF_TMR32_setPWM1MatchingCMPXDownCountAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXDownCountAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR1 PWM when the timer matches the CMPX value while down counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting down. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM1 configuration register by modifying EF\_TMR32\_PWM1CFG\_REG\_E5\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPX value while counting down. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM1MatchingCMPXUpCountingAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXUpCountingAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR1 PWM when the timer matches the CMPX value while up counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting up. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM1 configuration register by modifying EF\_TMR32\_PWM1CFG\_REG\_E1\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPX value while counting up. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM1MatchingCMPYDownCountAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYDownCountAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR1 PWM when the timer matches the CMPY value while down counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting down. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM1 configuration register by modifying EF\_TMR32\_PWM1CFG\_REG\_E4\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPY value while counting down. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM1MatchingCMPYUpCountingAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYUpCountingAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR1 PWM when the timer matches the CMPY value while up counting. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting up. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM1 configuration register by modifying EF\_TMR32\_PWM1CFG\_REG\_E2\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the CMPY value while counting up. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM1MatchingRELOADAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingRELOADAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR1 PWM when the timer matches the RELOAD value. This function allows the user to specify what happens to the PWM output signal when the timer counter matches the RELOAD value. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM1 configuration register by modifying EF\_TMR32\_PWM1CFG\_REG\_E3\_BI. This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the RELOAD value. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWM1MatchingZeroAction`

```c
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingZeroAction (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t action
) 
```


Configures the action of TMR1 PWM when the timer matches the Zero value. This function allows the user to specify what happens to the PWM output signal when the timer counter reaches zero. The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output. The action is configured in the PWM1 configuration register by modifying [**EF\_TMR32\_PWM1CFG\_REG\_E0\_BIT**](#define-ef_tmr32_pwm1cfg_reg_e0_bit). This is commonly used in PWM applications to define the output response when the counter reaches a particular value.



**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `action` A uint32\_t value specifying the action to take when the timer matches the Zero value. The possible values are:

  * EF\_TMR32\_ACTION\_NONE: No action (do nothing)
  * EF\_TMR32\_ACTION\_LOW: Set the PWM output to LOW
  * EF\_TMR32\_ACTION\_HIGH: Set the PWM output to HIGH
  * EF\_TMR32\_ACTION\_INVERT: Invert the current output state


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setPWMDeadtime`

_Sets the PWM dead time value of the PWM by writing to the PWMDT register._
```c
EF_DRIVER_STATUS EF_TMR32_setPWMDeadtime (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `value` The dead time value to set in the PWMDT register. Must not exceed [**EF\_TMR32\_PWMDT\_MAX\_VALUE**](#define-ef_tmr32_pwmdt_max_value).


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_setPeriodic`

_Sets the timer to operate in periodic mode by setting the "P" bit in the CFG register to 1._
```c
EF_DRIVER_STATUS EF_TMR32_setPeriodic (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setRELOAD`

_Sets the reload value of a 32-bit timer by writing to the RELOAD register._
```c
EF_DRIVER_STATUS EF_TMR32_setRELOAD (
    EF_TMR32_TYPE_PTR tmr32,
    uint32_t value
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr), which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.
* `value` The reload value to set in the RELOAD register.


**Returns:**

status A value of type EF\_DRIVER\_STATUS: returns a success or error code.
### function `EF_TMR32_setUpCount`

_Sets the timer direction to be up counting by setting the "DIR" field in the CTRL register to 0b10._
```c
EF_DRIVER_STATUS EF_TMR32_setUpCount (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_TMR32_setUpDownCount`

_Sets the timer direction to be up/down counting by setting the "DIR" field in the CTRL register to 0b11._
```c
EF_DRIVER_STATUS EF_TMR32_setUpDownCount (
    EF_TMR32_TYPE_PTR tmr32
) 
```


**Parameters:**


* `tmr32` An [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr) , which points to the base memory address of TMR32 registers.[**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) is a structure that contains the TMR32 registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code

## Macros Documentation

### define `EF_TMR32_ACTION_HIGH`

_Set output to HIGH when match occurs._
```c
#define EF_TMR32_ACTION_HIGH ((uint32_t)2)
```

### define `EF_TMR32_ACTION_INVERT`

_Invert the output when match occurs._
```c
#define EF_TMR32_ACTION_INVERT ((uint32_t)3)
```

### define `EF_TMR32_ACTION_LOW`

_Set output to LOW when match occurs._
```c
#define EF_TMR32_ACTION_LOW ((uint32_t)1)
```

### define `EF_TMR32_ACTION_MAX_VALUE`

_Maximum value for the action field._
```c
#define EF_TMR32_ACTION_MAX_VALUE ((uint32_t)3)
```

### define `EF_TMR32_ACTION_NONE`

_No action on match (do nothing)_
```c
#define EF_TMR32_ACTION_NONE ((uint32_t)0)
```

### define `EF_TMR32_ICR_MAX_VALUE`

_Maximum value for the ICR register._
```c
#define EF_TMR32_ICR_MAX_VALUE ((uint32_t)2)
```

### define `EF_TMR32_IM_MAX_VALUE`

_Maximum value for the IM register._
```c
#define EF_TMR32_IM_MAX_VALUE ((uint32_t)2)
```

### define `EF_TMR32_PR_MAX_VALUE`

_Maximum value for the PR register._
```c
#define EF_TMR32_PR_MAX_VALUE ((uint32_t)0x0000FFFF)
```

### define `EF_TMR32_PWMDT_MAX_VALUE`

_Maximum value for the deadtime register._
```c
#define EF_TMR32_PWMDT_MAX_VALUE ((uint32_t)0x000000FF)
```


## File EF_TMR32_example.h

_C header file containing an example of how to use the TMR32 APIs._




## Functions

| Type | Name |
| ---: | :--- |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_PWM\_Example**](#function-ef_tmr32_pwm_example) (void) <br>_Example of PWM Usage Example usage:_ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_TMR32\_normalExample**](#function-ef_tmr32_normalexample) (void) <br>_Example of Normal Usage Example usage:_ |



## Functions Documentation

### function `EF_TMR32_PWM_Example`

_Example of PWM Usage Example usage:_
```c
EF_DRIVER_STATUS EF_TMR32_PWM_Example (
    void
) 
```


````cpp
    #include "EF_TMR32.h"

    #define Example_TMR32_BASE_ADDRESS 0x40000000
    #define TMR320 ((EF_TMR32_TYPE_PTR)Example_TMR32_BASE_ADDRESS)

    EF_DRIVER_STATUS EF_TMR32_PWM_Example(void) {
    EF_DRIVER_STATUS status;

    uint32_t reload_value = 10000; // Timer reload value
    uint32_t duty_cycle = 70;       // Duty cycle for PWM0
    uint32_t cmpY_value = 500;      // Compare value for PWM1


    // Step 1: Enable GCLK
    status = EF_TMR32_setGclkEnable(TMR320, 1);
    if (status != EF_DRIVER_OK) {return status;}

    // Step 2: Enable the timer
    status = EF_TMR32_enable(TMR320);

    // Step 3: Enable PWM0
    status = EF_TMR32_PWM0Enable(TMR320);
    if (status != EF_DRIVER_OK) {return status;}

    // Step 4: Set PWM0 to Edge-Aligned Mode
    // Set PWM0 to edge-aligned mode with 70% duty cycle
    status = EF_TMR32_setPWM0EdgeAlignmentMode(TMR320, reload_value, duty_cycle);
    if (status != EF_DRIVER_OK) {return status;}


    // Step 5: Enable PWM1
    status = EF_TMR32_PWM1Enable(TMR320);

    // Step 6: Set PWM1 to Center-Aligned Mode
    // Set PWM1 to center-aligned mode with a specific CMPY value
    status = EF_TMR32_setPWM1CenterAlignedMode(TMR320, reload_value, cmpY_value);


    // Step 7: Disable the timer
    status = EF_TMR32_disable(TMR320);

    return EF_DRIVER_OK;
}
````
### function `EF_TMR32_normalExample`

_Example of Normal Usage Example usage:_
```c
EF_DRIVER_STATUS EF_TMR32_normalExample (
    void
) 
```


````cpp
#include "EF_TMR32.h"

#define Example_TMR32_BASE_ADDRESS 0x40000000
#define TMR320 ((EF_TMR32_TYPE_PTR)Example_TMR32_BASE_ADDRESS)

EF_DRIVER_STATUS EF_TMR32_normalExample(void){
    // Now let's configure the timer to operate in one-shot mode

    EF_DRIVER_STATUS status;

    uint32_t reload_value = 10000; // Timer reload value
    uint32_t cmpY_value = 500;      // Compare value for PWM1


    // Step 1: Enable GCLK
    status = EF_TMR32_setGclkEnable(TMR320, 1);
    if (status != EF_DRIVER_OK) {return status;}

    // Step 2: Enable the timer
    status = EF_TMR32_enable(TMR320);

    // Step 3: Set mode to up-count
    status = EF_TMR32_setUpCount(TMR320);

    // Step 4: Set mode to periodic
    status = EF_TMR32_setPeriodic(TMR320);

    // Step 5: Set the reload value
    status = EF_TMR32_setRELOAD(TMR320, reload_value);

    // Step 6: Set the compare value
    status = EF_TMR32_setCMPY(TMR320, cmpY_value);

    // Step 7: Set the timer to one-shot mode  
    status = EF_TMR32_setOneShot(TMR320);

    // Step 8: Restart the timer
    status = EF_TMR32_restart(TMR320);

    // Step 9: wait for the timer to finish counting
    for (int i = 0; i < 100000; i++) {}

    // Step 10: Check the time flag to ensure the timer has finished counting
    uint32_t flag;
    status = EF_TMR32_isCMPYMatch(TMR320, &flag);

    if (flag == 1) {
        // clear the flag
        status = EF_TMR32_clearCMPYMatch(TMR320);
    }

    // Step 11: Restart the timer
    status = EF_TMR32_restart(TMR320);

    // Step 12: Read the timer value
    uint32_t tmr_value;
    status = EF_TMR32_getTMR(TMR320, &tmr_value);

    // Step 13: Disable the timer
    status = EF_TMR32_disable(TMR320);

}
````


## File EF_TMR32_regs.h





## Structures and Types

| Type | Name |
| ---: | :--- |
| typedef struct [**\_EF\_TMR32\_TYPE\_**](#struct-_ef_tmr32_type_) | [**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type)  <br> |
| typedef [**EF\_TMR32\_TYPE**](#typedef-ef_tmr32_type) \* | [**EF\_TMR32\_TYPE\_PTR**](#typedef-ef_tmr32_type_ptr)  <br> |
| struct | [**\_EF\_TMR32\_TYPE\_**](#struct-_ef_tmr32_type_) <br> |


## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_TMR32\_CFG\_REG\_DIR\_BIT**](#define-ef_tmr32_cfg_reg_dir_bit)  (uint32\_t)(0)<br> |
| define  | [**EF\_TMR32\_CFG\_REG\_DIR\_MASK**](#define-ef_tmr32_cfg_reg_dir_mask)  (uint32\_t)(0x3)<br> |
| define  | [**EF\_TMR32\_CFG\_REG\_P\_BIT**](#define-ef_tmr32_cfg_reg_p_bit)  (uint32\_t)(2)<br> |
| define  | [**EF\_TMR32\_CFG\_REG\_P\_MASK**](#define-ef_tmr32_cfg_reg_p_mask)  (uint32\_t)(0x4)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_DTE\_BIT**](#define-ef_tmr32_ctrl_reg_dte_bit)  (uint32\_t)(4)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_DTE\_MASK**](#define-ef_tmr32_ctrl_reg_dte_mask)  (uint32\_t)(0x10)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_P0E\_BIT**](#define-ef_tmr32_ctrl_reg_p0e_bit)  (uint32\_t)(2)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_P0E\_MASK**](#define-ef_tmr32_ctrl_reg_p0e_mask)  (uint32\_t)(0x4)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_P1E\_BIT**](#define-ef_tmr32_ctrl_reg_p1e_bit)  (uint32\_t)(3)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_P1E\_MASK**](#define-ef_tmr32_ctrl_reg_p1e_mask)  (uint32\_t)(0x8)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_PI0\_BIT**](#define-ef_tmr32_ctrl_reg_pi0_bit)  (uint32\_t)(5)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_PI0\_MASK**](#define-ef_tmr32_ctrl_reg_pi0_mask)  (uint32\_t)(0x20)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_PI1\_BIT**](#define-ef_tmr32_ctrl_reg_pi1_bit)  (uint32\_t)(6)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_PI1\_MASK**](#define-ef_tmr32_ctrl_reg_pi1_mask)  (uint32\_t)(0x40)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_TE\_BIT**](#define-ef_tmr32_ctrl_reg_te_bit)  (uint32\_t)(0)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_TE\_MASK**](#define-ef_tmr32_ctrl_reg_te_mask)  (uint32\_t)(0x1)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_TS\_BIT**](#define-ef_tmr32_ctrl_reg_ts_bit)  (uint32\_t)(1)<br> |
| define  | [**EF\_TMR32\_CTRL\_REG\_TS\_MASK**](#define-ef_tmr32_ctrl_reg_ts_mask)  (uint32\_t)(0x2)<br> |
| define  | [**EF\_TMR32\_MX\_FLAG**](#define-ef_tmr32_mx_flag)  ((uint32\_t)0x2)<br> |
| define  | [**EF\_TMR32\_MY\_FLAG**](#define-ef_tmr32_my_flag)  ((uint32\_t)0x4)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E0\_BIT**](#define-ef_tmr32_pwm0cfg_reg_e0_bit)  (uint32\_t)(0)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E0\_MASK**](#define-ef_tmr32_pwm0cfg_reg_e0_mask)  (uint32\_t)(0x3)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E1\_BIT**](#define-ef_tmr32_pwm0cfg_reg_e1_bit)  (uint32\_t)(2)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E1\_MASK**](#define-ef_tmr32_pwm0cfg_reg_e1_mask)  (uint32\_t)(0xc)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E2\_BIT**](#define-ef_tmr32_pwm0cfg_reg_e2_bit)  (uint32\_t)(4)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E2\_MASK**](#define-ef_tmr32_pwm0cfg_reg_e2_mask)  (uint32\_t)(0x30)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E3\_BIT**](#define-ef_tmr32_pwm0cfg_reg_e3_bit)  (uint32\_t)(6)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E3\_MASK**](#define-ef_tmr32_pwm0cfg_reg_e3_mask)  (uint32\_t)(0xc0)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E4\_BIT**](#define-ef_tmr32_pwm0cfg_reg_e4_bit)  (uint32\_t)(8)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E4\_MASK**](#define-ef_tmr32_pwm0cfg_reg_e4_mask)  (uint32\_t)(0x300)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E5\_BIT**](#define-ef_tmr32_pwm0cfg_reg_e5_bit)  (uint32\_t)(10)<br> |
| define  | [**EF\_TMR32\_PWM0CFG\_REG\_E5\_MASK**](#define-ef_tmr32_pwm0cfg_reg_e5_mask)  (uint32\_t)(0xc00)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E0\_BIT**](#define-ef_tmr32_pwm1cfg_reg_e0_bit)  (uint32\_t)(0)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E0\_MASK**](#define-ef_tmr32_pwm1cfg_reg_e0_mask)  (uint32\_t)(0x3)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E1\_BIT**](#define-ef_tmr32_pwm1cfg_reg_e1_bit)  (uint32\_t)(2)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E1\_MASK**](#define-ef_tmr32_pwm1cfg_reg_e1_mask)  (uint32\_t)(0xc)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E2\_BIT**](#define-ef_tmr32_pwm1cfg_reg_e2_bit)  (uint32\_t)(4)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E2\_MASK**](#define-ef_tmr32_pwm1cfg_reg_e2_mask)  (uint32\_t)(0x30)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E3\_BIT**](#define-ef_tmr32_pwm1cfg_reg_e3_bit)  (uint32\_t)(6)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E3\_MASK**](#define-ef_tmr32_pwm1cfg_reg_e3_mask)  (uint32\_t)(0xc0)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E4\_BIT**](#define-ef_tmr32_pwm1cfg_reg_e4_bit)  (uint32\_t)(8)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E4\_MASK**](#define-ef_tmr32_pwm1cfg_reg_e4_mask)  (uint32\_t)(0x300)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E5\_BIT**](#define-ef_tmr32_pwm1cfg_reg_e5_bit)  (uint32\_t)(10)<br> |
| define  | [**EF\_TMR32\_PWM1CFG\_REG\_E5\_MASK**](#define-ef_tmr32_pwm1cfg_reg_e5_mask)  (uint32\_t)(0xc00)<br> |
| define  | [**EF\_TMR32\_TO\_FLAG**](#define-ef_tmr32_to_flag)  ((uint32\_t)0x1)<br> |
| define  | [**IO\_TYPES**](#define-io_types)  <br> |
| define  | [**\_\_R**](#define-__r)  volatile const uint32\_t<br> |
| define  | [**\_\_RW**](#define-__rw)  volatile       uint32\_t<br> |
| define  | [**\_\_W**](#define-__w)  volatile       uint32\_t<br> |

## Structures and Types Documentation

### typedef `EF_TMR32_TYPE`

```c
typedef struct _EF_TMR32_TYPE_ EF_TMR32_TYPE;
```

### typedef `EF_TMR32_TYPE_PTR`

```c
typedef EF_TMR32_TYPE* EF_TMR32_TYPE_PTR;
```

### struct `_EF_TMR32_TYPE_`


Variables:

-  [**\_\_W**](#define-__w) CFG  

-  [**\_\_W**](#define-__w) CMPX  

-  [**\_\_W**](#define-__w) CMPY  

-  [**\_\_W**](#define-__w) CTRL  

-  [**\_\_W**](#define-__w) GCLK  

-  [**\_\_W**](#define-__w) IC  

-  [**\_\_RW**](#define-__rw) IM  

-  [**\_\_R**](#define-__r) MIS  

-  [**\_\_W**](#define-__w) PR  

-  [**\_\_W**](#define-__w) PWM0CFG  

-  [**\_\_W**](#define-__w) PWM1CFG  

-  [**\_\_W**](#define-__w) PWMDT  

-  [**\_\_W**](#define-__w) PWMFC  

-  [**\_\_W**](#define-__w) RELOAD  

-  [**\_\_R**](#define-__r) RIS  

-  [**\_\_R**](#define-__r) TMR  

-  [**\_\_R**](#define-__r) reserved_0  



## Macros Documentation

### define `EF_TMR32_CFG_REG_DIR_BIT`

```c
#define EF_TMR32_CFG_REG_DIR_BIT (uint32_t)(0)
```

### define `EF_TMR32_CFG_REG_DIR_MASK`

```c
#define EF_TMR32_CFG_REG_DIR_MASK (uint32_t)(0x3)
```

### define `EF_TMR32_CFG_REG_P_BIT`

```c
#define EF_TMR32_CFG_REG_P_BIT (uint32_t)(2)
```

### define `EF_TMR32_CFG_REG_P_MASK`

```c
#define EF_TMR32_CFG_REG_P_MASK (uint32_t)(0x4)
```

### define `EF_TMR32_CTRL_REG_DTE_BIT`

```c
#define EF_TMR32_CTRL_REG_DTE_BIT (uint32_t)(4)
```

### define `EF_TMR32_CTRL_REG_DTE_MASK`

```c
#define EF_TMR32_CTRL_REG_DTE_MASK (uint32_t)(0x10)
```

### define `EF_TMR32_CTRL_REG_P0E_BIT`

```c
#define EF_TMR32_CTRL_REG_P0E_BIT (uint32_t)(2)
```

### define `EF_TMR32_CTRL_REG_P0E_MASK`

```c
#define EF_TMR32_CTRL_REG_P0E_MASK (uint32_t)(0x4)
```

### define `EF_TMR32_CTRL_REG_P1E_BIT`

```c
#define EF_TMR32_CTRL_REG_P1E_BIT (uint32_t)(3)
```

### define `EF_TMR32_CTRL_REG_P1E_MASK`

```c
#define EF_TMR32_CTRL_REG_P1E_MASK (uint32_t)(0x8)
```

### define `EF_TMR32_CTRL_REG_PI0_BIT`

```c
#define EF_TMR32_CTRL_REG_PI0_BIT (uint32_t)(5)
```

### define `EF_TMR32_CTRL_REG_PI0_MASK`

```c
#define EF_TMR32_CTRL_REG_PI0_MASK (uint32_t)(0x20)
```

### define `EF_TMR32_CTRL_REG_PI1_BIT`

```c
#define EF_TMR32_CTRL_REG_PI1_BIT (uint32_t)(6)
```

### define `EF_TMR32_CTRL_REG_PI1_MASK`

```c
#define EF_TMR32_CTRL_REG_PI1_MASK (uint32_t)(0x40)
```

### define `EF_TMR32_CTRL_REG_TE_BIT`

```c
#define EF_TMR32_CTRL_REG_TE_BIT (uint32_t)(0)
```

### define `EF_TMR32_CTRL_REG_TE_MASK`

```c
#define EF_TMR32_CTRL_REG_TE_MASK (uint32_t)(0x1)
```

### define `EF_TMR32_CTRL_REG_TS_BIT`

```c
#define EF_TMR32_CTRL_REG_TS_BIT (uint32_t)(1)
```

### define `EF_TMR32_CTRL_REG_TS_MASK`

```c
#define EF_TMR32_CTRL_REG_TS_MASK (uint32_t)(0x2)
```

### define `EF_TMR32_MX_FLAG`

```c
#define EF_TMR32_MX_FLAG ((uint32_t)0x2)
```

### define `EF_TMR32_MY_FLAG`

```c
#define EF_TMR32_MY_FLAG ((uint32_t)0x4)
```

### define `EF_TMR32_PWM0CFG_REG_E0_BIT`

```c
#define EF_TMR32_PWM0CFG_REG_E0_BIT (uint32_t)(0)
```

### define `EF_TMR32_PWM0CFG_REG_E0_MASK`

```c
#define EF_TMR32_PWM0CFG_REG_E0_MASK (uint32_t)(0x3)
```

### define `EF_TMR32_PWM0CFG_REG_E1_BIT`

```c
#define EF_TMR32_PWM0CFG_REG_E1_BIT (uint32_t)(2)
```

### define `EF_TMR32_PWM0CFG_REG_E1_MASK`

```c
#define EF_TMR32_PWM0CFG_REG_E1_MASK (uint32_t)(0xc)
```

### define `EF_TMR32_PWM0CFG_REG_E2_BIT`

```c
#define EF_TMR32_PWM0CFG_REG_E2_BIT (uint32_t)(4)
```

### define `EF_TMR32_PWM0CFG_REG_E2_MASK`

```c
#define EF_TMR32_PWM0CFG_REG_E2_MASK (uint32_t)(0x30)
```

### define `EF_TMR32_PWM0CFG_REG_E3_BIT`

```c
#define EF_TMR32_PWM0CFG_REG_E3_BIT (uint32_t)(6)
```

### define `EF_TMR32_PWM0CFG_REG_E3_MASK`

```c
#define EF_TMR32_PWM0CFG_REG_E3_MASK (uint32_t)(0xc0)
```

### define `EF_TMR32_PWM0CFG_REG_E4_BIT`

```c
#define EF_TMR32_PWM0CFG_REG_E4_BIT (uint32_t)(8)
```

### define `EF_TMR32_PWM0CFG_REG_E4_MASK`

```c
#define EF_TMR32_PWM0CFG_REG_E4_MASK (uint32_t)(0x300)
```

### define `EF_TMR32_PWM0CFG_REG_E5_BIT`

```c
#define EF_TMR32_PWM0CFG_REG_E5_BIT (uint32_t)(10)
```

### define `EF_TMR32_PWM0CFG_REG_E5_MASK`

```c
#define EF_TMR32_PWM0CFG_REG_E5_MASK (uint32_t)(0xc00)
```

### define `EF_TMR32_PWM1CFG_REG_E0_BIT`

```c
#define EF_TMR32_PWM1CFG_REG_E0_BIT (uint32_t)(0)
```

### define `EF_TMR32_PWM1CFG_REG_E0_MASK`

```c
#define EF_TMR32_PWM1CFG_REG_E0_MASK (uint32_t)(0x3)
```

### define `EF_TMR32_PWM1CFG_REG_E1_BIT`

```c
#define EF_TMR32_PWM1CFG_REG_E1_BIT (uint32_t)(2)
```

### define `EF_TMR32_PWM1CFG_REG_E1_MASK`

```c
#define EF_TMR32_PWM1CFG_REG_E1_MASK (uint32_t)(0xc)
```

### define `EF_TMR32_PWM1CFG_REG_E2_BIT`

```c
#define EF_TMR32_PWM1CFG_REG_E2_BIT (uint32_t)(4)
```

### define `EF_TMR32_PWM1CFG_REG_E2_MASK`

```c
#define EF_TMR32_PWM1CFG_REG_E2_MASK (uint32_t)(0x30)
```

### define `EF_TMR32_PWM1CFG_REG_E3_BIT`

```c
#define EF_TMR32_PWM1CFG_REG_E3_BIT (uint32_t)(6)
```

### define `EF_TMR32_PWM1CFG_REG_E3_MASK`

```c
#define EF_TMR32_PWM1CFG_REG_E3_MASK (uint32_t)(0xc0)
```

### define `EF_TMR32_PWM1CFG_REG_E4_BIT`

```c
#define EF_TMR32_PWM1CFG_REG_E4_BIT (uint32_t)(8)
```

### define `EF_TMR32_PWM1CFG_REG_E4_MASK`

```c
#define EF_TMR32_PWM1CFG_REG_E4_MASK (uint32_t)(0x300)
```

### define `EF_TMR32_PWM1CFG_REG_E5_BIT`

```c
#define EF_TMR32_PWM1CFG_REG_E5_BIT (uint32_t)(10)
```

### define `EF_TMR32_PWM1CFG_REG_E5_MASK`

```c
#define EF_TMR32_PWM1CFG_REG_E5_MASK (uint32_t)(0xc00)
```

### define `EF_TMR32_TO_FLAG`

```c
#define EF_TMR32_TO_FLAG ((uint32_t)0x1)
```

### define `IO_TYPES`

```c
#define IO_TYPES 
```

### define `__R`

```c
#define __R volatile const uint32_t
```

### define `__RW`

```c
#define __RW volatile       uint32_t
```

### define `__W`

```c
#define __W volatile       uint32_t
```


