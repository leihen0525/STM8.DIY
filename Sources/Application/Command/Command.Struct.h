/*
 * Command.Struct.h
 *
 *  Created on: 2020年4月19日
 *      Author: Master.HE
 */

#ifndef COMMAND_STRUCT_H_
#define COMMAND_STRUCT_H_

#include <stdint.h>

typedef union
{
	uint8_t DATA_8Bit[8];
	uint16_t DATA_16Bit[4];

	struct
	{
		struct
		{
			uint8_t K1_Up					:1;
			uint8_t K1_Down					:1;

			uint8_t K2_Up					:1;
			uint8_t K2_Down					:1;

			uint8_t K3_Up					:1;
			uint8_t K3_Down					:1;

			uint8_t K4_Up					:1;
			uint8_t K4_Down					:1;

			uint8_t K5_Up					:1;
			uint8_t K5_Down					:1;

			uint8_t K6_Up					:1;
			uint8_t K6_Down					:1;

			uint8_t K7_Up					:1;
			uint8_t K7_Down					:1;

			uint8_t K8_Up					:1;
			uint8_t K8_Down					:1;

		}KEY;
		//摇杆
		struct
		{
			uint8_t X;
			uint8_t Y;
		}Rocker[2];

	};
}Command_TX_DATA_Type;

typedef union
{
	uint8_t DATA_8Bit[4];
	uint16_t DATA_16Bit[2];

//	struct
//	{
//
//	};
}Command_RX_DATA_Type;

#endif /* COMMAND_STRUCT_H_ */
