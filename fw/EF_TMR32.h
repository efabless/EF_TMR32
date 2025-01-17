/*
	Copyright 2025 Efabless Corp.


	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/


/*! \file EF_TMR32.h
    \brief C header file for TMR32 APIs which contains the function prototypes 
    
*/
#ifndef EF_TMR32_H
#define EF_TMR32_H

/******************************************************************************
* Includes
******************************************************************************/
#include "EF_TMR32_regs.h"
#include "EF_Driver_Common.h"


/******************************************************************************
* Macros and Constants
******************************************************************************/

#define EF_TMR32_ACTION_NONE    ((uint32_t)0)   //!< No action on match (do nothing)
#define EF_TMR32_ACTION_LOW     ((uint32_t)1)   //!< Set output to LOW when match occurs
#define EF_TMR32_ACTION_HIGH    ((uint32_t)2)   //!< Set output to HIGH when match occurs
#define EF_TMR32_ACTION_INVERT  ((uint32_t)3)   //!< Invert the output when match occurs

#define EF_TMR32_ACTION_MAX_VALUE  ((uint32_t)3)    //!< Maximum value for the action field

#define EF_TMR32_PWMDT_MAX_VALUE    ((uint32_t)0x000000FF)  //!< Maximum value for the deadtime register
#define EF_TMR32_PR_MAX_VALUE       ((uint32_t)0x0000FFFF)  //!< Maximum value for the PR register
#define EF_TMR32_IM_MAX_VALUE       ((uint32_t)2)           //!< Maximum value for the IM register
#define EF_TMR32_ICR_MAX_VALUE      ((uint32_t)2)           //!< Maximum value for the ICR register


/******************************************************************************
* Typedefs and Enums
******************************************************************************/




/******************************************************************************
* Function Prototypes
******************************************************************************/

//! Sets the GCLK enable bit in the UART register to a certain value
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] value The value of the GCLK enable bit
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setGclkEnable(EF_TMR32_TYPE_PTR tmr32, uint32_t value);

//! Enables timer by setting "TE" bit in the CTRL register to 1 
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_enable(EF_TMR32_TYPE_PTR tmr32);


//! Disables timer by setting "TE" bit in the CTRL register to 0 
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_disable(EF_TMR32_TYPE_PTR tmr32);


//! Enables timer re-start; used in the one-shot mode to restart the timer by setting the "TS" bit in the CTRL register to 1 and then to 0
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_restart(EF_TMR32_TYPE_PTR tmr32);

//! Enables PWM0 by setting "P0E" bit in the CTRL register to 1 
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_PWM0Enable(EF_TMR32_TYPE_PTR tmr32);

//! Enables PWM1 by setting "P1E" bit in the CTRL register to 1 
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_PWM1Enable(EF_TMR32_TYPE_PTR tmr32);

//! Enables PWM dead-time by setting the "DTE" (Dead-Time Enable) bit in the CTRL register to 1.
//! Dead-time is a critical feature in PWM signal generation used to ensure a safe period between switching the high and low states, 
//! preventing short circuits or other issues in systems with complementary outputs, such as H-bridge drivers.
//! When enabled, the "DTE" bit introduces a fixed delay between the switching of PWM channels to allow for this safety margin.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_PWMDeadtimeEnable(EF_TMR32_TYPE_PTR tmr32);

//! Inverts PWM0 output by setting "P0I" bit in the CTRL register to 1 
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_PWM0Invert(EF_TMR32_TYPE_PTR tmr32);

//! Inverts PWM1 output by setting "P1I" bit in the CTRL register to 1 
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_PWM1Invert(EF_TMR32_TYPE_PTR tmr32);

//! Sets the timer direction to be up counting by setting the "DIR" field in the CTRL register to 0b10
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setUpCount(EF_TMR32_TYPE_PTR tmr32);

//! Sets the timer direction to be down counting by setting the "DIR" field in the CTRL register to 0b01
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setDownCount(EF_TMR32_TYPE_PTR tmr32);

//! Sets the timer direction to be up/down counting by setting the "DIR" field in the CTRL register to 0b11
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setUpDownCount(EF_TMR32_TYPE_PTR tmr32);

//! Sets the timer to operate in periodic mode by setting the "P" bit in the CFG register to 1
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPeriodic(EF_TMR32_TYPE_PTR tmr32);

//! Sets the timer to operate in one-shot mode by clearing the "P" bit in the CFG register to 0
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setOneShot(EF_TMR32_TYPE_PTR tmr32);

