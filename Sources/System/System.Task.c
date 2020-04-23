/*
 * System.Task.c
 *
 *  Created on: 2018年11月23日
 *      Author: Master.HE
 */
#include "System.Struct.h"
#include "System.Task.h"
#include "Driver/Driver.h"
#include "Services/Services.h"
#include "Application/Application.h"



System_Type System;

void System_Tick_Init(void)
{
	System.Tick_1MS=0;
	System.Tick_10MS=0;
	System.Time_1MS=0;
}
void System_Tick_IRQ(void)
{
	System.Tick_1MS++;
	System.Tick_10MS++;
	System.Time_1MS++;
}
uint32_t System_GET_Time_1MS(void)
{
	return System.Time_1MS;
}

void System_Task(void)
{

	while(1)
	{
		if(System.Tick_1MS>=1)
		{
			System.Tick_1MS=System.Tick_1MS-1;

			Services_Task_1MS();
		}

		if(System.Tick_10MS>=10)
		{
			System.Tick_10MS=System.Tick_10MS-10;


			Services_Task_10MS();

			Application_10MS();

		}


		__IWDG_FREE();//喂狗

		//__WAIT();//进入Wait低功耗模式

	}


}

void DelayMs(uint16_t x)
{
	for(uint16_t i=0;i<x;i++)
	{
		for(uint16_t j=0;j<1000;j++)
		{
			__NOP();
		}
	}
}
