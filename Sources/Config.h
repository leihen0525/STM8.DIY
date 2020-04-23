/*
 * Config.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define MCU_RF_ID	(1210)			//ID范围：1-65535 一对遥控器加车一个共同的号


typedef enum
{
	Input_CH_NULL							=0,

#if defined(__TX__)
	//按键
	Input_CH_K1_Up,
	Input_CH_K1_Down,

	Input_CH_K2_Up,
	Input_CH_K2_Down,

	Input_CH_K3_Up,
	Input_CH_K3_Down,

	Input_CH_K4_Up,
	Input_CH_K4_Down,

	Input_CH_K5_Up,
	Input_CH_K5_Down,

	Input_CH_K6_Up,
	Input_CH_K6_Down,

	Input_CH_K7_Up,
	Input_CH_K7_Down,

	Input_CH_K8_Up,
	Input_CH_K8_Down,

	//摇杆
	Input_CH_Rocker1_X,
	Input_CH_Rocker1_Y,

	Input_CH_Rocker2_X,
	Input_CH_Rocker2_Y,
#endif

	//
	Input_CH_End,
}Input_CH_Type;

typedef enum
{
	Output_CH_NULL							=0,

#if defined(__TX__)
	Output_CH_LED,
#endif
#if defined(__RX__)
	Output_CH_LED,

//-----------------------------------
	Output_CH_Motor1_OUT1,
	Output_CH_Motor1_OUT2,

	Output_CH_Motor2_OUT1,
	Output_CH_Motor2_OUT2,

	Output_CH_Motor3_OUT1,
	Output_CH_Motor3_OUT2,

	Output_CH_Motor4_OUT1,
	Output_CH_Motor4_OUT2,

	Output_CH_Motor5_OUT1,
	Output_CH_Motor5_OUT2,

	Output_CH_Motor6_OUT1,
	Output_CH_Motor6_OUT2,

	Output_CH_Motor7_OUT1,
	Output_CH_Motor7_OUT2,

	Output_CH_Motor8_OUT1,
	Output_CH_Motor8_OUT2,

	Output_CH_Servos1,
	Output_CH_Servos2,

#endif

	Output_CH_End,
}Output_CH_Type;


#if defined(__RX__)
typedef enum
{
	//按键
	Command_CH_K1_Up					=0,
	Command_CH_K1_Down,

	Command_CH_K2_Up,
	Command_CH_K2_Down,

	Command_CH_K3_Up,
	Command_CH_K3_Down,

	Command_CH_K4_Up,
	Command_CH_K4_Down,

	Command_CH_K5_Up,
	Command_CH_K5_Down,

	Command_CH_K6_Up,
	Command_CH_K6_Down,

	Command_CH_K7_Up,
	Command_CH_K7_Down,

	Command_CH_K8_Up,
	Command_CH_K8_Down,

	//摇杆
	Command_CH_Rocker1_X,
	Command_CH_Rocker1_Y,

	Command_CH_Rocker2_X,
	Command_CH_Rocker2_Y,


	Command_CH_End,
}Command_CH_Type;

typedef enum
{
	Control_CH_Motor1					=0,
	Control_CH_Motor2,
	Control_CH_Motor3,
	Control_CH_Motor4,
	Control_CH_Motor5,
	Control_CH_Motor6,
	Control_CH_Motor7,
	Control_CH_Motor8,

	Control_CH_End,
}Control_CH_Type;

typedef enum
{
	Servos_CH_1							=0,
	Servos_CH_2,

	Servos_CH_End,
}Servos_CH_Type;

#endif

#endif /* CONFIG_H_ */
