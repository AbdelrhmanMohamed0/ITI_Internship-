#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include "../../2_HAL/LCD/LCD_INTERFACE.h"
#include"../../5_SERVICE/Timers_Services.h"
#include<util/delay.h>
int main(void) {
	u32 freq;
	u8 duty;
	LCD_enuInit();
	LCD_enuClearScreen();
	SGI();
	PWM_Measure_HW(&freq,&duty);
	LCD_enuSetPosition(1,1);
	LCD_enuSendString("Frequency = ");
	LCD_enuSendNumber(freq);
	LCD_enuSendString(" HZ");
	LCD_enuSetPosition(2,1);
	LCD_enuSendString("Duty = ");
	LCD_enuSendNumber(duty);
	LCD_enuSendString(" %");
	while (1)
	{

	}
	return 0;
}


