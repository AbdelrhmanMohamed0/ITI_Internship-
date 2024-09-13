#include "../4_LIB/STD_TYPES.h"
#include "../4_LIB/BIT_MATH.h"
#include "../4_LIB/ERROR_STATES.h"
#include "../1_MCAL/DIO/DIO_INTERFACE.h"
#include "../1_MCAL/EXTI/EXTI_PP/EXTI_INTERFACE.h"
#include "../1_MCAL/TIMER/TIMER_interface.h"
#include "Timers_Services.h"
static volatile u16 t_on = 0, period = 0;
static volatile u16 Ton=0,Toff=0;
static void ICU_Init(void);
static void Func_ICU_HW(void);
static void EXTI_Callback(void);
/******************************************Set Interrupt Time******************************************************/

void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void))
{
	TIMER1_voidInit();
	TIMER1_voidSetCTCA((time*1000)-1);
	TIMER_u8SetCallBack(LocalFptr,TIMER1_CTCA_VECTOR_ID);
	Timer1_OCA_InterruptEnable();	
}

void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void))
{
	TIMER1_voidInit();
	TIMER1_voidSetCTCA((time)-1);
	TIMER_u8SetCallBack(LocalFptr,TIMER1_CTCA_VECTOR_ID);
	Timer1_OCA_InterruptEnable();
}

/**********************************************Measure PWM SW*********************************************************/
void PWM_Measure_SW(u32* Pfreq,u8* Pduty){
	ICU_Init();
	while(period==0);
	*Pfreq=(u32)(1000000UL/(u32)period);
	*Pduty=(u8)(((u32)t_on*100UL)/(u32)period);
}

static void ICU_Init(void)
{
#if ICU_EXTI_CHANNEL == EX_INT0
	DIO_Enu_SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
#elif ICU_EXTI_CHANNEL == EX_INT1
	DIO_Enu_SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8INPUT);
#elif ICU_EXTI_CHANNEL == EX_INT2
	DIO_Enu_SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8INPUT);
#endif

	EXI_TriggerEdge(ICU_EXTI_CHANNEL, RISING_EDGE);
	EXI_SetCallBack(ICU_EXTI_CHANNEL, EXTI_Callback);
	EXI_Enable(ICU_EXTI_CHANNEL);
	TIMER1_voidInit();
	TIMER1_voidSetPreload(0);
}
static void EXTI_Callback(void)
{
	static u8 state = ICU_STATE_WAIT_FOR_RISINGEDGE1;

	switch(state)
	{
	case ICU_STATE_WAIT_FOR_RISINGEDGE1:
		TIMER1_voidSetPreload(0);
		EXI_TriggerEdge(ICU_EXTI_CHANNEL,FALLING_EDGE);
		state = ICU_STATE_WAIT_FOR_FALLINGEDGE;
		break;
	case ICU_STATE_WAIT_FOR_FALLINGEDGE:
		EXI_TriggerEdge(ICU_EXTI_CHANNEL,RISING_EDGE);
		t_on = TIMER1_u16GetTimerCounterValue();
		state = ICU_STATE_WAIT_FOR_RISINGEDGE2;
		break;
	case ICU_STATE_WAIT_FOR_RISINGEDGE2:
		EXI_TriggerEdge(ICU_EXTI_CHANNEL,RISING_EDGE);
		period = TIMER1_u16GetTimerCounterValue();
		state = ICU_STATE_WAIT_FOR_RISINGEDGE1;
		break;
	}
}

void PWM_Measure2(u32* Pfreq,u8* Pduty)
{
	u8 signal;
	TIMER1_voidInit();
	TIMER1_voidSetPreload(0);
	do{
	DIO_Enu_GetPinValue(SIGNAL_PORT,SIGNAL_PIN,&signal);
	}while(signal!=0);
	do{
	DIO_Enu_GetPinValue(SIGNAL_PORT,SIGNAL_PIN,&signal);
	}while(signal!=1);
	TIMER1_voidSetPreload(0);
	do{
	DIO_Enu_GetPinValue(SIGNAL_PORT,SIGNAL_PIN,&signal);
	}while(signal==1);
	Ton=TIMER1_u16GetTimerCounterValue();
	TIMER1_voidSetPreload(0);
	do{
	DIO_Enu_GetPinValue(SIGNAL_PORT,SIGNAL_PIN,&signal);
	}while(signal!=1);
	Toff=TIMER1_u16GetTimerCounterValue();
	*Pduty=(u8)(((u32)Ton*100UL)/((u32)Ton+Toff));
	*Pfreq=(u32)(1000000UL/((u32)Toff+Ton));
}

/**********************************************Measure PWM HW*********************************************************/

void PWM_Measure_HW(u32* Pfreq,u8* Pduty)
{
	DIO_Enu_SetPinDirection(DIO_u8PORTD,DIO_u8PIN6,DIO_u8INPUT);
	TIMER1_voidInit();
	TIMER_voidICUEnableInterrupt();
	TIMER_u8SetCallBack(Func_ICU_HW,TIMER1_ICU_VECTOR_ID);
	TIMER_voidICUSetTriggerEdge(ICP_RAISING_EDGE);
	TIMER1_voidSetPreload(0);
	while(period==0);
	*Pfreq=(u32)(1000000UL/(u32)period);
	*Pduty=(u8)(((u32)t_on*100UL)/(u32)period);

}

static void Func_ICU_HW(void)
{
	static u8 state = FASTICU_FIRST_RISING;
	static u16 point_1 = 0;
	static u16 point_2 = 0;
	static u16 point_3 = 0;

	switch(state)
	{
	case FASTICU_FIRST_RISING:
		point_1 = TIMER_u16GetICR();
		TIMER_voidICUSetTriggerEdge(ICP_FALLING_EDGE);
		state = FASTICU_FALLING;
		break;
	case FASTICU_FALLING:
		point_2 = TIMER_u16GetICR();
		TIMER_voidICUSetTriggerEdge(ICP_RAISING_EDGE);
		state = FASTICU_SECOND_RISING;
		break;
	case FASTICU_SECOND_RISING:
		point_3 = TIMER_u16GetICR();
		TIMER_voidICUSetTriggerEdge(ICP_RAISING_EDGE);
		state = FASTICU_FIRST_RISING;
		t_on =   point_2 - point_1;
		period = point_3 - point_1;
		break;
	}	
}
