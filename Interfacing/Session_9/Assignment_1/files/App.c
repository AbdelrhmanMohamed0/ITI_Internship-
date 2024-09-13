/*
 * App.c
 *
 *  Created on: Jul 24, 2024
 *      Author: Abdelrhman Mohamed Ellawendi
 */
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "App.h"

int main(void)
{

	/*led direction  output */
	SET_BIT(LED1_PORT_DIRECTION, LED1_PIN_NUM);
	SET_BIT(LED2_PORT_DIRECTION, LED2_PIN_NUM);

	while (1)
	{
		SET_BIT(LED1_PORT, LED1_PIN_NUM);
		_delay_ms(DELAY_TIME_MS);
		CLR_BIT(LED1_PORT, LED1_PIN_NUM);
		SET_BIT(LED2_PORT, LED2_PIN_NUM);
		_delay_ms(DELAY_TIME_MS);
		CLR_BIT(LED2_PORT, LED2_PIN_NUM);
	}
	return 0;
}
