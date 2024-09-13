#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include "../../1_MCAL/DIO/DIO_INTERFACE.h"
#include"../../1_MCAL/TIMER/TIMER_interface.h"
int main(void) {
	DIO_Enu_Init();
	TIMER1_voidInit();
	SGI();
	while (1)
	{

	}
	return 0;
}


