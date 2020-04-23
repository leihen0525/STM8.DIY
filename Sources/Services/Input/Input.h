/*
 * Input.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "Driver/Driver.h"

void Input_Init(void);
void Input_Task_10MS(void);
uint8_t Input_GET_DATA(uint8_t CH);


#endif /* INPUT_H_ */
