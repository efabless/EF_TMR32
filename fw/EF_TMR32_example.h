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


/*! \file EF_TMR32_example.h
    \brief C header file containing an example of how to use the TMR32 APIs
    
*/


#ifndef EF_TMR32_EXAMPLE_H
#define EF_TMR32_EXAMPLE_H

/******************************************************************************
* Includes
******************************************************************************/
#include "EF_TMR32.h"

/******************************************************************************
* File-Specific Macros and Constants
******************************************************************************/


/******************************************************************************
* Static Variables
******************************************************************************/



/******************************************************************************
* Static Function Prototypes
******************************************************************************/



/******************************************************************************
* Function Definitions
******************************************************************************/



/******************************************************************************
* Example Usage
******************************************************************************/

/** @brief Example of Normal Usage
 Example usage:
 @code
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
 @endcode
 */
EF_DRIVER_STATUS EF_TMR32_normalExample(void);

/** @brief Example of PWM Usage
 Example usage:
 @code
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
 @endcode
 */
EF_DRIVER_STATUS EF_TMR32_PWM_Example(void);
/******************************************************************************
* Static Function Definitions
******************************************************************************/



#endif // EF_TMR32_EXAMPLE_H

/******************************************************************************
* End of File
******************************************************************************/
