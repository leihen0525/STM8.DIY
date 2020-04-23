/*
 * Control.Struct.h
 *
 *  Created on: 2020年4月22日
 *      Author: Master.HE
 */

#ifndef CONTROL_STRUCT_H_
#define CONTROL_STRUCT_H_

#include <stdint.h>

typedef struct
{
	uint8_t Enabled;

	struct
	{
		uint8_t Command_CH;
		uint8_t Type;
	}InPut[2];

	struct
	{
		uint8_t OutPut_CH;
		uint8_t Type;
	}OutPut[2];


}Control_Config_Type;

#endif /* CONTROL_STRUCT_H_ */
