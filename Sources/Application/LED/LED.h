/*
 * LED.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef LED_H_
#define LED_H_

#include "Config.h"

#if defined(__TX__)
#define LED_PIN Tx_LED_PIN
#elif defined(__RX__)
#define LED_PIN Rx_LED_PIN
#else
#error "未选择"
#endif



void LED_ON(void);
void LED_OFF(void);



#endif /* LED_H_ */
