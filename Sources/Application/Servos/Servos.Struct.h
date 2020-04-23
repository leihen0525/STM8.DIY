/*
 * Servos.Struct.h
 *
 *  Created on: 2020年4月23日
 *      Author: Master.HE
 */

#ifndef SERVOS_STRUCT_H_
#define SERVOS_STRUCT_H_

#include <stdint.h>

typedef struct
{
	uint8_t Enabled;

	uint8_t Type;

	uint8_t Direction;

	uint8_t Angle;

	uint8_t Command_CH;

	uint8_t OutPut_CH;

}Servos_Config_Type;

#endif /* SERVOS_STRUCT_H_ */
