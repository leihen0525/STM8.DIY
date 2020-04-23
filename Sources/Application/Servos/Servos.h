/*
 * Servos.h
 *
 *  Created on: 2020年4月22日
 *      Author: Master.HE
 */

#ifndef SERVOS_H_
#define SERVOS_H_

#include "Servos.Enum.h"
#include "Servos.Struct.h"

#if defined(__RX__)

void Servos_Init(void);
void Servos_Task_10MS(void);

uint16_t Servos_Calculate_MG996R(uint8_t InPut_DATA,Servos_Direction_Type Direction,Servos_Angle_Type Angle);

#endif

#endif /* SERVOS_H_ */
