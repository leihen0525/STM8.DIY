/*
 * Servos.Enum.h
 *
 *  Created on: 2020年4月23日
 *      Author: Master.HE
 */

#ifndef SERVOS_ENUM_H_
#define SERVOS_ENUM_H_

typedef enum
{
	Servos_Model_MG996R					=0,
}Servos_Model_Type;

typedef enum
{
	Servos_Direction_Positive			=0,
	Servos_Direction_Negative,

	Servos_Direction_End,
}Servos_Direction_Type;

typedef enum
{
	Servos_Angle_90_Degree			=0,
	Servos_Angle_180_Degree,

	Servos_Angle_End,
}Servos_Angle_Type;

#endif /* SERVOS_ENUM_H_ */
