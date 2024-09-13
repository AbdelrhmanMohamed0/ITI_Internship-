#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../1_MCAL/DIO/DIO_INTERFACE.h"
#include"../../1_MCAL/TWI/TWI_interface.h"
#include "../../2_HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../../2_HAL/Servo/Servo.h"
#include "../../2_HAL/EEPROM/EEPROM_interface.h"
#include"../../2_HAL/LCD/LCD_INTERFACE.h"
#include <util/delay.h>
#include <string.h>
#define PASS_LOCATION   0x12

int main(void) {
	u8 read[5] = { 0 };
	u8 pass_preased_key[5] = { 0 };
	u8 new_pass[5] = { 0 }, preased_key;
	DIO_Enu_Init();
	KPD_enu_Init();
	SERVO_Init();
	LCD_enuInit();
	LCD_enuClearScreen();
	EEPROM_voidInit();
	u8 pass[5] = "1234";
	u8 is_stored = 1;
	for (u8 i = 0; i < 4; i++) {
		read[i] = EEPROM_u8ReadDataByte(PASS_LOCATION + i);
		_delay_ms(15);
		if (read[i] != pass[i]) {
			is_stored = 0;
		}
	}
	if (is_stored) {
		for (u8 i = 0; i < 4; i++) {
			EEPROM_voidSendDataByte(PASS_LOCATION + i, pass[i]);
			_delay_ms(15);
		}
	}
	while (1) {
		SERVO_SetAngle(0);
		for (u8 i = 0; i < 4; i++) {
			read[i] = EEPROM_u8ReadDataByte(PASS_LOCATION + i);
		}

		LCD_enuSendString("WELCOME");
		LCD_enuSetPosition(2, 1);
		LCD_enuSendString("ENTER PASSCODE :");
		while (strncmp(read, pass_preased_key, 5) != 0) {
			for (u8 i = 0; i < 4; i++) {
				do {
					KPD_enu_GetPressed(&pass_preased_key[i]);
				} while (pass_preased_key[i] == '\0');
				if (i == 0) {
					LCD_enuClearScreen();
				}
				LCD_enuSendData('*');
			}
			if (strncmp(read, pass_preased_key, 5) != 0) {
				LCD_enuClearScreen();
				LCD_enuSendString("WRONG PASSCODE");
				LCD_enuSetPosition(2, 1);
				LCD_enuSendString("TRY AGAIN :");
			} else {
				break;
			}
		}

		SERVO_SetAngle(90);
		LCD_enuClearScreen();
		LCD_enuSendString("1-TO CLOSE Door");
		LCD_enuSetPosition(2, 1);
		LCD_enuSendString("2-TO CHANGE PASS");
		do {
			KPD_enu_GetPressed(&preased_key);
		} while (preased_key == '\0'
				&& (preased_key != '1' || preased_key != '2'));
		if (preased_key == '1') {
			SERVO_SetAngle(0);
		} else if (preased_key == '2') {
			LCD_enuClearScreen();
			LCD_enuSendString("ENTER NEW PASS :");
			for (u8 i = 0; i < 4; i++) {
				do {
					KPD_enu_GetPressed(&new_pass[i]);
				} while (new_pass[i] == '\0');
				if (i == 0) {
					LCD_enuClearScreen();
				}
				LCD_enuSendData('*');
			}
			for (u8 i = 0; i < 4; i++) {
				EEPROM_voidSendDataByte(PASS_LOCATION + i, new_pass[i]);
			}
			strcpy(pass, new_pass);
		}
		for (u8 i = 0; i < 4; i++) {
			read[i] = 0;
			pass_preased_key[i] = 0;
			new_pass[i] = 0;
			LCD_enuClearScreen();
		}
	}
	return 0;
}

