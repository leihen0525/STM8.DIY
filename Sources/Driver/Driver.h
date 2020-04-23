/*
 * Driver.h
 *
 *  Created on: 2020年4月7日
 *      Author: Master.HE
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#if (defined (STM8L15X_MD)			\
	|| defined (STM8L15X_MDP)		\
	|| defined (STM8L15X_HD)		\
	|| defined (STM8L15X_LD)		\
	|| defined (STM8L05X_LD_VL)		\
	|| defined (STM8L05X_MD_VL)		\
	|| defined (STM8L05X_HD_VL)		\
	|| defined (STM8AL31_L_MD))
#include "Driver.STM8L15x/Driver.STM8L15x.h"
#endif


#include "Driver.Enum.h"

void Driver_Init(void);




#endif /* DRIVER_H_ */
