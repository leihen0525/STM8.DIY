/*
 * Driver.STM8L15x.c
 *
 *  Created on: 2020年4月7日
 *      Author: Master.HE
 */
#include "Driver.STM8L15x.h"

void CLK_Init(void)
{

	CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);


	CLK_SYSCLKSourceSwitchCmd(ENABLE);
	CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);

	while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_HSI)
	{

	}

}

//#define TIM4_PERIOD       124

void Tick_Init(void)//1MS
{
	/* TIM4 configuration:
	- TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
	clock used is 16 MHz / 128 = 125 000 Hz
	- With 125 000 Hz we can generate time base:
	  max time base is 2.048 ms if TIM4_PERIOD = 255 --> (255 + 1) / 125000 = 2.048 ms
	  min time base is 0.016 ms if TIM4_PERIOD = 1   --> (  1 + 1) / 125000 = 0.016 ms
	- In this example we need to generate a time base equal to 1 ms
	so TIM4_PERIOD = (0.001 * 125000 - 1) = 124 */

	CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);

	/* Time base configuration */
	TIM4_TimeBaseInit(TIM4_Prescaler_128, 124);

	/* Clear TIM4 update flag */
	TIM4_ClearFlag(TIM4_FLAG_Update);

	/* Enable update interrupt */
	TIM4_ITConfig(TIM4_IT_Update, ENABLE);

	/* Enable TIM4 */
	TIM4_Cmd(ENABLE);
}

void IWDG_Init(void)
{
	/* IWDG configuration: IWDG is clocked by LSI = 38KHz */

	/* IWDG timeout equal to 214.7 ms (the timeout may varies due to LSI frequency dispersion) */

	/* IWDG timeout = (RELOAD_VALUE + 1) * Prescaler / LSI = (254 + 1) * 32 / 38 000 = 214.7 ms */

	/* Enable the IWDG */

	IWDG_Enable();

	/* Enable write access to IWDG_PR and IWDG_RLR registers */

	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);

	/* Set IWDG timeout */

	IWDG_SetPrescaler(IWDG_Prescaler_32);

	IWDG_SetReload(254);

	/* Refresh IWDG */

	IWDG_ReloadCounter();



	/* enable interrupts by switching to level 0 */
}
#define FREQUENCY_VALUE          5000   //26us为一个周期
void PWM_Init(void)
{
	//2
	//时钟配置
	CLK_PeripheralClockConfig(CLK_Peripheral_TIM2,ENABLE);

	//配置
	TIM2_DeInit();                                                                                                //复位
	TIM2_TimeBaseInit(TIM2_Prescaler_64, TIM2_CounterMode_Up, FREQUENCY_VALUE);                     //每26us定时重新计数一次，38K
	//TIM2_OC1Init(TIM2_OCMode_PWM2, TIM2_OutputState_Enable, 0, TIM2_OCPolarity_Low, TIM2_OCIdleState_Reset);     //先空闲后运行的模式、输出使能、占空比初始化为0、运行时为高、死区时为低
	//TIM2_OC2Init(TIM2_OCMode_PWM2, TIM2_OutputState_Enable, 0, TIM2_OCPolarity_Low, TIM2_OCIdleState_Reset);     //先空闲后运行的模式、输出使能、占空比初始化为0、运行时为高、死区时为低
	TIM2_Cmd(ENABLE);
	TIM2_CtrlPWMOutputs(ENABLE);

	//3
	//时钟配置
	CLK_PeripheralClockConfig(CLK_Peripheral_TIM3,ENABLE);

	//配置
	TIM3_DeInit();                                                                                                //复位
	TIM3_TimeBaseInit(TIM3_Prescaler_16, TIM3_CounterMode_Up, FREQUENCY_VALUE);                     //每26us定时重新计数一次，38K
	//TIM3_OC1Init(TIM3_OCMode_PWM2, TIM3_OutputState_Enable, 0, TIM3_OCPolarity_Low, TIM3_OCIdleState_Reset);     //先空闲后运行的模式、输出使能、占空比初始化为0、运行时为高、死区时为低
	//TIM3_OC2Init(TIM3_OCMode_PWM2, TIM3_OutputState_Enable, 0, TIM3_OCPolarity_Low, TIM3_OCIdleState_Reset);     //先空闲后运行的模式、输出使能、占空比初始化为0、运行时为高、死区时为低
	TIM3_Cmd(ENABLE);
	TIM3_CtrlPWMOutputs(ENABLE);

}

