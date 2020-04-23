/*
 * Driver.STM8L15x.Define.h
 *
 *  Created on: 2020年4月7日
 *      Author: Master.HE
 */

#ifndef DRIVER_STM8L15X_DEFINE_H_
#define DRIVER_STM8L15X_DEFINE_H_


#define __NOP()						nop()
#define __WAIT()					wfi()
#define __IWDG_FREE()				IWDG_ReloadCounter()

#define __DisableInterrupts()		disableInterrupts()
#define __EnableInterrupts()		enableInterrupts()

#endif /* DRIVER_STM8L15X_DEFINE_H_ */
