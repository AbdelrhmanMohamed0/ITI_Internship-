#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../2_HAL/LED/LED_CONFIG.h"
#include"../../2_HAL/LED/LED_INTERFACE.h"
#include"../../1_MCAL/EXTI/EXTI_PP/EXTI_INTERFACE.h"
#include"../../2_HAL/SWITCH/SWITCH_CONFIG.h"
#include"../../2_HAL/SWITCH/SWITCH_INTERFACE.h"

extern LED_t LED_Arr_Str_LedConfig[LED_NUM];
extern SW_t Switch_Arr_Stru_SwitchState[SW_NUM];

volatile u8 collision_detected = 0;
void activateAirbag(void);
void deactivateAirbag(void);

int main(void) {
	LED_EnuInit(&LED_Arr_Str_LedConfig);
	SWITCH_EnuInit(&Switch_Arr_Stru_SwitchState);
	EXI_TriggerEdge(EX_INT0, FALLING_EDGE);
	EXI_Enable(EX_INT0);
	EXI_SetCallBack(EX_INT0, activateAirbag);
	SGI();
	while (1)
	{
		if (collision_detected == 0) {
			deactivateAirbag();
		}
	}
		return 0;
}
	void activateAirbag(void) {
		LED_EnuTurnON(&LED_Arr_Str_LedConfig[0]);
		collision_detected = 1;
	}

	void deactivateAirbag(void) {
		LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[0]);
	}