bool PWM_SET_Open(Timer_Type Timerx,Timer_CH_Type CH)
{
	switch (Timerx)
	{
		case Timer_2:
		{
			switch (CH)
			{
				case Timer_CH_1:
				{
					TIM2_OC1Init(TIM2_OCMode_PWM2, TIM2_OutputState_Enable, 0, TIM2_OCPolarity_Low, TIM2_OCIdleState_Reset);
					GPIO_Init(GPIOB,GPIO_Pin_0, GPIO_Mode_Out_PP_High_Fast);
					return true;
				}break;
				case Timer_CH_2:
				{
					TIM2_OC2Init(TIM2_OCMode_PWM2, TIM2_OutputState_Enable, 0, TIM2_OCPolarity_Low, TIM2_OCIdleState_Reset);
					GPIO_Init(GPIOB,GPIO_Pin_2, GPIO_Mode_Out_PP_High_Fast);
					return true;
				}break;
			}
		}break;
		case Timer_3:
		{
			switch (CH)
			{
				case Timer_CH_1:
				{
					TIM3_OC1Init(TIM3_OCMode_PWM2, TIM3_OutputState_Enable, 0, TIM3_OCPolarity_Low, TIM3_OCIdleState_Reset);
					GPIO_Init(GPIOB,GPIO_Pin_1, GPIO_Mode_Out_PP_High_Fast);
					return true;
				}break;
				case Timer_CH_2:
				{
					TIM3_OC2Init(TIM3_OCMode_PWM2, TIM3_OutputState_Enable, 0, TIM3_OCPolarity_Low, TIM3_OCIdleState_Reset);
					GPIO_Init(GPIOD,GPIO_Pin_0, GPIO_Mode_Out_PP_High_Fast);
					return true;
				}break;
			}
		}break;
	}
	return false;
}
bool PWM_SET_Duty(Timer_Type Timerx,Timer_CH_Type CH,uint16_t Duty_X_10)
{
	switch (Timerx)
	{
		case Timer_2:
		{
			switch (CH)
			{
				case Timer_CH_1:
				{
					TIM2_SetCompare1(Duty_X_10);
					return true;
				}break;
				case Timer_CH_2:
				{
					TIM2_SetCompare2(Duty_X_10);
					return true;
				}break;
			}
		}break;
		case Timer_3:
		{
			switch (CH)
			{
				case Timer_CH_1:
				{
					TIM3_SetCompare1(Duty_X_10);
					return true;
				}break;
				case Timer_CH_2:
				{
					TIM3_SetCompare2(Duty_X_10);
					return true;
				}break;
			}
		}break;
	}
	return false;
}
/*
	switch (Timerx)
	{
		case Timer_0:
		{
			switch (CH)
			{
				case Timer_CH_0:
				{

				}break;
				case Timer_CH_1:
				{

				}break;
				case Timer_CH_2:
				{

				}break;
				case Timer_CH_3:
				{

				}break;
				case Timer_CH_4:
				{

				}break;
				case Timer_CH_5:
				{

				}break;
				case Timer_CH_6:
				{

				}break;
				case Timer_CH_7:
				{

				}break;
				case Timer_CH_8:
				{

				}break;

				default:
				{

				}break;
			}
		}break;
		case Timer_1:
		{

		}break;
		case Timer_2:
		{
			switch (CH)
			{
				case Timer_CH_0:
				{

				}break;
				case Timer_CH_1:
				{

				}break;
				case Timer_CH_2:
				{

				}break;
				case Timer_CH_3:
				{

				}break;
				case Timer_CH_4:
				{

				}break;
				case Timer_CH_5:
				{

				}break;
				case Timer_CH_6:
				{

				}break;
				case Timer_CH_7:
				{

				}break;
				case Timer_CH_8:
				{

				}break;

				default:
				{

				}break;
			}
		}break;
		case Timer_3:
		{
			switch (CH)
			{
				case Timer_CH_0:
				{

				}break;
				case Timer_CH_1:
				{

				}break;
				case Timer_CH_2:
				{

				}break;
				case Timer_CH_3:
				{

				}break;
				case Timer_CH_4:
				{

				}break;
				case Timer_CH_5:
				{

				}break;
				case Timer_CH_6:
				{

				}break;
				case Timer_CH_7:
				{

				}break;
				case Timer_CH_8:
				{

				}break;

				default:
				{

				}break;
			}
		}break;
		case Timer_4:
		{

		}break;
		case Timer_5:
		{

		}break;
		case Timer_6:
		{

		}break;
		case Timer_7:
		{

		}break;
		case Timer_8:
		{

		}break;
		case Timer_9:
		{

		}break;

		default:
		{

		}break;
	}
 */
