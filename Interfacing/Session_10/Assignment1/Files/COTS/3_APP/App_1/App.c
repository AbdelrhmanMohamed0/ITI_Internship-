#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../2_HAL/LED/LED_CONFIG.h"
#include"../../2_HAL/LED/LED_INTERFACE.h"
#include<util/delay.h>
#define delay 1000

extern LED_t LED_Arr_Str_LedConfig[LED_NUM];

int main(void) {
	LED_EnuInit(LED_Arr_Str_LedConfig);
	s8 i = 0;
	while (1) {
		for (i = 0; i < 5; i++) {
			LED_EnuTurnON(&LED_Arr_Str_LedConfig[i]);
			_delay_ms(delay);
		}
		for (i = 4; i >=0; i--) {
			LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[i]);
			_delay_ms(delay);
		}
	}

	return 0;
}
