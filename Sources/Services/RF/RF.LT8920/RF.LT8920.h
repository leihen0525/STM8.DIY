/*
 * RF.LT8920.h
 *
 *  Created on: 2020年4月18日
 *      Author: Master.HE
 */

#ifndef RF_LT8920_H_
#define RF_LT8920_H_

#include "Driver/Driver.h"
#include "RF.LT8920.Enum.h"
#include "RF.LT8920.Struct.h"


void RF_LT8920_Init(void);

void RF_LT8920_Read_Register_Byte(uint8_t ID,uint8_t *Data_H,uint8_t *Data_L);
void RF_LT8920_Write_Register_Byte(uint8_t ID,uint8_t Data_H,uint8_t Data_L);

void RF_LT8920_Read_Register(uint8_t ID,uint16_t *Data);
void RF_LT8920_Write_Register(uint8_t ID,uint16_t Data);

void RF_LT8920_SET_Init(void);

bool RF_LT8920_SET_Mode(RF_LT8920_Mode_Type Mode,uint8_t F_PLL_CH_NO);
bool RF_LT8920_GET_SYNTH_LOCK(void);
uint8_t RF_LT8920_GET_RSSI(void);
void RF_LT8920_SET_MAC_Address(
		uint16_t SYNC_WORD_15_0,
		uint16_t SYNC_WORD_31_16,
		uint16_t SYNC_WORD_47_32,
		uint16_t SYNC_WORD_63_48);
void RF_LT8920_SET_CLear_FIFO_Pointer(bool TX,bool RX);
uint8_t RF_LT8920_GET_FIFO_RD_PTR(void);
void RF_LT8920_SET_FIFO_DATA(uint16_t *DATA,uint8_t Size);
void RF_LT8920_GET_FIFO_DATA(uint16_t *DATA,uint8_t Size);
RF_LT8920_Register_48_Type RF_LT8920_GET_Register_48(void);
void RF_LT8920_SET_Baud_Rate(RF_LT8920_Baud_Rate_Type Baud_Rate);
void RF_LT8920_SET_Register_41(
		uint8_t CRC_INITIAL_DATA,
		uint8_t PKT_FIFO_POLARITY,
		bool AUTO_ACK,
		uint8_t FW_TERM_TX,
		uint8_t PACK_LENGTH_EN,
		bool CRC_ON);

void RF_LT8920_1MS(void);
void RF_LT8920_10MS(void);

#endif /* RF_LT8920_H_ */
