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


/*! \file EF_TMR32.c
    \brief C file for TMR32 APIs which contains the function implmentations 
    
*/

#ifndef EF_TMR32_C
#define EF_TMR32_C

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

EF_DRIVER_STATUS EF_TMR32_setGclkEnable(EF_TMR32_TYPE_PTR tmr32, uint32_t value) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if (value > (uint32_t)0x1) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        tmr32->GCLK = value; // Set the GCLK enable bit to the provided value
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_enable(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= ((uint32_t)1 << EF_TMR32_CTRL_REG_TE_BIT); // Set the enable bit to 1
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_disable(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL &= ~((uint32_t)1 << EF_TMR32_CTRL_REG_TE_BIT); // Clear the enable bit
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_restart(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= ((uint32_t)1 << EF_TMR32_CTRL_REG_TS_BIT);  // Set the restart bit
        tmr32->CTRL &= ~((uint32_t)1 << EF_TMR32_CTRL_REG_TS_BIT); // Clear the restart bit
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_PWM0Enable(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= ((uint32_t)1 << EF_TMR32_CTRL_REG_P0E_BIT); // Enable PWM0
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_PWM1Enable(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= ((uint32_t)1 << EF_TMR32_CTRL_REG_P1E_BIT); // Enable PWM1
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_PWMDeadtimeEnable(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= ((uint32_t)1 << EF_TMR32_CTRL_REG_DTE_BIT); // Enable dead-time
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_PWM0Invert(EF_TMR32_TYPE_PTR tmr32){
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= ((uint32_t)1 << EF_TMR32_CTRL_REG_PI0_BIT); // Invert PWM0 output
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_PWM1Invert(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= ((uint32_t)1 << EF_TMR32_CTRL_REG_PI1_BIT); // Invert PWM1 output
    }

    return status;
}



EF_DRIVER_STATUS EF_TMR32_setUpCount(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK; // Clear the direction field
        tmr32->CFG |= (((uint32_t)0b10 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK); // Set up-count direction
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setDownCount(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK; // Clear the direction field
        tmr32->CFG |= (((uint32_t)0b01 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK); // Set down-count mode
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setUpDownCount(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK; // Clear the direction field
        tmr32->CFG |= (((uint32_t)0b11 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK); // Set up-down-count mode
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPeriodic(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG |= ((uint32_t)1 << EF_TMR32_CFG_REG_P_BIT); // Enable periodic mode
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setOneShot(EF_TMR32_TYPE_PTR tmr32) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~EF_TMR32_CFG_REG_P_BIT; // Disable periodic mode to set one-shot mode
    }

    return status;
}



EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E0_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E0_BIT) & EF_TMR32_PWM0CFG_REG_E0_MASK);
    }
    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXUpCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E1_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E1_BIT) & EF_TMR32_PWM0CFG_REG_E1_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYUpCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E2_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E2_BIT) & EF_TMR32_PWM0CFG_REG_E2_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E3_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E3_BIT) & EF_TMR32_PWM0CFG_REG_E3_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E4_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E4_BIT) & EF_TMR32_PWM0CFG_REG_E4_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E5_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E5_BIT) & EF_TMR32_PWM0CFG_REG_E5_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E0_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E0_BIT) & EF_TMR32_PWM1CFG_REG_E0_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXUpCountingAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E1_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E1_BIT) & EF_TMR32_PWM1CFG_REG_E1_MASK);
    }

    return status;
}



EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYUpCountingAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E2_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E2_BIT) & EF_TMR32_PWM1CFG_REG_E2_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E3_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E3_BIT) & EF_TMR32_PWM1CFG_REG_E3_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E4_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E4_BIT) & EF_TMR32_PWM1CFG_REG_E4_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > EF_TMR32_ACTION_MAX_VALUE)) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E5_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E5_BIT) & EF_TMR32_PWM1CFG_REG_E5_MASK);
    }

    return status;
}


EF_DRIVER_STATUS EF_TMR32_setRELOAD (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {

        tmr32->RELOAD = value;
    }
    return status;

}



EF_DRIVER_STATUS EF_TMR32_setCMPX (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {

        tmr32->CMPX = value;
    }

    return status;
}



EF_DRIVER_STATUS EF_TMR32_setCMPY (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {

        tmr32->CMPY = value;
    }

    return status;
}



EF_DRIVER_STATUS EF_TMR32_getTMR (EF_TMR32_TYPE_PTR tmr32, uint32_t* tmr_value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (tmr_value == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer value pointer is NULL
    }else{
        *tmr_value = tmr32->TMR;
    }
    return status;

}


EF_DRIVER_STATUS EF_TMR32_setPWMDeadtime (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (value > EF_TMR32_PWMDT_MAX_VALUE) {

        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL   

    }else {
                tmr32->PWMDT = value;
    }
    return status;
}


EF_DRIVER_STATUS EF_TMR32_setPR(EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (value > EF_TMR32_PR_MAX_VALUE) {

        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
        
    }else{
        tmr32->PR = value;
    }
 
    return status;
}


EF_DRIVER_STATUS EF_TMR32_setIM(EF_TMR32_TYPE_PTR tmr32, uint32_t mask){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (mask > EF_TMR32_IM_MAX_VALUE) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL   
    }else{
        tmr32->IM = mask;
    }
    return status;
}


EF_DRIVER_STATUS EF_TMR32_setICR(EF_TMR32_TYPE_PTR tmr32, uint32_t mask){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (mask > EF_TMR32_ICR_MAX_VALUE) {

        status = EF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
        
    }else{
        tmr32->IC = mask;
    }
    return status;
}


/******************************************************************************
* Static Function Definitions
******************************************************************************/


#endif // EF_TMR32_C

/******************************************************************************
* End of File
******************************************************************************/