bool GPIO_SET_DDR(GPIO_Type GPIOx,BIT_Type BIT,IO_DDR_Type DDR,bool Pull_Up_OR_Push_Pull)
{
	if(GPIOx>=GPIO_End || BIT>BIT_ALL || DDR>=IO_DDR_End || Pull_Up_OR_Push_Pull>=bool_End)
	{
		return false;
	}
	GPIO_Init((GPIO_TypeDef*)((uint16_t)0x5000+GPIOx*5),BIT,((DDR<<7)|(Pull_Up_OR_Push_Pull<<6)));
	return true;
}

bool GPIO_SET_DATA(GPIO_Type GPIOx,BIT_Type BIT,PIN_State_Type PIN_State)
{
	if(GPIOx>=GPIO_End || BIT>BIT_ALL)
	{
		return false;
	}
	if(PIN_State==PIN_LOW)
	{
		GPIO_ResetBits((GPIO_TypeDef*)((uint16_t)0x5000+GPIOx*5),BIT);
	}
	else
	{
		GPIO_SetBits((GPIO_TypeDef*)((uint16_t)0x5000+GPIOx*5),BIT);
	}
	return true;
}
PIN_State_Type GPIO_GET_DATA(GPIO_Type GPIOx,BIT_Type BIT)
{
	if(GPIOx>=GPIO_End || BIT>BIT_ALL)
	{
		return false;
	}

	BitStatus BITx=GPIO_ReadInputDataBit((GPIO_TypeDef*)((uint16_t)0x5000+GPIOx*5),BIT);

	if(BITx==RESET)
	{
		return PIN_LOW;
	}
	else
	{
		return PIN_HIGH;
	}
}

//---------------------------------------------------------------------------------------------------------------

void ADC_Config(void)
{
	/* Enable ADC1 clock */
	CLK_PeripheralClockConfig(CLK_Peripheral_ADC1, ENABLE);
	/* Initialize and configure ADC1 */
	ADC_Init(ADC1, ADC_ConversionMode_Continuous, ADC_Resolution_8Bit, ADC_Prescaler_2);
	ADC_SamplingTimeConfig(ADC1, ADC_Group_SlowChannels, ADC_SamplingTime_384Cycles);
	ADC_SamplingTimeConfig(ADC1, ADC_Group_FastChannels, ADC_SamplingTime_384Cycles);

	/* Enable ADC1 */
	ADC_Cmd(ADC1, ENABLE);
	ADC_VrefintCmd(ENABLE);
}
#define ADC1_DR_ADDRESS        ((uint16_t)0x5344)
//#define BUFFER_SIZE            ((uint8_t) 0x03)


#define BUFFER_ADDRESS         ((uint16_t)(&Buffer))

uint16_t Buffer[10]  = {0};
uint8_t BufferSize=0;
uint32_t ADC_EN=0;

