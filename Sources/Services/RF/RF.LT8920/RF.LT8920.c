/*
 * RF.LT8920.c
 *
 *  Created on: 2020年4月18日
 *      Author: Master.HE
 */
#include <string.h>
#include "Config.h"
#include "System/System.h"
#include "RF.LT8920.h"
#include "RF.LT8920.Cfg.h"

#include "System/System.h"

RF_LT8920_DATA_Type RF_LT8920_DATA;

#include "Application/Application.h"
extern Command_TX_DATA_Type Command_TX_DATA;
extern Command_RX_DATA_Type Command_RX_DATA;

extern const Command_TX_DATA_Type Command_TX_DATA_Default;
extern const Command_RX_DATA_Type Command_RX_DATA_Default;

#if defined(__TX__)

#elif defined(__RX__)

#else
#error "NO SET DDR"
#endif

void RF_LT8920_Init(void)
{
	SPI_SET_Init(0,1);

	GPIO_SET_DDR(GPIO_C,BIT4,IO_DDR_OUT,true);

	RF_LT8920_DATA.Status=RF_LT8920_Status_Init;
	RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_RST_LOW;
	RF_LT8920_DATA.TimeOut_Sub=-1;
	RF_LT8920_DATA.TimeOut_Init=-1;

	RF_LT8920_DATA.TimeOut_DATA=1;
}

void RF_LT8920_Read_Register_Byte(uint8_t ID,uint8_t *Data_H,uint8_t *Data_L)
{
	SPI_SET_NSS(PIN_LOW);
	SPI_WR_Byte(ID|0x80);
	*Data_H=SPI_WR_Byte(0);
	*Data_L=SPI_WR_Byte(0);
	SPI_SET_NSS(PIN_HIGH);
}
void RF_LT8920_Write_Register_Byte(uint8_t ID,uint8_t Data_H,uint8_t Data_L)
{
	SPI_SET_NSS(PIN_LOW);
	SPI_WR_Byte(ID);
	SPI_WR_Byte(Data_H);
	SPI_WR_Byte(Data_L);
	SPI_SET_NSS(PIN_HIGH);
}

void RF_LT8920_Read_Register(uint8_t ID,uint16_t *Data)
{
	SPI_SET_NSS(PIN_LOW);
	SPI_WR_Byte(ID|0x80);
	*Data=(uint16_t)((uint16_t)SPI_WR_Byte(0)<<8);
	*Data=(*Data)|SPI_WR_Byte(0);
	SPI_SET_NSS(PIN_HIGH);
}
void RF_LT8920_Write_Register(uint8_t ID,uint16_t Data)
{
	SPI_SET_NSS(PIN_LOW);
	SPI_WR_Byte(ID);
	SPI_WR_Byte((Data>>8)&0xFF);
	SPI_WR_Byte(Data&0xFF);
	SPI_SET_NSS(PIN_HIGH);
}

void RF_LT8920_SET_Init(void)
{
 	GPIO_SET_DATA(GPIO_C,BIT4,PIN_LOW);
 	DelayMs(10);
	GPIO_SET_DATA(GPIO_C,BIT4,PIN_HIGH);
	DelayMs(10);

	uint8_t Len=RF_LT8920_GET_Init_Len();

	for(uint8_t i=0;i<Len;i++)
	{
		RF_LT8920_Write_Register(RF_LT8920_Register_Init[i].Index,RF_LT8920_Register_Init[i].DATA);
	}
	DelayMs(20);

	//
	RF_LT8920_SET_Mode(RF_LT8920_Mode_Idle,0);

	RF_LT8920_SET_CLear_FIFO_Pointer(true,true);

	RF_LT8920_SET_MAC_Address(MCU_RF_ID,~((uint16_t)MCU_RF_ID),MCU_RF_ID,~((uint16_t)MCU_RF_ID));


}

