
#include "Driver/Driver.h"
#include "System/System.h"



void main(void)
{
	DelayMs(100);

	__DisableInterrupts();

	System_Init();

	__EnableInterrupts();

	System_Task();

	while(1)
	{

	}
}



