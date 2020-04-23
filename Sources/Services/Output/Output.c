/*
 * Output.c
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */
#include "Config.h"
#include "Output.Enum.h"
#include "Output.Struct.h"
#include "Output.h"



extern const Output_Config_Type Output_CH_Config[Output_CH_End];

Output_DATA_Type Output_DATA_CH[Output_CH_End];

void Output_Init(void)
{
	for(int i=0;i<Output_CH_End;i++)
	{
		if(Output_CH_Config[i].Enabled==Disable)continue;



		switch(Output_CH_Config[i].Type)
		{
			case Output_Type_IO:
			{

				GPIO_SET_DDR(Output_CH_Config[i].GPIOx,Output_CH_Config[i].BIT_CH,IO_DDR_OUT,Output_CH_Config[i].Push_Pull);


				Output_SET_DATA(i,Output_CH_Config[i].Default);

			}break;

			case Output_Type_PWM:
			{
				PWM_SET_Open(Output_CH_Config[i].GPIOx,Output_CH_Config[i].BIT_CH);

			}break;
		}
	}
}
static uint16_t Output_IO_Logic_To_Physics(uint16_t Logic_Data,uint16_t Active)
{
	if(Logic_Data==IO_OFF)
	{
		if(Active==PIN_LOW)
		{
			return PIN_HIGH;
		}
		else
		{
			return PIN_LOW;
		}
	}
	else
	{
		if(Active==PIN_LOW)
		{
			return PIN_LOW;
		}
		else
		{
			return PIN_HIGH;
		}
	}
}

bool Output_SET_DATA(uint8_t Output_CH,uint16_t Logic_DATA)
{
	if(Output_CH>=Output_CH_End)
	{
		return false;
	}

	if(Output_CH_Config[Output_CH].Enabled==Disable)
	{
		return false;
	}
	Output_DATA_CH[Output_CH].Logic_Data=Logic_DATA;

	switch(Output_CH_Config[Output_CH].Type)
	{
		case Output_Type_IO:
		{

			Output_DATA_CH[Output_CH].Physics_Data=Output_IO_Logic_To_Physics(
														Output_DATA_CH[Output_CH].Logic_Data,
														Output_CH_Config[Output_CH].Active);

			return GPIO_SET_DATA(Output_CH_Config[Output_CH].GPIOx,Output_CH_Config[Output_CH].BIT_CH,Output_DATA_CH[Output_CH].Physics_Data);

		}break;

		case Output_Type_PWM:
		{
			Output_DATA_CH[Output_CH].Physics_Data=Logic_DATA;
			Output_DATA_CH[Output_CH].Logic_Data=Logic_DATA;

			return PWM_SET_Duty(Output_CH_Config[Output_CH].GPIOx,Output_CH_Config[Output_CH].BIT_CH,Output_DATA_CH[Output_CH].Physics_Data);


		}break;
	}
	return false;
}
