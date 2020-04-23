/*
 * Servos.c
 *
 *  Created on: 2020年4月22日
 *      Author: Master.HE
 */
#include "Driver/Driver.h"

#include "Config.h"
#include "Application/Command/Command.h"
#include "Services/Services.h"
#include "Servos.h"

#if defined(__RX__)

extern const Servos_Config_Type Servos_CH_Config[Servos_CH_End];

void Servos_Init(void)
{

}

void Servos_Task_10MS(void)
{
	for(int i=0;i<Servos_CH_End;i++)
	{
		if(Servos_CH_Config[i].Enabled==Disable)continue;

		switch (Servos_CH_Config[i].Type)
		{
			case Servos_Model_MG996R:
			{

				uint16_t Temp_OutPut_DATA=Servos_Calculate_MG996R(
												Command_GET_DATA(Servos_CH_Config[i].Command_CH),
												Servos_CH_Config[i].Direction,
												Servos_CH_Config[i].Angle);

				Output_SET_DATA(Servos_CH_Config[i].OutPut_CH,Temp_OutPut_DATA);

			}break;

			default:
			{

			}break;
		}


	}
}

uint16_t Servos_Calculate_MG996R(uint8_t InPut_DATA,Servos_Direction_Type Direction,Servos_Angle_Type Angle)
{
	uint16_t Duty;

	if(Direction==Servos_Direction_Positive)
	{
		Duty = 255 -InPut_DATA;
	}
	else
	{
		Duty = InPut_DATA;
	}

	if(Angle==Servos_Angle_90_Degree)
	{
		Duty = (uint16_t)(125 * Duty) / 128 + 250;
	}
	else
	{
		Duty = (uint16_t)(250 * Duty) / 128 + 125;
	}


	if (Duty < 125)
	{
		Duty = 125;
	}
	else if (Duty>625)
	{
		Duty = 625;
	}

	return Duty;
}


#endif
