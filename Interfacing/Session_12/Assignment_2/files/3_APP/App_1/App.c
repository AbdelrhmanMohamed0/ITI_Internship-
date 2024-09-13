#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../2_HAL/LCD/LCD_INTERFACE.h"
#include<util/delay.h>

#define MAX_STRING_LENGTH 10
#define SCROLL_DELAY 100
#define RESET_POSITION -16

void displayMovingText(u8 *str, s8 *index) {
    LCD_enuSetPosition(1, 1);
    LCD_enuSendString(&str[*index]);
    (*index)--;
    _delay_ms(SCROLL_DELAY);
}

void displayCustomCharacters(void) {
    LCD_enuSendExtraChar(2,1,0);
    LCD_enuSendExtraChar(2,2,1);
    LCD_enuSendExtraChar(2,3,2);
    LCD_enuSendExtraChar(2,10,7);
}

int main(void) {
    LCD_enuInit();
    LCD_enuClearScreen();

    u8 name[] = "Abdelrhman";
    s8 i = MAX_STRING_LENGTH - 1;

    while (1) {
        while (i >= 0) {
            displayMovingText(name, &i);
        }

        i--;
        if (i == RESET_POSITION) {
            i = MAX_STRING_LENGTH - 1;
            LCD_enuClearScreen();
        }

        LCD_enuSendCommand(lcd_Display_shift_right);
        displayCustomCharacters();
    }

    return 0;
}
