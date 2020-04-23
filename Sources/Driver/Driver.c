/*
 * Driver.c
 *
 *  Created on: 2020年4月7日
 *      Author: Master.HE
 */
#include "Driver.h"

void Driver_Init(void)
{
	CLK_Init();

	Tick_Init();

	IWDG_Init();

	PWM_Init();

	ADC_Config();
}
