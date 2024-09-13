/*
 * App.h
 *
 *  Created on: Jul 24, 2024
 *      Author: Abdelrhman Mohamed Ellawendi
 */

#ifndef APP_H_
#define APP_H_

/* set delay time */
#define DELAY_TIME_MS 1000

/* output value */
#define LOW 0
#define HIGH 1

/* you can choice (DDRA , DDRB , DDRC , DDRD) */
#define LED1_PORT_DIRECTION DDRA
#define LED2_PORT_DIRECTION DDRA

/* you can choice (PORTA , PORTB , PORTC , PORTD) */
#define LED1_PORT PORTA
#define LED2_PORT PORTA

/* you can choice from 0 to 7 */
#define LED1_PIN_NUM 1
#define LED2_PIN_NUM 2

#endif /* APP_H_ */
