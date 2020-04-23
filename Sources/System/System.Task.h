/*
 * System.Task.h
 *
 *  Created on: 2018年11月23日
 *      Author: Master.HE
 */

#ifndef SOURCES_SYSTEM_SYSTEM_TASK_H_
#define SOURCES_SYSTEM_SYSTEM_TASK_H_

#include <stdint.h>
//#include "System.Struct.h"

//extern System_Type System;
void System_Tick_Init(void);
void System_Tick_IRQ(void);
uint32_t System_GET_Time_1MS(void);
void System_Task(void);
void DelayMs(uint16_t x);

#endif /* SOURCES_SYSTEM_SYSTEM_TASK_H_ */