void DMA_Config(void)
{
	/* Enable DMA1 clock */
	CLK_PeripheralClockConfig(CLK_Peripheral_DMA1, ENABLE);
	/* Connect ADC to DMA channel 0 */
	SYSCFG_REMAPDMAChannelConfig(REMAP_DMA1Channel_ADC1ToChannel0);//ADCͨ��Ҫremap
	//BUFFER_SIZE
	DMA_Init(
			DMA1_Channel0, BUFFER_ADDRESS,
			ADC1_DR_ADDRESS,
			BufferSize,
			DMA_DIR_PeripheralToMemory,
			DMA_Mode_Circular,
			DMA_MemoryIncMode_Inc,
			DMA_Priority_High,
			DMA_MemoryDataSize_HalfWord);
	/* DMA Channel0 enable */
	DMA_Cmd(DMA1_Channel0, ENABLE);
	/* Enable DMA1 channel0 Transfer complete interrupt */
	//DMA_ITConfig(DMA1_Channel0, DMA_ITx_TC, ENABLE);
	/* DMA enable */
	DMA_GlobalCmd(ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
}

const uint16_t ADC_CH_Index[AIN_End]=
{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7,
	ADC_Channel_8,
	ADC_Channel_9,
	ADC_Channel_10,
	ADC_Channel_11,
	ADC_Channel_12,
	ADC_Channel_13,
	ADC_Channel_14,
	ADC_Channel_15,
	ADC_Channel_16,
	ADC_Channel_17,
	ADC_Channel_18,
	ADC_Channel_19,
	ADC_Channel_20,
	ADC_Channel_21,
	ADC_Channel_22,
	ADC_Channel_23,
	ADC_Channel_24,
	ADC_Channel_25,
	ADC_Channel_26,
	ADC_Channel_27,
	ADC_Channel_Vrefint,
	ADC_Channel_TempSensor,
};
bool ADC_SET_CH(AIN_ADC_Type ADCx,AIN_Type CH)
{
	if(ADCx!=AIN_ADC1 || CH>29)
	{
		return false;
	}

	ADC_ChannelCmd(ADC1, ADC_CH_Index[CH], ENABLE);

	if(((ADC_EN>>CH)&0x01)==0)
	{
		BufferSize++;

		ADC_EN=(uint32_t)((uint32_t)ADC_EN|(uint32_t)((uint32_t)1<<(uint32_t)CH));
	}


	return true;
}
uint8_t ADC_GET_DATA(AIN_ADC_Type ADCx,AIN_Type CH)
{
	if(ADCx!=AIN_ADC1 || CH>29)
	{
		return 0;
	}
	uint8_t Index=0;
	for(int i=0;i<AIN_End;i++)
	{
		if(((ADC_EN>>i)&0x01)!=0)
		{
			Index++;
		}

		if(i==CH)
		{
			if(Index!=0)
			{
				return Buffer[Index-1];
			}
			else
			{
				return 0;
			}

		}
	}

	return 0;
}
void ADC_Start(void)
{
	DMA_Config();
	ADC_SoftwareStartConv(ADC1);
}

//------------------------------------------------------------------------------------------
void SPI_SET_Init(uint8_t CPOL,uint8_t CPHA)
{
	SPI_CPOL_TypeDef SPI_CPOL;
	SPI_CPHA_TypeDef SPI_CPHA;

	if(CPOL==0)
	{
		SPI_CPOL=SPI_CPOL_Low;
	}
	else
	{
		SPI_CPOL=SPI_CPOL_High;
	}

	if(CPHA==0)
	{
		SPI_CPHA=SPI_CPHA_1Edge;
	}
	else
	{
		SPI_CPHA=SPI_CPHA_2Edge;
	}

	CLK_PeripheralClockConfig(CLK_Peripheral_SPI1, ENABLE);

	SPI_DeInit(SPI1);

	// 配置SPI相关参数,2分频（8MHZ）
	SPI_Init(SPI1,SPI_FirstBit_MSB, SPI_BaudRatePrescaler_2,
		 SPI_Mode_Master, SPI_CPOL, SPI_CPHA,
		 SPI_Direction_2Lines_FullDuplex, SPI_NSS_Soft,0x07);

	SPI_Cmd(SPI1,ENABLE);

	// SPI相关IO口配置
	GPIO_Init(GPIOB, GPIO_Pin_7, GPIO_Mode_In_PU_No_IT);       // MISO (PB7)
	GPIO_Init(GPIOB, GPIO_Pin_5, GPIO_Mode_Out_PP_High_Slow);  // SCLK (PB5)
	GPIO_Init(GPIOB, GPIO_Pin_6, GPIO_Mode_Out_PP_High_Slow);  // MOSI (PB6)

	GPIO_Init(GPIOB,GPIO_Pin_4, GPIO_Mode_Out_PP_High_Slow);	//NSS
	GPIO_SetBits(GPIOB,GPIO_Pin_4);
}
void SPI_SET_NSS(PIN_State_Type State)
{
	if(State==PIN_LOW)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_4);
	}
	else
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_4);
	}
}
uint8_t SPI_WR_Byte(uint8_t W_DATA)
{
	while (RESET == SPI_GetFlagStatus(SPI1,SPI_FLAG_TXE));   // 等待数据传输完成
	SPI_SendData(SPI1,W_DATA);
	while (RESET == SPI_GetFlagStatus(SPI1,SPI_FLAG_RXNE));  // 等待数据接收完成
	return (SPI_ReceiveData(SPI1));
}
