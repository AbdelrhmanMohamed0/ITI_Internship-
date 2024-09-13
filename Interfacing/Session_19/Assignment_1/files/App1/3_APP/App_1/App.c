#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../1_MCAL/USART/USART_interface.h"
#include "../../2_HAL/LCD/LCD_INTERFACE.h"
#include<util/delay.h>
# define SGI()   __asm__ __volatile__ ("sei" ::)
u8 volatile buffer[30] = { 0 };

void func_send(void) {
}

void func_receive(void) {
	LCD_enuSetPosition(1, 1);
	LCD_enuSendString("Received Data is:");
	LCD_enuSetPosition(2, 1);
	LCD_enuSendString(buffer);
}

int main(void) {
	LCD_enuInit();
	LCD_enuClearScreen();
	USART_voidInit();
	SGI();

	while (1) {
		USART_u8SendStringAsynch("Abdelrhman", func_send);
		USART_u8ReceiveBufferAsynch(buffer, 7, func_receive);
	}
	return 0;
}

