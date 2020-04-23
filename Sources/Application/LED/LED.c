/*
 * LED.c
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */
//#include "Driver/Driver.h"
#include "LED.h"

#include "Services/Services.h"

void LED_ON(void)
{
	Output_SET_DATA(Output_CH_LED,IO_ON);
}
void LED_OFF(void)
{
	Output_SET_DATA(Output_CH_LED,IO_OFF);
}

