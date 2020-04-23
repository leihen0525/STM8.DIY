/*
 * Control.c
 *
 *  Created on: 2020年4月22日
 *      Author: Master.HE
 */
#include "Config.h"
#include "Driver/Driver.h"
#include "Services/Services.h"
#include "Application/Command/Command.h"
#include "Control.h"

#if defined(__RX__)
extern const Control_Config_Type Control_CH_Config[Control_CH_End];

void Control_Init(void)
{

}

void Control_Task_10MS(void)
{
	for(int i=0;i<Control_CH_End;i++)
	{
		if(Control_CH_Config[i].Enabled==Disable)continue;

		if(Control_CH_Config[i].InPut[0].Type==Control_InPut_IO)
		{
			if(Control_CH_Config[i].OutPut[0].Type==Control_OutPut_IO)
			{
				if(Command_GET_DATA(Control_CH_Config[i].InPut[0].Command_CH)==IO_OFF)
				{
					Output_SET_DATA(Control_CH_Config[i].OutPut[0].OutPut_CH,IO_OFF);
				}
				else
				{
					Output_SET_DATA(Control_CH_Config[i].OutPut[0].OutPut_CH,IO_ON);
				}
			}
			else if(Control_CH_Config[i].OutPut[0].Type==Control_OutPut_PWM)
			{

			}
		}
		else if(Control_CH_Config[i].InPut[0].Type==Control_InPut_AD)
		{

		}

		if(Control_CH_Config[i].InPut[1].Type==Control_InPut_IO)
		{
			if(Control_CH_Config[i].OutPut[1].Type==Control_OutPut_IO)
			{
				if(Command_GET_DATA(Control_CH_Config[i].InPut[1].Command_CH)==IO_OFF)
				{
					Output_SET_DATA(Control_CH_Config[i].OutPut[1].OutPut_CH,IO_OFF);
				}
				else
				{
					Output_SET_DATA(Control_CH_Config[i].OutPut[1].OutPut_CH,IO_ON);
				}
			}
			else if(Control_CH_Config[i].OutPut[1].Type==Control_OutPut_PWM)
			{

			}
		}
		else if(Control_CH_Config[i].InPut[1].Type==Control_InPut_AD)
		{

		}
	}
}


#endif