//! Configures the action of TMR0 PWM when the timer matches the Zero value.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter reaches zero. 
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM0 configuration register by modifying \ref EF_TMR32_PWM0CFG_REG_E0_BIT.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the Zero value. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR0 PWM when the timer matches the CMPX value while up counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting up.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM0 configuration register by modifying \ref EF_TMR32_PWM0CFG_REG_E1_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPX value while counting up. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXUpCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR0 PWM when the timer matches the CMPY value while up counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting up.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM0 configuration register by modifying \ref EF_TMR32_PWM0CFG_REG_E2_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPY value while counting up. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYUpCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR0 PWM when the timer matches the RELOAD value.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the RELOAD value.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM0 configuration register by modifying \ref EF_TMR32_PWM0CFG_REG_E3_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the RELOAD value. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR0 PWM when the timer matches the CMPY value while down counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting down.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM0 configuration register by modifying \ref EF_TMR32_PWM0CFG_REG_E4_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular
//! value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPY value while counting down. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR0 PWM when the timer matches the CMPX value while down counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting down.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM0 configuration register by modifying \ref EF_TMR32_PWM0CFG_REG_E5_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPX value while counting down. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR1 PWM when the timer matches the Zero value.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter reaches zero.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM1 configuration register by modifying \ref EF_TMR32_PWM1CFG_REG_E0_BIT.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the Zero value. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR1 PWM when the timer matches the CMPX value while up counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting up.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM1 configuration register by modifying \ref EF_TMR32_PWM1CFG_REG_E1_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPX value while counting up. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXUpCountingAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR1 PWM when the timer matches the CMPY value while up counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting up.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM1 configuration register by modifying \ref EF_TMR32_PWM1CFG_REG_E2_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPY value while counting up. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYUpCountingAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR1 PWM when the timer matches the RELOAD value.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the RELOAD value.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM1 configuration register by modifying \ref EF_TMR32_PWM1CFG_REG_E3_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the RELOAD value. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR1 PWM when the timer matches the CMPY value while down counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPY value while counting down.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM1 configuration register by modifying \ref EF_TMR32_PWM1CFG_REG_E4_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPY value while counting down. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Configures the action of TMR1 PWM when the timer matches the CMPX value while down counting.
//! This function allows the user to specify what happens to the PWM output signal when the timer counter matches the CMPX value while counting down.
//! The available actions are: no action, set the output to LOW, set the output to HIGH, or invert the current state of the output.
//! The action is configured in the PWM1 configuration register by modifying \ref EF_TMR32_PWM1CFG_REG_E5_BI.
//! This is commonly used in PWM applications to define the output response when the counter reaches a particular value.
    /*!
        \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR , which points to the base memory address of TMR32 registers. \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
        \param [in] action A uint32_t value specifying the action to take when the timer matches the CMPX value while counting down. The possible values are:
        - \ref EF_TMR32_ACTION_NONE: No action (do nothing)
        - \ref EF_TMR32_ACTION_LOW: Set the PWM output to LOW
        - \ref EF_TMR32_ACTION_HIGH: Set the PWM output to HIGH
        - \ref EF_TMR32_ACTION_INVERT: Invert the current output state
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action);

//! Sets the reload value of a 32-bit timer by writing to the RELOAD register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [in] value The reload value to set in the RELOAD register.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_setRELOAD (EF_TMR32_TYPE_PTR tmr32, uint32_t value);


//! Sets the compare value of a 32-bit timer by writing to the CMPX register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [in] value The compare value to set in the CMPX register.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_setCMPX (EF_TMR32_TYPE_PTR tmr32, uint32_t value);


//! Sets the compare value Y of a 32-bit timer by writing to the CMPY register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [in] value The compare value to set in the CMPY register.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_setCMPY (EF_TMR32_TYPE_PTR tmr32, uint32_t value);


//! Retrieves the current timer value by reading the TMR register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [out] tmr_value A pointer to a uint32_t where the timer value will be stored.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_getTMR (EF_TMR32_TYPE_PTR tmr32, uint32_t* tmr_value);

//! Sets the PWM dead time value of the PWM by writing to the PWMDT register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [in] value The dead time value to set in the PWMDT register. 
                      Must not exceed \ref EF_TMR32_PWMDT_MAX_VALUE.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_setPWMDeadtime (EF_TMR32_TYPE_PTR tmr32, uint32_t value);

//! Sets the prescaler value of the timer by writing to the PR register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [in] value The prescaler value to set in the PR register. 
                      Must not exceed \ref EF_TMR32_PR_MAX_VALUE.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_setPR(EF_TMR32_TYPE_PTR tmr32, uint32_t value);


//! Sets the interrupt mask of the timer by writing to the IM register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [in] mask The interrupt mask value to set in the IM register. 
                     Must not exceed \ref EF_TMR32_IM_MAX_VALUE.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_setIM(EF_TMR32_TYPE_PTR tmr32, uint32_t mask);


//! Sets the interrupt clear register of the timer by writing to the ICR register.
/*!
    \param [in] tmr32 An \ref EF_TMR32_TYPE_PTR, which points to the base memory address of TMR32 registers. 
                      \ref EF_TMR32_TYPE is a structure that contains the TMR32 registers.
    \param [in] mask The interrupt clear mask value to set in the ICR register. 
                     Must not exceed \ref EF_TMR32_ICR_MAX_VALUE.
    
    \return status A value of type \ref EF_DRIVER_STATUS: returns a success or error code.
*/
EF_DRIVER_STATUS EF_TMR32_setICR(EF_TMR32_TYPE_PTR tmr32, uint32_t mask);


/******************************************************************************
* External Variables
******************************************************************************/


#endif  //EF_TMR32_H


/******************************************************************************
* End of File
******************************************************************************/
