#ifndef EF_UART_H
#define EF_UART_H

#include "EF_TMR32_regs.h"
#include "EF_Driver_Common.h"


#define EF_TMR32_ACTION_NONE    ((uint32_t)0)
#define EF_TMR32_ACTION_LOW     ((uint32_t)1)
#define EF_TMR32_ACTION_HIGH    ((uint32_t)2)
#define EF_TMR32_ACTION_INVERT  ((uint32_t)3)

#define EF_TMR32_ACTION_MAX_VALUE  ((uint32_t)3)

#define EF_TMR32_PWMDT_MAX_VALUE    ((uint32_t)0x000000FF)
#define EF_TMR32_PR_MAX_VALUE       ((uint32_t)0x0000FFFF)
#define EF_TMR32_IM_MAX_VALUE       ((uint32_t)2)
#define EF_TMR32_ICR_MAX_VALUE      ((uint32_t)2)

EF_DRIVER_STATUS EF_TMR32_setGclkEnable (EF_TMR32_TYPE_PTR tmr32, uint32_t value);

//! enables timer by setting "TE" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_enable(EF_TMR32_TYPE_PTR tmr32);


//! disables timer by setting "TE" bit in the CTRL register to 0 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_disable(EF_TMR32_TYPE_PTR tmr32);


//! enables timer re-start; used in the one-shot mode to restart the timer.
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_restart(EF_TMR32_TYPE_PTR tmr32);

//! enables TMR0 by setting "P0E" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_PWM0Enable(EF_TMR32_TYPE_PTR tmr32);

//! enables TMR1 by setting "P1E" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_PWM1Enable(EF_TMR32_TYPE_PTR tmr32);

//! enables deadtime by setting "DTE" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_deadtimeEnable(EF_TMR32_TYPE_PTR tmr32);

//! invert TMR0 by setting "P0I" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_PWM0Invert(EF_TMR32_TYPE_PTR tmr32);

//! invert TMR1 by setting "P1I" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_PWM1Invert(EF_TMR32_TYPE_PTR tmr32);

//! set the timer direction to be up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_setUpCount(EF_TMR32_TYPE_PTR tmr32);

//! set the timer direction to be down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_setDownCount(EF_TMR32_TYPE_PTR tmr32);

//! set the timer direction to be up/down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_setUpDownCount(EF_TMR32_TYPE_PTR tmr32);

//! set the timer to be periodic
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_setPeriodic(EF_TMR32_TYPE_PTR tmr32);

//! set the timer to be one shot
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
EF_DRIVER_STATUS EF_TMR32_setOneShot(EF_TMR32_TYPE_PTR tmr32);

//! set the action of TMR0 when the timer matches Zero value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR0 when the timer matches CMPX value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR0 when the timer matches CMPY value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR0 when the timer matches Reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR0 when the timer matches CMPX value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR0 when the timer matches CMPY value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR1 when the timer matches Zero value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR1 when the timer matches CMPX value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR1 when the timer matches CMPY value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR1 when the timer matches Reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR1 when the timer matches CMPX value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the action of TMR1 when the timer matches CMPY value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action uint32_t could be NONE, LOW, HIGH, or INVERT
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! set the timer reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value timer reload value 
    */
EF_DRIVER_STATUS EF_TMR32_setRELOAD (EF_TMR32_TYPE_PTR tmr32, uint32_t value);

//! get the timer reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns reload register value 
    */
EF_DRIVER_STATUS EF_TMR32_getRELOAD (EF_TMR32_TYPE_PTR tmr32, uint32_t* reload_value);

//! set the CMPX register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value CMPX value 
    */
EF_DRIVER_STATUS EF_TMR32_setCMPX (EF_TMR32_TYPE_PTR tmr32, uint32_t value);

//! get the CMPX register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns CMPX register value 
    */
EF_DRIVER_STATUS EF_TMR32_getCMPX (EF_TMR32_TYPE_PTR tmr32, uint32_t* cmpx_value);

//! set the CMPY register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value CMPY value 
    */
EF_DRIVER_STATUS EF_TMR32_setCMPY (EF_TMR32_TYPE_PTR tmr32, uint32_t value);

//! get the CMPY register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns CMPY register value 
    */
EF_DRIVER_STATUS EF_TMR32_getCMPY (EF_TMR32_TYPE_PTR tmr32, uint32_t* cmpy_value);

//! get the current value of the timer 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns current timer value 
    */
EF_DRIVER_STATUS EF_TMR32_getTMR (EF_TMR32_TYPE_PTR tmr32, uint32_t* tmr_value);

//! set the timer deadtime register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value deadtime register value
    */
EF_DRIVER_STATUS EF_TMR32_setDeadtime (EF_TMR32_TYPE_PTR tmr32, uint32_t value);

EF_DRIVER_STATUS EF_TMR32_getDeadtime (EF_TMR32_TYPE_PTR tmr32, uint32_t* deadtime_value);

EF_DRIVER_STATUS EF_TMR32_setPR(EF_TMR32_TYPE_PTR tmr32, uint32_t value);

EF_DRIVER_STATUS EF_TMR32_setInterruptMask(uint32_t spi_base, uint32_t mask);

EF_DRIVER_STATUS EF_TMR32_clearIrq(EF_TMR32_TYPE_PTR tmr32, uint32_t mask);



#endif