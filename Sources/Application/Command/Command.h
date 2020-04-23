/*
 * Command.h
 *
 *  Created on: 2020年4月19日
 *      Author: Master.HE
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Config.h"

#include "Command.Struct.h"



void Command_Init(void);

void Command_10MS(void);

#if defined(__RX__)
uint8_t Command_GET_DATA(uint8_t CH);
#endif

#endif /* COMMAND_H_ */
