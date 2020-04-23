/*
 * Application.c
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */
#include "Application.h"

void Application_Init(void)
{
	Command_Init();

#if defined(__RX__)
	Control_Init();

	Servos_Init();
#endif

}

void Application_10MS(void)
{
	Command_10MS();
#if defined(__RX__)
	Control_Task_10MS();

	Servos_Task_10MS();
#endif

}
