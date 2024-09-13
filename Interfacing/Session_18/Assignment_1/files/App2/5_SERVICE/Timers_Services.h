
#ifndef TIMERS_SERVICES_H_
#define TIMERS_SERVICES_H_

#define SIGNAL_PORT DIO_u8PORTD
#define SIGNAL_PIN  DIO_u8PIN6

/*
	EX_INT0
	EX_INT1
	EX_INT2
*/

#define ICU_EXTI_CHANNEL	EX_INT0

#define ICU_STATE_WAIT_FOR_RISINGEDGE1	0
#define ICU_STATE_WAIT_FOR_FALLINGEDGE	1
#define ICU_STATE_WAIT_FOR_RISINGEDGE2	2

#define FASTICU_FIRST_RISING	0
#define FASTICU_FALLING			1
#define FASTICU_SECOND_RISING	2

#define ICP_FALLING_EDGE                   0
#define ICP_RAISING_EDGE                   1

# define SGI()   __asm__ __volatile__ ("sei" ::)

void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void));
void PWM_Measure_SW(u32* Pfreq,u8* Pduty);
void PWM_Measure_HW(u32* Pfreq,u8* Pduty);
void PWM_Measure2(u32* Pfreq,u8* Pduty);

#endif /* TIMERS_SERVICES_H_ */
