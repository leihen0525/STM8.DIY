/*
 * Driver.STM8L15x.h
 *
 *  Created on: 2020年4月7日
 *      Author: Master.HE
 */

#ifndef DRIVER_STM8L15X_H_
#define DRIVER_STM8L15X_H_

#include "stm8l15x.h"
#include "Driver.STM8L15x.Define.h"
#include "Driver/Driver.Enum.h"

void CLK_Init(void);
void Tick_Init(void);
void IWDG_Init(void);
void PWM_Init(void);
bool PWM_SET_Open(Timer_Type Timerx,Timer_CH_Type CH);
bool PWM_SET_Duty(Timer_Type Timerx,Timer_CH_Type CH,uint16_t Duty_X_10);

bool GPIO_SET_DDR(GPIO_Type GPIOx,BIT_Type BIT,IO_DDR_Type DDR,bool Pull_Up_OR_Push_Pull);
bool GPIO_SET_DATA(GPIO_Type GPIOx,BIT_Type BIT,PIN_State_Type PIN_State);
PIN_State_Type GPIO_GET_DATA(GPIO_Type GPIOx,BIT_Type BIT);

void ADC_Config(void);
void DMA_Config(void);
bool ADC_SET_CH(AIN_ADC_Type ADCx,AIN_Type CH);
uint8_t ADC_GET_DATA(AIN_ADC_Type ADCx,AIN_Type CH);
void ADC_Start(void);

void SPI_SET_Init(uint8_t CPOL,uint8_t CPHA);
void SPI_SET_NSS(PIN_State_Type State);
uint8_t SPI_WR_Byte(uint8_t W_DATA);

#endif /* DRIVER_STM8L15X_H_ */
