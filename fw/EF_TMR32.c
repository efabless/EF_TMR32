/*! \file EF_UART.c
    \brief C file for UART APIs which contains the function implmentations 
    
*/

#ifndef EF_TMR32_C
#define EF_TMR32_C
#include "EF_TMR32.h"


EF_DRIVER_STATUS EF_TMR32_setGclkEnable (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    tmr32->GCLK = value;
}

EF_DRIVER_STATUS EF_TMR32_enable(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_TE_BIT);
}

EF_DRIVER_STATUS EF_TMR32_disable(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL &= ~(1 << EF_TMR32_CTRL_REG_TE_BIT);
}

EF_DRIVER_STATUS EF_TMR32_restart(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_TS_BIT);
    tmr32->CTRL &= ~(1 << EF_TMR32_CTRL_REG_TS_BIT);

}

EF_DRIVER_STATUS EF_TMR32_PWM0Enable(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_P0E_BIT);
}

EF_DRIVER_STATUS EF_TMR32_PWM1Enable(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_P1E_BIT);
}

EF_DRIVER_STATUS EF_TMR32_deadtimeEnable(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_DTE_BIT);
}

EF_DRIVER_STATUS EF_TMR32_PWM0Invert(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_PI0_BIT);
}

EF_DRIVER_STATUS EF_TMR32_PWM1Invert(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_PI1_BIT);
}

EF_DRIVER_STATUS EF_TMR32_setUpCount(EF_TMR32_TYPE_PTR tmr32){

    // Clear the field bits in the register using the defined mask
    tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->CFG |= ((0b10 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK);
}

EF_DRIVER_STATUS EF_TMR32_setDownCount(EF_TMR32_TYPE_PTR tmr32){

    // Clear the field bits in the register using the defined mask
    tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->CFG |= ((0b01 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK);
}

EF_DRIVER_STATUS EF_TMR32_setUpDownCount(EF_TMR32_TYPE_PTR tmr32){

    // Clear the field bits in the register using the defined mask
    tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->CFG |= ((0b11 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK);
}

EF_DRIVER_STATUS EF_TMR32_setPeriodic(EF_TMR32_TYPE_PTR tmr32){

    // set the enable bit to 1 at the specified offset
    tmr32->CFG |= (1 << EF_TMR32_CFG_REG_P_BIT);
}

EF_DRIVER_STATUS EF_TMR32_setOneShot(EF_TMR32_TYPE_PTR tmr32){

    // Clear the enable bit using the specified  mask
    tmr32->CFG &= ~EF_TMR32_CFG_REG_P_BIT;
}

EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E0_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E0_BIT) & EF_TMR32_PWM0CFG_REG_E0_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E1_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E1_BIT) & EF_TMR32_PWM0CFG_REG_E1_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E2_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E2_BIT) & EF_TMR32_PWM0CFG_REG_E2_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E3_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E3_BIT) & EF_TMR32_PWM0CFG_REG_E3_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E4_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E4_BIT) & EF_TMR32_PWM0CFG_REG_E4_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM0MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E5_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E5_BIT) & EF_TMR32_PWM0CFG_REG_E5_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingZeroAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E0_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E0_BIT) & EF_TMR32_PWM1CFG_REG_E0_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E1_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E1_BIT) & EF_TMR32_PWM1CFG_REG_E1_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E2_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E2_BIT) & EF_TMR32_PWM1CFG_REG_E2_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingRELOADAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E3_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E3_BIT) & EF_TMR32_PWM1CFG_REG_E3_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPYDownCountAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E4_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E4_BIT) & EF_TMR32_PWM1CFG_REG_E4_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setPWM1MatchingCMPXDownCountAction(EF_TMR32_TYPE_PTR tmr32, enum actions action){

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E5_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E5_BIT) & EF_TMR32_PWM1CFG_REG_E5_MASK);

}

EF_DRIVER_STATUS EF_TMR32_setRELOAD (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    tmr32->RELOAD = value;

}

EF_DRIVER_STATUS EF_TMR32_getRELOAD (EF_TMR32_TYPE_PTR tmr32, uint32_t* reload_value){

    *reload_value = tmr32->RELOAD;

}

EF_DRIVER_STATUS EF_TMR32_setCMPX (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    tmr32->CMPX = value;

}

EF_DRIVER_STATUS EF_TMR32_getCMPX (EF_TMR32_TYPE_PTR tmr32, uint32_t* cmpx_value){

    * cmpx_value = tmr32->CMPX;

}

EF_DRIVER_STATUS EF_TMR32_setCMPY (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    tmr32->CMPY = value;

}

EF_DRIVER_STATUS EF_TMR32_getCMPY (EF_TMR32_TYPE_PTR tmr32, uint32_t* cmpy_value){

    *cmpy_value = tmr32->CMPY;

}

EF_DRIVER_STATUS EF_TMR32_getTMR (EF_TMR32_TYPE_PTR tmr32, uint32_t* tmr_value){

    *tmr_value = tmr32->TMR;

}

EF_DRIVER_STATUS EF_TMR32_setDeadtime (EF_TMR32_TYPE_PTR tmr32, uint32_t value){

    tmr32->PWMDT = value;

}

EF_DRIVER_STATUS EF_TMR32_getDeadtime (EF_TMR32_TYPE_PTR tmr32, uint32_t* deadtime_value){

    *deadtime_value = tmr32->PWMDT;

}

EF_DRIVER_STATUS EF_TMR32_setPR(EF_TMR32_TYPE_PTR tmr32, uint32_t value){
 
    tmr32->PR = value;
}


EF_DRIVER_STATUS EF_TMR32_setInterruptMask(EF_TMR32_TYPE_PTR tmr32, uint32_t mask){

    tmr32->IM = mask;
}
EF_DRIVER_STATUS EF_TMR32_clearIrq(EF_TMR32_TYPE_PTR tmr32, uint32_t mask){

    tmr32->IC = mask;
}

#endif