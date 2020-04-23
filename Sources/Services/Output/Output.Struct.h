/*
 * Output.Struct.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef OUTPUT_STRUCT_H_
#define OUTPUT_STRUCT_H_

#include <stdint.h>

typedef struct
{
	uint8_t Enabled;

	uint8_t Type;			//口类型
	uint16_t Default;
	uint8_t Active;

	uint8_t GPIOx;
	uint8_t BIT_CH;
	uint8_t Push_Pull;

}Output_Config_Type;


typedef struct
{

	uint16_t Logic_Data;
	uint16_t Physics_Data;

}Output_DATA_Type;

#endif /* OUTPUT_STRUCT_H_ */
