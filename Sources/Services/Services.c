/*
 * Services.c
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */
#include "Services.h"

void Services_Init(void)
{
	Input_Init();

	Output_Init();

	RF_Init();

}
void Services_Task_1MS(void)
{
	RF_Task_1MS();
}


void Services_Task_10MS(void)
{
	Input_Task_10MS();
	RF_Task_10MS();


#if defined(__TX__)

#endif
}
