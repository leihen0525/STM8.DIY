/*
 * Config.c
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */
#include "Config.h"
#include "Driver/Driver.h"

#include "Services/Input/Input.Enum.h"
#include "Services/Input/Input.Struct.h"

#include "Services/Output/Output.Enum.h"
#include "Services/Output/Output.Struct.h"

#include "Application/Control/Control.Enum.h"
#include "Application/Control/Control.Struct.h"

#include "Application/Servos/Servos.Enum.h"
#include "Application/Servos/Servos.Struct.h"

const Input_Config_Type Input_CH_Config[Input_CH_End]=
{
//		Enabled		Type				Default		Active		GPIOx		BIT_AIN		Pull_Up		AIN_IO_Min		AIN_IO_Max

	//Input_CH_NULL
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},
//-----------------------------------------------------------------------------------------------------------------------------
#if defined(__TX__)
	//Input_CH_K1_Up
	{	Enable,		Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_B,		BIT3,		true,		0,				0	},
	//Input_CH_K1_Down,
	{	Enable,		Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_C,		BIT5,		true,		0,				0	},

	//Input_CH_K2_Up,
	{	Enable,		Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_B,		BIT1,		true,		0,				0	},
	//Input_CH_K2_Down,
	{	Enable,		Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_B,		BIT0,		true,		0,				0	},

	//Input_CH_K3_Up,
	{	Enable,		Inputs_Type_AIN_IO,	IO_OFF,		PIN_LOW,	AIN_ADC1,	AIN16,		true,		0,				100	},
	//Input_CH_K3_Down,
	{	Enable,		Inputs_Type_AIN_IO,	IO_OFF,		PIN_LOW,	AIN_ADC1,	AIN16,		true,		155,			255	},

	//Input_CH_K4_Up,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},
	//Input_CH_K4_Down,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},

	//Input_CH_K5_Up,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},
	//Input_CH_K5_Down,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},

	//Input_CH_K6_Up,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},
	//Input_CH_K6_Down,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},

	//Input_CH_K7_Up,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},
	//Input_CH_K7_Down,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},

	//Input_CH_K8_Up,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},
	//Input_CH_K8_Down,
	{	Disable,	Inputs_Type_MCU_IO,	IO_OFF,		PIN_LOW,	GPIO_A,		BIT0,		true,		0,				0	},

	//Input_CH_Rocker1_X,
	{	Disable,	Inputs_Type_AIN_AD,	128,		0,			AIN_ADC1,	AIN0,		false,		0,				0	},
	//Input_CH_Rocker1_Y,
	{	Disable,	Inputs_Type_AIN_AD,	128,		0,			AIN_ADC1,	AIN16,		false,		0,				0	},

	//Input_CH_Rocker2_X,
	{	Enable,		Inputs_Type_AIN_AD,	128,		0,			AIN_ADC1,	AIN22,		false,		0,				0	},
	//Input_CH_Rocker2_Y,
	{	Disable,	Inputs_Type_AIN_AD,	128,		0,			AIN_ADC1,	AIN0,		false,		0,				0	},
#endif
//-----------------------------------------------------------------------------------------------------------------------------
};


const Output_Config_Type Output_CH_Config[Output_CH_End]=
{
//		Enabled		Type				Default		Active		GPIOx		BIT_CH		Push_Pull
	//Output_CH_NULL
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},
//-----------------------------------------------------------------------------------------------------------------------------
#if defined(__TX__)
	//Output_CH_LED
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_C,		BIT4,		true	},
#endif
//-----------------------------------------------------------------------------------------------------------------------------
#if defined(__RX__)
	//Output_CH_LED
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_C,		BIT4,		true	},
//---------------------------------------
	//Output_CH_Motor1_OUT1
	{	Enable,		Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_D,		BIT0,		true	},
	//Output_CH_Motor1_OUT2
	{	Enable,		Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_B,		BIT0,		true	},

	//Output_CH_Motor2_OUT1
	{	Enable,		Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_B,		BIT3,		true	},
	//Output_CH_Motor2_OUT2
	{	Enable,		Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_B,		BIT1,		true	},

	//Output_CH_Motor3_OUT1
	{	Enable,		Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_C,		BIT5,		true	},
	//Output_CH_Motor3_OUT2
	{	Enable,		Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_C,		BIT6,		true	},

	//Output_CH_Motor4_OUT1
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},
	//Output_CH_Motor4_OUT2
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},

	//Output_CH_Motor5_OUT1
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},
	//Output_CH_Motor5_OUT2
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},

	//Output_CH_Motor6_OUT1
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},
	//Output_CH_Motor6_OUT2
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},

	//Output_CH_Motor7_OUT1
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},
	//Output_CH_Motor7_OUT2
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},

	//Output_CH_Motor8_OUT1
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},
	//Output_CH_Motor8_OUT2
	{	Disable,	Output_Type_IO,		IO_OFF,		PIN_HIGH,	GPIO_A,		BIT0,		true	},

	//Output_CH_Servos1
	{	Enable,		Output_Type_PWM,	0,			0,			Timer_2,	Timer_CH_2,	true	},
	//Output_CH_Servos2
	{	Disable,	Output_Type_PWM,	0,			0,			Timer_0,	Timer_CH_0,	true	},
