/*
 * RF.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef RF_H_
#define RF_H_

#if defined(__RF_LT8920__)
#include "RF.LT8920/RF.LT8920.h"
#elif defined(__RF_NRF24L01P__)
#include "RF.NRF24L01P/RF.NRF24L01P.h"
#else
#error "RF Chip No Find"
#endif

void RF_Init(void);
void RF_Task_1MS(void);
void RF_Task_10MS(void);

#endif /* RF_H_ */
