#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../1_MCAL/TIMER/TIMER_interface.h"
#include"../../2_HAL/LED/LED_CONFIG.h"
#include"../../2_HAL/LED/LED_INTERFACE.h"

extern LED_t LED_Arr_Str_LedConfig[LED_NUM];
void isr(void) ;
void led(void);

int main(void) {
	LED_EnuInit(&LED_Arr_Str_LedConfig);
	TIMER2_voidInit();
	TIMER_u8SetCallBack(isr, TIMER2_CTC_VECTOR_ID);
	SGI();
	while (1) {
	}
	return 0;
}
void isr(void) {
	volatile static u32 count = 0;
	count++;
	if (count == 2000) {

		led();
		count = 0;
	}
}

void led(void) {
	volatile static u8 led = 0;
	if (led == 0) {
		LED_EnuTurnON(&LED_Arr_Str_LedConfig[0]);
		led = 1;
	} else {
		LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[0]);
		led = 0;
	}
}
