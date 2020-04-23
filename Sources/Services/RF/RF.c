/*
 * RF.c
 *
 *  Created on: 2020年4月18日
 *      Author: Master.HE
 */
#include "RF.h"

void RF_Init(void)
{
#if defined(__RF_LT8920__)
	RF_LT8920_Init();
#elif defined(__RF_NRF24L01P__)
	RF_NRF24L01P_Init();
#endif
}

void RF_Task_1MS(void)
{
#if defined(__RF_LT8920__)
	RF_LT8920_1MS();
#elif defined(__RF_NRF24L01P__)
#endif
}
void RF_Task_10MS(void)
{
#if defined(__RF_LT8920__)
	RF_LT8920_10MS();
#elif defined(__RF_NRF24L01P__)
#endif
}
