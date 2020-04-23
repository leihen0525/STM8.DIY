/*
 * Output.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Driver/Driver.h"

void Output_Init(void);
static uint16_t Output_IO_Logic_To_Physics(uint16_t Logic_Data,uint16_t Active);
bool Output_SET_DATA(uint8_t Output_CH,uint16_t Logic_DATA);

#endif /* OUTPUT_H_ */
