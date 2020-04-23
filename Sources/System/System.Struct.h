/*
 * System.Struct.h
 *
 *  Created on: 2018年11月23日
 *      Author: Master.HE
 */

#ifndef SOURCES_SYSTEM_SYSTEM_STRUCT_H_
#define SOURCES_SYSTEM_SYSTEM_STRUCT_H_

#include <stdint.h>

typedef struct
{

	uint8_t Tick_1MS;
	uint8_t Tick_10MS;

	uint32_t Time_1MS;
}System_Type;

#endif /* SOURCES_SYSTEM_SYSTEM_STRUCT_H_ */
