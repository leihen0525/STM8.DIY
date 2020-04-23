/*
 * Services.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef SERVICES_H_
#define SERVICES_H_

#include "Config.h"

#include "Input/Input.h"
#include "Output/Output.h"
#include "RF/RF.h"


void Services_Init(void);
void Services_Task_1MS(void);
void Services_Task_10MS(void);


#endif /* SERVICES_H_ */
