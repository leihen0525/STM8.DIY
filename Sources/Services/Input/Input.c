/*
 * Input.c
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */
#include "Config.h"
#include "Input.Define.h"
#include "Input.Enum.h"
#include "Input.Struct.h"
#include "Input.h"

extern const Input_Config_Type Input_CH_Config[Input_CH_End];

Input_DATA_Type Input_DATA_CH[Input_CH_End];

void Input_Init(void)
{
	int ADC_Index=0;
	for(int i=0;i<Input_CH_End;i++)
	{
		Input_DATA_CH[i].Logic_Data=Input_CH_Config[i].Default;

		if(Input_CH_Config[i].Enabled==Disable)continue;

		switch(Input_CH_Config[i].Type)
		{
			case Inputs_Type_MCU_IO:
			{
				GPIO_SET_DDR(Input_CH_Config[i].GPIOx,Input_CH_Config[i].BIT_AIN,IO_DDR_IN,Input_CH_Config[i].Pull_Up);

				if(Input_CH_Config[i].Default==IO_ON)
				{
					if(Input_CH_Config[i].Active==PIN_HIGH)
					{
						Input_DATA_CH[i].Temp_Data=PIN_HIGH;
					}
					else
					{
						Input_DATA_CH[i].Temp_Data=PIN_LOW;
					}
				}
				else//IO_OFF
				{
					if(Input_CH_Config[i].Active==PIN_HIGH)
					{
						Input_DATA_CH[i].Temp_Data=PIN_LOW;
					}
					else
					{
						Input_DATA_CH[i].Temp_Data=PIN_HIGH;
					}
				}

			}break;

			case Inputs_Type_AIN_AD:
			{
				ADC_SET_CH(Input_CH_Config[i].GPIOx,Input_CH_Config[i].BIT_AIN);
				ADC_Index++;
				Input_DATA_CH[i].Temp_Data=Input_CH_Config[i].Default;
			}break;

			case Inputs_Type_AIN_IO:
			{
				ADC_SET_CH(Input_CH_Config[i].GPIOx,Input_CH_Config[i].BIT_AIN);
				ADC_Index++;
				Input_DATA_CH[i].Temp_Data=Input_CH_Config[i].Default;
			}break;
		}

		Input_DATA_CH[i].Physics_Data=Input_DATA_CH[i].Temp_Data;
		Input_DATA_CH[i].Time_CheckOut=-1;

		Input_DATA_CH[i].AD_Temp[0]=0;
		Input_DATA_CH[i].AD_Temp[1]=0;
		Input_DATA_CH[i].AD_Temp[2]=0;
		Input_DATA_CH[i].AD_Temp[3]=0;

	}
	if(ADC_Index!=0)
	{
		ADC_Start();
	}
}


void Input_Task_10MS(void)
{
	uint8_t Temp_Data=0;

	for(int i=0;i<Input_CH_End;i++)
	{
		if(Input_CH_Config[i].Enabled==Disable)continue;

		switch(Input_CH_Config[i].Type)
		{
			case Inputs_Type_MCU_IO:
			{
				Temp_Data=GPIO_GET_DATA(Input_CH_Config[i].GPIOx,Input_CH_Config[i].BIT_AIN);

				if(Input_DATA_CH[i].Temp_Data!=Temp_Data)
				{
					Input_DATA_CH[i].Temp_Data=Temp_Data;
					Input_DATA_CH[i].Time_CheckOut=Inputs_Time_CheckOut;
				}

				if(Input_DATA_CH[i].Time_CheckOut>0)
				{
					Input_DATA_CH[i].Time_CheckOut--;

					if(Input_DATA_CH[i].Time_CheckOut==0)
					{
						Input_DATA_CH[i].Time_CheckOut=-1;

						Input_DATA_CH[i].Physics_Data=Input_DATA_CH[i].Temp_Data;

						if(Input_CH_Config[i].Active==PIN_LOW)
						{
							if(Input_DATA_CH[i].Physics_Data==PIN_LOW)
							{
								Input_DATA_CH[i].Logic_Data=IO_ON;
							}
							else
							{
								Input_DATA_CH[i].Logic_Data=IO_OFF;
							}
						}
						else//PIN_HIGH
						{
							if(Input_DATA_CH[i].Physics_Data==PIN_LOW)
							{
								Input_DATA_CH[i].Logic_Data=IO_OFF;
							}
							else
							{
								Input_DATA_CH[i].Logic_Data=IO_ON;
							}
						}
					}
				}
			}break;

			case Inputs_Type_AIN_AD:
			case Inputs_Type_AIN_IO:
			{
				Temp_Data=ADC_GET_DATA(Input_CH_Config[i].GPIOx,Input_CH_Config[i].BIT_AIN);

				//AD 采用平均数滤波
				Input_DATA_CH[i].AD_Temp[0]=Input_DATA_CH[i].AD_Temp[1];
				Input_DATA_CH[i].AD_Temp[1]=Input_DATA_CH[i].AD_Temp[2];
				Input_DATA_CH[i].AD_Temp[2]=Input_DATA_CH[i].AD_Temp[3];
				Input_DATA_CH[i].AD_Temp[3]=Temp_Data;


				uint16_t AD_Temp=Input_DATA_CH[i].AD_Temp[0]
								+Input_DATA_CH[i].AD_Temp[1]
								+Input_DATA_CH[i].AD_Temp[2]
								+Input_DATA_CH[i].AD_Temp[3];

				Temp_Data=(AD_Temp>>2)&0xFF;

				if(Input_DATA_CH[i].Temp_Data!=Temp_Data)
				{
					Input_DATA_CH[i].Temp_Data=Temp_Data;

					if(Input_CH_Config[i].Type==Inputs_Type_AIN_AD)
					{
						Input_DATA_CH[i].Physics_Data=Temp_Data;
						Input_DATA_CH[i].Logic_Data=Temp_Data;

						Input_DATA_CH[i].Time_CheckOut=-1;
					}
					else if(Input_CH_Config[i].Type==Inputs_Type_AIN_IO)
					{
						uint8_t Temp_Physics_Data;
						if(Input_CH_Config[i].AIN_IO_Min<=Input_DATA_CH[i].Temp_Data && Input_DATA_CH[i].Temp_Data<=Input_CH_Config[i].AIN_IO_Max)
						{
							Temp_Physics_Data=IO_ON;
						}
						else
						{
							Temp_Physics_Data=IO_OFF;
						}

						if(Input_DATA_CH[i].Physics_Data!=Temp_Physics_Data)
						{
							Input_DATA_CH[i].Physics_Data=Temp_Physics_Data;
							Input_DATA_CH[i].Time_CheckOut=Inputs_Time_CheckOut;
						}


					}

				}
				if(Input_DATA_CH[i].Time_CheckOut>0)
				{
					Input_DATA_CH[i].Time_CheckOut--;

					if(Input_DATA_CH[i].Time_CheckOut==0)
					{
						Input_DATA_CH[i].Time_CheckOut=-1;

						if(Input_DATA_CH[i].Physics_Data==IO_OFF)
						{
							Input_DATA_CH[i].Logic_Data=IO_OFF;
						}
						else
						{
							Input_DATA_CH[i].Logic_Data=IO_ON;
						}
					}
				}

			}break;
		}


	}
}

uint8_t Input_GET_DATA(uint8_t CH)
{
	if(CH>=Input_CH_End)
	{
		return 0;
	}
	return Input_DATA_CH[CH].Logic_Data;
}
