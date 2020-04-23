/*
 * Driver.Enum.h
 *
 *  Created on: 2020年4月12日
 *      Author: Master.HE
 */

#ifndef DRIVER_ENUM_H_
#define DRIVER_ENUM_H_

typedef enum
{
	Timer_0				=0,
	Timer_1,
	Timer_2,
	Timer_3,
	Timer_4,
	Timer_5,
	Timer_6,
	Timer_7,
	Timer_8,
	Timer_9,

	Timer_End,
}Timer_Type;

typedef enum
{
	Timer_CH_0			=0,
	Timer_CH_1,
	Timer_CH_2,
	Timer_CH_3,
	Timer_CH_4,
	Timer_CH_5,
	Timer_CH_6,
	Timer_CH_7,
	Timer_CH_8,

	Timer_CH_End,
}Timer_CH_Type;

typedef enum
{
	GPIO_A				=0,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F,
	GPIO_G,
	GPIO_H,
	GPIO_I,

	GPIO_End,
}GPIO_Type;


typedef enum
{
	BIT0=0x01,
	BIT1=0x02,
	BIT2=0x04,
	BIT3=0x08,
	BIT4=0x10,
	BIT5=0x20,
	BIT6=0x40,
	BIT7=0x80,

	BIT_ALL=0xFF,
}BIT_Type;

typedef enum
{
	AIN_ADC0		=0,
	AIN_ADC1,
	AIN_ADC2,
	AIN_ADC3,

	AIN_ADC_End,
}AIN_ADC_Type;

typedef enum
{
	AIN0			=0,
	AIN1,
	AIN2,
	AIN3,
	AIN4,
	AIN5,
	AIN6,
	AIN7,
	AIN8,
	AIN9,
	AIN10,
	AIN11,
	AIN12,
	AIN13,
	AIN14,
	AIN15,
	AIN16,
	AIN17,
	AIN18,
	AIN19,
	AIN20,
	AIN21,
	AIN22,
	AIN23,
	AIN24,
	AIN25,
	AIN26,
	AIN27,
	AIN28,
	AIN29,
	AIN30,

	AIN_End,
}AIN_Type;

typedef enum
{
	IO_DDR_IN=0,
	IO_DDR_OUT,

	IO_DDR_End,
}IO_DDR_Type;

typedef enum	//PIN状态
{
	PIN_LOW=0,
	PIN_HIGH,

	PIN_End,
}PIN_State_Type;

typedef enum
{
	IO_OFF=0,
	IO_ON,

	IO_End,
}IO_Type;

#endif /* DRIVER_ENUM_H_ */
