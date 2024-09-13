#include"../Master_User/master.h"
#include"../Pass_check/pass.h"
#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../1_MCAL/DIO/DIO_INTERFACE.h"
#include"../../1_MCAL/GIE/GIE_interface.h"
#include"../../1_MCAL/TIMER/TIMER_interface.h"
#include"../../2_HAL/LED/LED_CONFIG.h"
#include"../../2_HAL/LED/LED_INTERFACE.h"
#include"../../2_HAL/BUZZER/BUZ_interface.h"
#include"../../2_HAL/Servo/Servo.h"
#include <util/delay.h>
#include <string.h>

extern LED_t LED_Arr_Str_LedConfig[LED_NUM];
BUZ_Type BUZ = { BUZ_PORTC, BUZ_PIN3, ACTIVE_HIGH };
volatile u8 flag_1=0;

void flag_func(void);
void system_init(void);
void led_control(void);
void user_mode(void);


void main(void) {
u8 choice[2]={0};
	system_init();
	master_user_interface();
	system_init();
	user_mode();
	while (1) {
		USART_u8SendStringSynch((u8 *)"\n\r===== choice master or user mode =====");
		USART_u8SendStringSynch((u8 *)"\n\r===== 1- Master =====");
		USART_u8SendStringSynch((u8 *)"\n\r===== 2- User =====");
		USART_u8SendStringSynch((u8 *)"\n\r");
		while(flag_1==0){
		USART_u8ReceiveBufferAsynch(choice,1,flag_func);
		}
		flag_1=0;
		switch(choice[0])
		{
		case '1' :
			system_init();
		    master_user_interface();
		    break;
		case '2' :
			user_mode();
			break;
		}
	}
}


void flag_func(void){
	flag_1=1;
}

void system_init(void){
	DIO_Enu_Init();
	TIMER1_voidInit();
	LED_EnuInit(&LED_Arr_Str_LedConfig);
	BUZ_voidInit(&BUZ);
	SERVO_Init();
	SERVO_SetAngle(0);
	GIE_VoidEnable();
}

void led_control(void) {
    u8 choice[2] = {0};
    u8 ledState[2] = {0}; // 0 for OFF, 1 for ON

    USART_u8SendStringSynch((u8 *)"\n\r===== LED Control =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 0- LED Bathroom    =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 1- LED Kitchen     =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 2- LED Living Room =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 3- LED Bedroom     =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 4- LED Garage      =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 5- LED Hallway     =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 6- LED Garden      =====");
    USART_u8SendStringSynch((u8 *)"\n\r===== 7- LED Balcony     =====");
    USART_u8SendStringSynch((u8 *)"\n\rEnter LED number: ");

    while(flag_1 == 0) {
        USART_u8ReceiveBufferAsynch(choice, 1, flag_func);
    }
    flag_1 = 0;

    USART_u8SendStringSynch((u8 *)"\n\rEnter 1 to Turn ON or 0 to Turn OFF: ");
    while(flag_1 == 0) {
        USART_u8ReceiveBufferAsynch(ledState, 1, flag_func);
    }
    flag_1 = 0;

    switch(choice[0]) {
        case '0':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[0]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Bathroom is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[0]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Bathroom is now OFF");
            }
            break;
        case '1':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[1]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Kitchen is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[1]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Kitchen is now OFF");
            }
            break;
        case '2':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[2]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Living Room is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[2]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Living Room is now OFF");
            }
            break;
        case '3':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[3]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Bedroom is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[3]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Bedroom is now OFF");
            }
            break;
        case '4':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[4]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Garage is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[4]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Garage is now OFF");
            }
            break;
        case '5':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[5]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Hallway is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[5]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Hallway is now OFF");
            }
            break;
        case '6':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[6]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Garden is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[6]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Garden is now OFF");
            }
            break;
        case '7':
            if (ledState[0] == '1') {
                LED_EnuTurnON(&LED_Arr_Str_LedConfig[7]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Balcony is now ON");
            } else {
                LED_EnuTurnOFF(&LED_Arr_Str_LedConfig[7]);
                USART_u8SendStringSynch((u8 *)"\n\rLED Balcony is now OFF");
            }
            break;
        default:
            USART_u8SendStringSynch((u8 *)"\n\rInvalid Choice");
            break;
    }
}


void user_mode(void){
	u8 state = 0;
			USART_u8SendStringSynch((u8 *)"\n\r===== Welcome User Mode =====");
			state=check_pass_operation();
			if(state==1){
				SERVO_SetAngle(90);
				_delay_ms(5000);
				SERVO_SetAngle(0);
				led_control();
			}
			else{
				SERVO_SetAngle(0);
				BUZ_voidOn(&BUZ);        // Enable buzzer
				_delay_ms(5000);        // Keep the buzzer on for 5 seconds
				BUZ_voidOff(&BUZ);       // Turn off the buzzer
			}
}
