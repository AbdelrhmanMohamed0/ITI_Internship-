#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../1_MCAL/ADC/ADC_INTERFACE.h"
#include"../../2_HAL/LM35/LM35_INTERFACE.h"
#include"../../2_HAL/LCD/LCD_INTERFACE.h"
#include<util/delay.h>


int main(void) {
	u16 res=0;
	LCD_enuInit();
	ADC_voidInit();
	LM35_CONFIG lm35={ADC_CHANNEL0,5,ADC_RESOLUTION_10_BIT};
	while (1) {
		LM35_u8GetTemp(&lm35,&res);
		LCD_enuSetPosition(1,1);
		LCD_WriteNumberIn4Digits(res);
		_delay_ms(50);
	}
	return 0;
}

