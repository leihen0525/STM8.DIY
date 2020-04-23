/*
 * RF.LT8920.Enum.h
 *
 *  Created on: 2020年4月19日
 *      Author: Master.HE
 */

#ifndef RF_LT8920_ENUM_H_
#define RF_LT8920_ENUM_H_

typedef enum
{
	RF_LT8920_Mode_Idle				=0,
	RF_LT8920_Mode_TX,
	RF_LT8920_Mode_RX,

	RF_LT8920_Mode_End,
}RF_LT8920_Mode_Type;

typedef enum
{
	RF_LT8920_Baud_Rate_1Mbps			=0x0100,
	RF_LT8920_Baud_Rate_250Kbps			=0x0400,
	RF_LT8920_Baud_Rate_125Kbps			=0x0800,
	RF_LT8920_Baud_Rate_62500bps		=0x1000,
}RF_LT8920_Baud_Rate_Type;

typedef enum
{
	RF_LT8920_Status_Init,

	RF_LT8920_Status_Wait_TX,
	RF_LT8920_Status_TX_DATA,
	RF_LT8920_Status_TX_Wait_Finish,
	RF_LT8920_Status_TX_Change_Channel,

	RF_LT8920_Status_RX_DATA,
	RF_LT8920_Status_RX_Wait_DATA,
	RF_LT8920_Status_RX_Change_Channel,

}RF_LT8920_Status_Type;

typedef enum
{
	RF_LT8920_Status_Init_RST_LOW,
	RF_LT8920_Status_Init_RST_TimeOut,
	RF_LT8920_Status_Init_RST_High,
	RF_LT8920_Status_Init_RST_TimeOut1,

	RF_LT8920_Status_Init_Register,
	RF_LT8920_Status_Init_SET,

	RF_LT8920_Status_Init_DATA,
}RF_LT8920_Status_Init_Type;

#endif /* RF_LT8920_ENUM_H_ */
