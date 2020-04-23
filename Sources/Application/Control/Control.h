/*
 * Control.h
 *
 *  Created on: 2020年4月22日
 *      Author: Master.HE
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include "Control.Enum.h"
#include "Control.Struct.h"

#if defined(__RX__)

void Control_Init(void);
void Control_Task_10MS(void);

#endif

#endif /* CONTROL_H_ */
