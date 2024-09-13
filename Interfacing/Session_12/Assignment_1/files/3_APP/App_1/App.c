#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../1_MCAL/DIO/DIO_INTERFACE.h"
#include"../../2_HAL/LED/LED_CONFIG.h"
#include"../../2_HAL/LED/LED_INTERFACE.h"
#include"../../2_HAL/LCD/LCD_INTERFACE.h"
#include"../../2_HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include<util/delay.h>
#include <string.h>

extern LED_t LED_Arr_Str_LedConfig[LED_NUM];
const u8 PASSWORD[] = "123";

int main(void) {

	u8 num, i = 0, trial = 0, pass[4] = { 0 };

	DIO_Enu_Init();
	LED_EnuInit(&LED_Arr_Str_LedConfig);
	KPD_enu_Init();
	LCD_enuInit();
	LCD_enuClearScreen();

	LED_EnuTurnON(&LED_Arr_Str_LedConfig[0]);
	LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[1]);
	LCD_enuSetPosition(1, 1);
	LCD_enuSendString("Welcome ");
	LCD_enuSetPosition(2, 1);
	LCD_enuSendString("Enter password : ");

	while (1) {
		do {
			for (i = 0; i < 3; i++)
			{
				do
				{
					KPD_enu_GetPressed(&num);
				} while (num == '\0');
				if (i == 0)
				{
					LCD_enuClearScreen();
				}
				pass[i] = num;
				LCD_enuSendData('*');
			}
			pass[i] = '\0';
			if (strcmp(pass, PASSWORD) != 0)
			{
				LCD_enuClearScreen();
				LCD_enuSendString("Invalid Pass :");
				LCD_enuSetPosition(2, 1);
				LCD_enuSendString("Try Again :");
				_delay_ms(1000);
				trial++;
				LCD_enuClearScreen();
			}
			if (trial == 3)
			{
				trial = 0;
				LCD_enuClearScreen();
				LCD_enuSendString("Locked for 5 sec");
				_delay_ms(5000);
				LCD_enuClearScreen();
			}
		} while (strcmp(pass, PASSWORD) != 0);
		LCD_enuClearScreen();
		while (strcmp(pass, PASSWORD) == 0)
		{
			LCD_enuSetPosition(1, 1);
			LCD_enuSendString("Correct password:");
			LCD_enuSetPosition(2, 1);
			LCD_enuSendString("    Welcome    ");
			LED_EnuTurnON(&LED_Arr_Str_LedConfig[1]);
			LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[0]);
		}

	}
	return 0;
}
