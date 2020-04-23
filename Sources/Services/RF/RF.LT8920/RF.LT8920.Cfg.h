/*
 * RF.LT8920.Cfg.h
 *
 *  Created on: 2020年4月18日
 *      Author: Master.HE
 */

#ifndef RF_LT8920_CFG_H_
#define RF_LT8920_CFG_H_

#include "RF.LT8920.Struct.h"

#define RF_LT8920_PIN							GPIO_C,BIT4

#define RF_LT8920_TimeOut_Init					(2000)//

#define RF_LT8920_TimeOut_Wait_TX				(20)//

#define RF_LT8920_TimeOut_Default				(1250)//

#define RF_LT8920_TimeOut_Wait_RX_DATA			(250)//

#define RF_LT8920_TimeOut_Wait_TX_DATA_Send		(50)//

#define RF_LT8920_TimeOut_DATA					(500)

extern const RF_LT8920_Register_Init_Type RF_LT8920_Register_Init[];

uint8_t RF_LT8920_GET_Init_Len(void);

#endif /* RF_LT8920_CFG_H_ */
