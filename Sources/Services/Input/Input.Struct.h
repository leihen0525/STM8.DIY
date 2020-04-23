/*
 * Input.Struct.h
 *
 *  Created on: 2020年4月11日
 *      Author: Master.HE
 */

#ifndef INPUT_STRUCT_H_
#define INPUT_STRUCT_H_

#include <stdint.h>

typedef struct
{
	uint8_t Enabled;

	uint8_t Type;			//口类型
	uint8_t Default;
	uint8_t Active;
	
	uint8_t GPIOx;
	uint8_t BIT_AIN;
	uint8_t Pull_Up;
	
	uint8_t AIN_IO_Min;
	uint8_t AIN_IO_Max;
}Input_Config_Type;

typedef struct
{
	uint8_t Temp_Data;

	uint8_t Logic_Data;
	uint8_t Physics_Data;

	int8_t Time_CheckOut;

	//AD滤波
	uint8_t AD_Temp[4];
	
}Input_DATA_Type;

#endif /* INPUT_STRUCT_H_ */
