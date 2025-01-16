/*
	Copyright 2024 Efabless Corp.

	Author: Efabless Corp. (ip_admin@efabless.com)

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/

#ifndef EF_TMR32REGS_H
#define EF_TMR32REGS_H

#ifndef IO_TYPES
#define IO_TYPES
#define   __R     volatile const uint32_t
#define   __W     volatile       uint32_t
#define   __RW    volatile       uint32_t
#endif

#define EF_TMR32_CTRL_REG_TE_BIT	    (uint32_t)(0)
#define EF_TMR32_CTRL_REG_TE_MASK	    (uint32_t)(0x1)
#define EF_TMR32_CTRL_REG_TS_BIT	    (uint32_t)(1)
#define EF_TMR32_CTRL_REG_TS_MASK	    (uint32_t)(0x2)
#define EF_TMR32_CTRL_REG_P0E_BIT	    (uint32_t)(2)
#define EF_TMR32_CTRL_REG_P0E_MASK	    (uint32_t)(0x4)
#define EF_TMR32_CTRL_REG_P1E_BIT	    (uint32_t)(3)
#define EF_TMR32_CTRL_REG_P1E_MASK	    (uint32_t)(0x8)
#define EF_TMR32_CTRL_REG_DTE_BIT	    (uint32_t)(4)
#define EF_TMR32_CTRL_REG_DTE_MASK	    (uint32_t)(0x10)
#define EF_TMR32_CTRL_REG_PI0_BIT	    (uint32_t)(5)
#define EF_TMR32_CTRL_REG_PI0_MASK	    (uint32_t)(0x20)
#define EF_TMR32_CTRL_REG_PI1_BIT	    (uint32_t)(6)
#define EF_TMR32_CTRL_REG_PI1_MASK	    (uint32_t)(0x40)
#define EF_TMR32_CFG_REG_DIR_BIT	    (uint32_t)(0)
#define EF_TMR32_CFG_REG_DIR_MASK	    (uint32_t)(0x3)
#define EF_TMR32_CFG_REG_P_BIT	        (uint32_t)(2)
#define EF_TMR32_CFG_REG_P_MASK	        (uint32_t)(0x4)
#define EF_TMR32_PWM0CFG_REG_E0_BIT	    (uint32_t)(0)
#define EF_TMR32_PWM0CFG_REG_E0_MASK	(uint32_t)(0x3)
#define EF_TMR32_PWM0CFG_REG_E1_BIT	    (uint32_t)(2)
#define EF_TMR32_PWM0CFG_REG_E1_MASK	(uint32_t)(0xc)
#define EF_TMR32_PWM0CFG_REG_E2_BIT	    (uint32_t)(4)
#define EF_TMR32_PWM0CFG_REG_E2_MASK	(uint32_t)(0x30)
#define EF_TMR32_PWM0CFG_REG_E3_BIT	    (uint32_t)(6)
#define EF_TMR32_PWM0CFG_REG_E3_MASK	(uint32_t)(0xc0)
#define EF_TMR32_PWM0CFG_REG_E4_BIT	    (uint32_t)(8)
#define EF_TMR32_PWM0CFG_REG_E4_MASK	(uint32_t)(0x300)
#define EF_TMR32_PWM0CFG_REG_E5_BIT	    (uint32_t)(10)
#define EF_TMR32_PWM0CFG_REG_E5_MASK	(uint32_t)(0xc00)
#define EF_TMR32_PWM1CFG_REG_E0_BIT	    (uint32_t)(0)
#define EF_TMR32_PWM1CFG_REG_E0_MASK	(uint32_t)(0x3)
#define EF_TMR32_PWM1CFG_REG_E1_BIT	    (uint32_t)(2)
#define EF_TMR32_PWM1CFG_REG_E1_MASK	(uint32_t)(0xc)
#define EF_TMR32_PWM1CFG_REG_E2_BIT	    (uint32_t)(4)
#define EF_TMR32_PWM1CFG_REG_E2_MASK	(uint32_t)(0x30)
#define EF_TMR32_PWM1CFG_REG_E3_BIT	    (uint32_t)(6)
#define EF_TMR32_PWM1CFG_REG_E3_MASK	(uint32_t)(0xc0)
#define EF_TMR32_PWM1CFG_REG_E4_BIT	    (uint32_t)(8)
#define EF_TMR32_PWM1CFG_REG_E4_MASK	(uint32_t)(0x300)
#define EF_TMR32_PWM1CFG_REG_E5_BIT	    (uint32_t)(10)
#define EF_TMR32_PWM1CFG_REG_E5_MASK	(uint32_t)(0xc00)

#define EF_TMR32_TO_FLAG	            ((uint32_t)0x1)
#define EF_TMR32_MX_FLAG	            ((uint32_t)0x2)
#define EF_TMR32_MY_FLAG	            ((uint32_t)0x4)

typedef struct _EF_TMR32_TYPE_ {
	__R 	TMR;
	__W 	RELOAD;
	__W 	PR;
	__W 	CMPX;
	__W 	CMPY;
	__W 	CTRL;
	__W 	CFG;
	__W 	PWM0CFG;
	__W 	PWM1CFG;
	__W 	PWMDT;
	__W 	PWMFC;
	__R 	reserved_0[16309];
	__RW	IM;
	__R 	MIS;
	__R 	RIS;
	__W 	IC;
	__W 	GCLK;
} EF_TMR32_TYPE;


typedef EF_TMR32_TYPE* EF_TMR32_TYPE_PTR;


#endif

