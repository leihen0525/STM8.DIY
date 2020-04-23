/*
 * System.Init.c
 *
 *  Created on: 2018年11月23日
 *      Author: Master.HE
 */
#include "System.Init.h"
#include "System.Task.h"
#include "Driver/Driver.h"
#include "Services/Services.h"
#include "Application/Application.h"

void System_Init(void)
{
	System_Tick_Init();

	Driver_Init();

	Services_Init();

	Application_Init();
}