#endif
//-----------------------------------------------------------------------------------------------------------------------------
};

#if defined(__RX__)
const Control_Config_Type Control_CH_Config[Control_CH_End]=
{
	//Control_CH_Motor1
	{
		.Enabled=Enable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K1_Up,		Control_InPut_IO,
			Command_CH_K1_Down,		Control_InPut_IO,
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor1_OUT1,	Control_OutPut_IO,
			Output_CH_Motor1_OUT2,	Control_OutPut_IO,
		},
	},

	//Control_CH_Motor2
	{
		.Enabled=Enable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K2_Up,		Control_InPut_IO,
			Command_CH_K2_Down,		Control_InPut_IO
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor2_OUT1,	Control_OutPut_IO,
			Output_CH_Motor2_OUT2,	Control_OutPut_IO,
		},
	},

	//Control_CH_Motor3
	{
		.Enabled=Enable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K3_Up,		Control_InPut_IO,
			Command_CH_K3_Down,		Control_InPut_IO
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor3_OUT1,	Control_OutPut_IO,
			Output_CH_Motor3_OUT2,	Control_OutPut_IO,
		},
	},

	//Control_CH_Motor4
	{
		.Enabled=Disable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K4_Up,		Control_InPut_IO,
			Command_CH_K4_Down,		Control_InPut_IO
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor4_OUT1,	Control_OutPut_IO,
			Output_CH_Motor4_OUT2,	Control_OutPut_IO,
		},
	},

	//Control_CH_Motor5
	{
		.Enabled=Disable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K5_Up,		Control_InPut_IO,
			Command_CH_K5_Down,		Control_InPut_IO
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor5_OUT1,	Control_OutPut_IO,
			Output_CH_Motor5_OUT2,	Control_OutPut_IO,
		},
	},

	//Control_CH_Motor6
	{
		.Enabled=Disable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K6_Up,		Control_InPut_IO,
			Command_CH_K6_Down,		Control_InPut_IO
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor6_OUT1,	Control_OutPut_IO,
			Output_CH_Motor6_OUT2,	Control_OutPut_IO,
		},
	},

	//Control_CH_Motor7
	{
		.Enabled=Disable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K7_Up,		Control_InPut_IO,
			Command_CH_K7_Down,		Control_InPut_IO
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor7_OUT1,	Control_OutPut_IO,
			Output_CH_Motor7_OUT2,	Control_OutPut_IO,
		},
	},

	//Control_CH_Motor8
	{
		.Enabled=Disable,

		.InPut=
		{
			//Command_CH			Type
			Command_CH_K8_Up,		Control_InPut_IO,
			Command_CH_K8_Down,		Control_InPut_IO
		},

		.OutPut=
		{
			//OutPut_CH				Type
			Output_CH_Motor8_OUT1,	Control_OutPut_IO,
			Output_CH_Motor8_OUT2,	Control_OutPut_IO,
		},
	},
};


const Servos_Config_Type Servos_CH_Config[Servos_CH_End]=
{
//		Enabled		Type					Direction					Angle					Command_CH				OutPut_CH

	//Servos_CH_1
	{	Enable,		Servos_Model_MG996R,	Servos_Direction_Negative,	Servos_Angle_90_Degree,	Command_CH_Rocker2_X,	Output_CH_Servos1},

	//Servos_CH_2
	{	Disable,	Servos_Model_MG996R,	Servos_Direction_Positive,	Servos_Angle_90_Degree,	Command_CH_Rocker2_Y,	Output_CH_Servos2},
};
#endif
