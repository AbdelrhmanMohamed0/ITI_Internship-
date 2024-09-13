
#ifndef TIMERS_SERVICES_H_
#define TIMERS_SERVICES_H_


#include "../1_MCAL/TIMER/TIMER_interface.h"

#define SIGNAL_PORT DIO_u8PORTD
#define SIGNAL_PIN  DIO_u8PIN6

#define ICP_FALLING_EDGE                   0
#define ICP_RAISING_EDGE                   1

/*
	EX_INT0
	EX_INT1
	EX_INT2
*/

#define ICU_EXTI_CHANNEL	EX_INT0

#define ICU_STATE_WAIT_FOR_RISINGEDGE1	0
#define ICU_STATE_WAIT_FOR_FALLINGEDGE	1
#define ICU_STATE_WAIT_FOR_RISINGEDGE2	2



static volatile u16 t_on = 0;
static volatile u16 period = 0;



void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void));
void PWM_Measure_SW(u32* Pfreq,u8* Pduty);
void PWM_Measure_HW(u32* Pfreq,u8* Pduty);
void PWM_Measure2(u32* Pfreq,u8* Pduty);
static void ICU_Init(void);
static void Func_ICU_HW(void);
static void EXTI_Callback(void);

#endif /* TIMERS_SERVICES_H_ */