bool RF_LT8920_SET_Mode(RF_LT8920_Mode_Type Mode,uint8_t F_PLL_CH_NO)
{
	if(Mode>=RF_LT8920_Mode_End || F_PLL_CH_NO>0x7F)
	{
		return false;
	}
	RF_LT8920_Register_7_Type Register_7={.Data=0};

	if(Mode==RF_LT8920_Mode_Idle)
	{
		Register_7.RX_EN=0;
		Register_7.TX_EN=0;
	}
	else if(Mode==RF_LT8920_Mode_TX)
	{
		Register_7.RX_EN=0;
		Register_7.TX_EN=1;
	}
	else if(Mode==RF_LT8920_Mode_RX)
	{
		Register_7.RX_EN=1;
		Register_7.TX_EN=0;
	}
	Register_7.RF_PLL_CH_NO=F_PLL_CH_NO;

	RF_LT8920_Write_Register(7, Register_7.Data);

	return true;

}
bool RF_LT8920_GET_SYNTH_LOCK(void)
{
	uint16_t DATA=0;

	RF_LT8920_Read_Register(3,&DATA);

	if((DATA&0x1000)!=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
uint8_t RF_LT8920_GET_RSSI(void)
{
	uint16_t DATA=0;

	RF_LT8920_Read_Register(6,&DATA);

	return (DATA>>10)&0x3F;
}

void RF_LT8920_SET_MAC_Address(
		uint16_t SYNC_WORD_15_0,
		uint16_t SYNC_WORD_31_16,
		uint16_t SYNC_WORD_47_32,
		uint16_t SYNC_WORD_63_48)
{
	RF_LT8920_Write_Register(36, SYNC_WORD_15_0);
	RF_LT8920_Write_Register(37, SYNC_WORD_31_16);
	RF_LT8920_Write_Register(38, SYNC_WORD_47_32);
	RF_LT8920_Write_Register(39, SYNC_WORD_63_48);
}
void RF_LT8920_SET_CLear_FIFO_Pointer(bool TX,bool RX)
{
	RF_LT8920_Register_52_Type Register_52={.Data=0};

	if(TX!=false)
	{
		Register_52.CLR_W_PTR=1;
	}
	if(RX!=false)
	{
		Register_52.CLR_R_PTR=1;
	}
	RF_LT8920_Write_Register(52,Register_52.Data);
}

uint8_t RF_LT8920_GET_FIFO_RD_PTR(void)
{
	RF_LT8920_Register_52_Type Register_52={.Data=0};
	RF_LT8920_Read_Register(52,&Register_52.Data);
	return Register_52.FIFO_RD_PTR;
}

uint32_t Sum;
void RF_LT8920_SET_FIFO_DATA(uint16_t *DATA,uint8_t Size)
{
	Sum=0xFE;//System_GET_Time_1MS();
	uint8_t *P=(uint8_t *)DATA;

	for(int i=0;i<Size*2;i++)
	{
		Sum=Sum+P[i];
	}

	RF_LT8920_Write_Register_Byte(50,Size*2+1,Sum&0xFF);

	for(int i=0;i<Size;i++)
	{
		RF_LT8920_Write_Register(50,DATA[i]);
	}
}
uint16_t Temp_DATA[10];
void RF_LT8920_GET_FIFO_DATA(uint16_t *DATA,uint8_t Size)
{
	uint8_t R_Size,Temp;
	RF_LT8920_Read_Register_Byte(50,&R_Size,&Temp);
	if(R_Size!=(Size*2+1))
	{
		return ;
	}

	for(int i=0;i<Size;i++)
	{
		RF_LT8920_Read_Register(50,&Temp_DATA[i]);
		//Sum=Sum+Temp_DATA[i];
	}
	Sum=0xFE;
	uint8_t *P=(uint8_t *)Temp_DATA;

	for(int i=0;i<Size*2;i++)
	{
		Sum=Sum+P[i];
	}

	if((Sum&0xFF)==Temp)
	{
		for(int i=0;i<Size;i++)
		{
			DATA[i]=Temp_DATA[i];
		}
	}
	else
	{
		__asm("NOP");
	}
}
RF_LT8920_Register_48_Type RF_LT8920_GET_Register_48(void)
{
	RF_LT8920_Register_48_Type Register_48={.Data=0};

	RF_LT8920_Read_Register(48,&Register_48.Data);

	return Register_48;
}
void RF_LT8920_SET_Baud_Rate(RF_LT8920_Baud_Rate_Type Baud_Rate)
{
	RF_LT8920_Write_Register(44,Baud_Rate);
}
void RF_LT8920_SET_Register_41(
		uint8_t CRC_INITIAL_DATA,
		uint8_t PKT_FIFO_POLARITY,
		bool AUTO_ACK,
		uint8_t FW_TERM_TX,
		uint8_t PACK_LENGTH_EN,
		bool CRC_ON)
{
	RF_LT8920_Register_41_Type Register_41={.Data=0};
	Register_41.CRC_INITIAL_DATA=CRC_INITIAL_DATA;
	Register_41.PKT_FIFO_POLARITY=PKT_FIFO_POLARITY;
	Register_41.AUTO_ACK=AUTO_ACK;
	Register_41.FW_TERM_TX=FW_TERM_TX;
	Register_41.PACK_LENGTH_EN=PACK_LENGTH_EN;
	Register_41.CRC_ON=CRC_ON;

	RF_LT8920_Write_Register(41,Register_41.Data);
}


void RF_LT8920_1MS(void)
{
	if(Command_TX_DATA.DATA_8Bit[0]!=0)
	{
		__asm("NOP");
	}
	
	switch (RF_LT8920_DATA.Status)
	{
		case RF_LT8920_Status_Init:
		{
			switch (RF_LT8920_DATA.Status_Sub)
			{
				case RF_LT8920_Status_Init_RST_LOW:
				{
					GPIO_SET_DATA(RF_LT8920_PIN,PIN_LOW);
					RF_LT8920_DATA.TimeOut_Sub=10;
					RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_RST_TimeOut;

					RF_LT8920_DATA.TimeOut_Init=-1;
					RF_LT8920_DATA.TimeOut_Default=-1;
				}break;
				case RF_LT8920_Status_Init_RST_TimeOut:
				{
					if(RF_LT8920_DATA.TimeOut_Sub>0)
					{
						RF_LT8920_DATA.TimeOut_Sub--;
						if(RF_LT8920_DATA.TimeOut_Sub==0)
						{
							RF_LT8920_DATA.TimeOut_Sub=-1;
							RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_RST_High;
						}
					}
				}break;
				case RF_LT8920_Status_Init_RST_High:
				{
					GPIO_SET_DATA(RF_LT8920_PIN,PIN_HIGH);
					RF_LT8920_DATA.TimeOut_Sub=10;
					RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_RST_TimeOut1;

				}break;
				case RF_LT8920_Status_Init_RST_TimeOut1:
				{
					if(RF_LT8920_DATA.TimeOut_Sub>0)
					{
						RF_LT8920_DATA.TimeOut_Sub--;
						if(RF_LT8920_DATA.TimeOut_Sub==0)
						{
							RF_LT8920_DATA.TimeOut_Sub=-1;
							RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_Register;
						}
					}
				}break;
				case RF_LT8920_Status_Init_Register:
				{
					uint8_t Len=RF_LT8920_GET_Init_Len();

					for(uint8_t i=0;i<Len;i++)
					{
						RF_LT8920_Write_Register(RF_LT8920_Register_Init[i].Index,RF_LT8920_Register_Init[i].DATA);
					}
					RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_SET;
				}break;

				case RF_LT8920_Status_Init_SET:
				{
					//
					RF_LT8920_SET_Mode(RF_LT8920_Mode_Idle,RF_LT8920_DATA.RF_PLL_CH_NO);

					RF_LT8920_SET_CLear_FIFO_Pointer(true,true);

					RF_LT8920_SET_MAC_Address(MCU_RF_ID,~((uint16_t)MCU_RF_ID),MCU_RF_ID,~((uint16_t)MCU_RF_ID));

					RF_LT8920_SET_Register_41(0,0,true,1,1,true);

					RF_LT8920_SET_Baud_Rate(RF_LT8920_Baud_Rate_62500bps);

					RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_DATA;

					RF_LT8920_DATA.TimeOut_Init=RF_LT8920_TimeOut_Init;



				}break;

				case RF_LT8920_Status_Init_DATA:
				{
					uint16_t ID=0;
					RF_LT8920_Read_Register(30,&ID);
					while(ID!=0xF413)
					{
						;
					}
#if defined(__TX__)
					RF_LT8920_DATA.Status=RF_LT8920_Status_Wait_TX;
					RF_LT8920_DATA.TimeOut_Wait_TX=RF_LT8920_TimeOut_Wait_TX;

#elif defined(__RX__)
					RF_LT8920_DATA.Status=RF_LT8920_Status_RX_DATA;
#endif
					//--------------------------------------------
					//RF_LT8920_DATA.TimeOut_Sub=100;

					RF_LT8920_DATA.RF_PLL_CH_NO=0;

					RF_LT8920_DATA.TimeOut_Default=-1;
					
					RF_LT8920_SET_Mode(RF_LT8920_Mode_Idle,RF_LT8920_DATA.RF_PLL_CH_NO);

					RF_LT8920_SET_CLear_FIFO_Pointer(true,true);
					
				}break;
				default:
				{

				}break;
			}
		}break;
//----------------------------------------------------------------------------------------------------
		case RF_LT8920_Status_Wait_TX:
		{
			if(RF_LT8920_DATA.TimeOut_Wait_TX>0)
			{
				RF_LT8920_DATA.TimeOut_Wait_TX--;
				if(RF_LT8920_DATA.TimeOut_Wait_TX==0)
				{
					RF_LT8920_DATA.TimeOut_Wait_TX=-1;
					RF_LT8920_DATA.Status=RF_LT8920_Status_TX_DATA;
				}
			}
		}break;
		case RF_LT8920_Status_TX_DATA:
		{
			RF_LT8920_SET_CLear_FIFO_Pointer(true,true);

			RF_LT8920_SET_Mode(RF_LT8920_Mode_Idle,RF_LT8920_DATA.RF_PLL_CH_NO);

#if defined(__TX__)
			RF_LT8920_SET_FIFO_DATA(Command_TX_DATA.DATA_16Bit,sizeof(Command_TX_DATA_Type)/2);
#elif defined(__RX__)
			RF_LT8920_SET_FIFO_DATA(Command_RX_DATA.DATA_16Bit,sizeof(Command_RX_DATA_Type)/2);
#endif

			RF_LT8920_SET_Mode(RF_LT8920_Mode_TX,RF_LT8920_DATA.RF_PLL_CH_NO);

			RF_LT8920_DATA.Status=RF_LT8920_Status_TX_Wait_Finish;

			RF_LT8920_DATA.TimeOut_Sub=RF_LT8920_TimeOut_Wait_TX_DATA_Send;
		}break;

		case RF_LT8920_Status_TX_Wait_Finish:
		{
			RF_LT8920_Register_48_Type Register_48;

			Register_48=RF_LT8920_GET_Register_48();

			if(Register_48.PKT_FLAG==1)
			{
				uint8_t ACK=RF_LT8920_GET_FIFO_RD_PTR();
				if(ACK==0)
				{
					RF_LT8920_DATA.Status=RF_LT8920_Status_RX_DATA;

					RF_LT8920_DATA.TimeOut_Sub=-1;

#if defined(__TX__)
					RF_LT8920_DATA.TimeOut_Default=RF_LT8920_TimeOut_Default;
#elif defined(__RX__)
					RF_LT8920_DATA.TimeOut_Default=-1;
#endif
					RF_LT8920_DATA.TimeOut_Init=RF_LT8920_TimeOut_Init;
				}
				else
				{
					RF_LT8920_DATA.Status=RF_LT8920_Status_TX_Change_Channel;
				}

				RF_LT8920_SET_Mode(RF_LT8920_Mode_Idle,0);
				RF_LT8920_SET_CLear_FIFO_Pointer(true,true);
			}
			else
			{
				__asm("nop");
			}

			if(RF_LT8920_DATA.TimeOut_Sub>0)
			{
				RF_LT8920_DATA.TimeOut_Sub--;
				if(RF_LT8920_DATA.TimeOut_Sub==0)
				{
					RF_LT8920_DATA.TimeOut_Sub=-1;
					RF_LT8920_DATA.Status=RF_LT8920_Status_TX_Change_Channel;
				}
			}
		}break;
		case RF_LT8920_Status_TX_Change_Channel:
		{
			RF_LT8920_DATA.TimeOut_Sub=RF_LT8920_TimeOut_Wait_TX_DATA_Send;
			RF_LT8920_DATA.RF_PLL_CH_NO=RF_LT8920_DATA.RF_PLL_CH_NO+10;
			if(RF_LT8920_DATA.RF_PLL_CH_NO>=40)
			{
				RF_LT8920_DATA.RF_PLL_CH_NO=0;
			}
			RF_LT8920_DATA.Status=RF_LT8920_Status_TX_DATA;

		}break;
//-------------------------------------------------------------------------------------
		case RF_LT8920_Status_RX_DATA:
		{
			RF_LT8920_SET_CLear_FIFO_Pointer(true,true);

			RF_LT8920_SET_Mode(RF_LT8920_Mode_RX,RF_LT8920_DATA.RF_PLL_CH_NO);

			RF_LT8920_DATA.Status=RF_LT8920_Status_RX_Wait_DATA;
			RF_LT8920_DATA.TimeOut_Sub=RF_LT8920_TimeOut_Wait_RX_DATA;

		}break;
		case RF_LT8920_Status_RX_Wait_DATA:
		{

			RF_LT8920_Register_48_Type Register_48;

			Register_48=RF_LT8920_GET_Register_48();

			if(Register_48.PKT_FLAG==1)
			{
				if(Register_48.CRC_ERROR==0)
				{
#if defined(__TX__)
					RF_LT8920_GET_FIFO_DATA(Command_RX_DATA.DATA_16Bit,sizeof(Command_RX_DATA_Type)/2);
#elif defined(__RX__)
					RF_LT8920_GET_FIFO_DATA(Command_TX_DATA.DATA_16Bit,sizeof(Command_TX_DATA_Type)/2);
#endif

					RF_LT8920_DATA.TimeOut_DATA=RF_LT8920_TimeOut_DATA;

#if defined(__TX__)
					RF_LT8920_DATA.TimeOut_Default=-1;
#elif defined(__RX__)
					RF_LT8920_DATA.TimeOut_Default=RF_LT8920_TimeOut_Default;
#endif

					RF_LT8920_DATA.Status=RF_LT8920_Status_Wait_TX;
					RF_LT8920_DATA.TimeOut_Wait_TX=RF_LT8920_TimeOut_Wait_TX;

					RF_LT8920_DATA.TimeOut_Init=RF_LT8920_TimeOut_Init;

					RF_LT8920_SET_Mode(RF_LT8920_Mode_Idle,RF_LT8920_DATA.RF_PLL_CH_NO);
					RF_LT8920_SET_CLear_FIFO_Pointer(true,true);
				}
				else
				{
					__asm("nop");
				}


			}
			else
			{

			}

			if(RF_LT8920_DATA.TimeOut_Sub>0)
			{
				RF_LT8920_DATA.TimeOut_Sub--;
				if(RF_LT8920_DATA.TimeOut_Sub==0)
				{
					RF_LT8920_DATA.TimeOut_Sub=-1;
					RF_LT8920_DATA.Status=RF_LT8920_Status_RX_Change_Channel;
					RF_LT8920_SET_Mode(RF_LT8920_Mode_Idle,RF_LT8920_DATA.RF_PLL_CH_NO);
					RF_LT8920_SET_CLear_FIFO_Pointer(true,true);
				}
			}
		}break;
		case RF_LT8920_Status_RX_Change_Channel:
		{
			RF_LT8920_DATA.TimeOut_Sub=RF_LT8920_TimeOut_Wait_RX_DATA;
			RF_LT8920_DATA.RF_PLL_CH_NO=RF_LT8920_DATA.RF_PLL_CH_NO+10;
			if(RF_LT8920_DATA.RF_PLL_CH_NO>=40)
			{
				RF_LT8920_DATA.RF_PLL_CH_NO=0;
			}
			RF_LT8920_DATA.Status=RF_LT8920_Status_RX_DATA;
		}break;

		default:
		{

		}break;
	}

	//复位芯片
	if(RF_LT8920_DATA.TimeOut_Init>0)
	{
		RF_LT8920_DATA.TimeOut_Init--;
		if(RF_LT8920_DATA.TimeOut_Init==0)
		{

			RF_LT8920_DATA.Status=RF_LT8920_Status_Init;
			RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_RST_LOW;
			RF_LT8920_DATA.TimeOut_Init=-1;
			RF_LT8920_DATA.TimeOut_Default=-1;
		}
	}

	//复位到默认方向
	if(RF_LT8920_DATA.TimeOut_Default>0)
	{
		RF_LT8920_DATA.TimeOut_Default--;
		if(RF_LT8920_DATA.TimeOut_Default==0)
		{
			RF_LT8920_DATA.TimeOut_Default=-1;
			RF_LT8920_DATA.Status=RF_LT8920_Status_Init;
			RF_LT8920_DATA.Status_Sub=RF_LT8920_Status_Init_DATA;



		}
	}

	//复位数据
	if(RF_LT8920_DATA.TimeOut_DATA>0)
	{
		RF_LT8920_DATA.TimeOut_DATA--;
		if(RF_LT8920_DATA.TimeOut_DATA==0)
		{
			RF_LT8920_DATA.TimeOut_DATA=RF_LT8920_TimeOut_DATA;

#if defined(__TX__)
			memcpy(&Command_RX_DATA,&Command_RX_DATA_Default,sizeof(Command_RX_DATA_Type));
#elif defined(__RX__)
			memcpy(&Command_TX_DATA,&Command_TX_DATA_Default,sizeof(Command_TX_DATA_Type));
#endif
		}
	}
}

void RF_LT8920_10MS(void)
{












#ifdef __TX__


#endif

#ifdef __RX__

#endif
}
