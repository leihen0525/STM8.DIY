/*
 * RF.LT8920.Struct.h
 *
 *  Created on: 2020年4月18日
 *      Author: Master.HE
 */

#ifndef RF_LT8920_STRUCT_H_
#define RF_LT8920_STRUCT_H_

#include <stdint.h>

typedef struct
{
	uint8_t Index;
	uint16_t DATA;

}RF_LT8920_Register_Init_Type;

typedef union
{
	uint16_t Data;
	struct
	{
		uint16_t RF_PLL_CH_NO	:7;

		uint16_t RX_EN			:1;
		uint16_t TX_EN			:1;

		uint16_t 				:7;
	};
}RF_LT8920_Register_7_Type;

typedef union
{
	uint16_t Data;
	struct
	{
		uint16_t CRC_INITIAL_DATA	:8;

		uint16_t					:2;
		uint16_t PKT_FIFO_POLARITY	:1;
		uint16_t AUTO_ACK			:1;
		uint16_t FW_TERM_TX			:1;
		uint16_t PACK_LENGTH_EN		:1;
		uint16_t					:1;
		uint16_t CRC_ON				:1;
	};
}RF_LT8920_Register_41_Type;

typedef union
{
	uint16_t Data;
	struct
	{
		uint16_t				:5;
		uint16_t FIFO_FLAG		:1;
		uint16_t PKT_FLAG		:1;
		uint16_t SYNCWORD_RECV	:1;

		uint16_t FRAMER_ST		:6;
		uint16_t FEC23_ERROR	:1;
		uint16_t CRC_ERROR		:1;
	};
}RF_LT8920_Register_48_Type;

typedef union
{
	uint16_t Data;
	struct
	{
		uint16_t FIFO_RD_PTR	:6;
		uint16_t				:1;
		uint16_t CLR_R_PTR		:1;


		uint16_t FIFO_WR_PTR	:6;
		uint16_t				:1;
		uint16_t CLR_W_PTR		:1;
	};
}RF_LT8920_Register_52_Type;

typedef struct
{
	uint8_t Status;
	uint8_t Status_Sub;
	int16_t TimeOut_Sub;
	int16_t TimeOut_DATA;
	int16_t TimeOut_Wait_TX;
	int16_t TimeOut_Default;
	int16_t TimeOut_Init;
	uint8_t RF_PLL_CH_NO		:7;

}RF_LT8920_DATA_Type;

#endif /* RF_LT8920_STRUCT_H_ */
