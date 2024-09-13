#include "../../4_LIB/STD_TYPES.h"
#include "../../4_LIB/BIT_MATH.h"
#include "../../4_LIB/ERROR_STATES.h"

#include "TIMER_private.h" 
#include "TIMER_register.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"


/*Global Pointer to array of Function to Hold the Call Back Function Address for Timer*/
static void (*TIMERS_pvCallBackFunc[16])(void) = {NULL} ;  /* we have 8 interrupt sources in timer  */


void TIMER1_voidInit(void)
{

	/*Set Configurable Modes*/

		#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_NORMAL_MODE

			/*Set Waveform generation mode as Normal mode */
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);

			/*Set the require Preload Value*/
			TCNT1 = TIMER1_PRELOAD_VAL ;

			/*Timer1 Overflow Interrupt Enable*/
			#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_TOIE1) ;
			#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_TOIE1) ;
			#else
				#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
			#endif

		#elif (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE)

			/*Set Waveform generation mode as CTC modes */
			#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE
				CLR_BIT(TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1B,TCCR1B_WGM12);
				SET_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_OCR1A_MODE
				CLR_BIT(TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#else
				#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
			#endif

			/*Set the require CTC Values*/
			OCR1A = TIMER1_CTCA_VAL ;
			OCR1B = TIMER1_CTCB_VAL ;

			/*Set ICR1 if TIMER1_CTC_OCR1A_MODE = TIMER1_CTC_ICR1_MODE*/
			#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE
				ICR1 = TIMER1_ICR1_VAL ;

				#if TIMER1_ICR_EDGE == RISING_EDGE
					SET_BIT(TCCR1B , TCCR1B_ICES1) ;
				#elif TIMER1_ICR_EDGE == FALLING_EDGE
					CLR_BIT(TCCR1B , TCCR1B_ICES1) ;
				#else
				#error "Wrong TIMER1_ICR_EDGE Config"
				#endif

			#else
				/*Do nothing*/
			#endif

			/*Set OCR1A mode*/
			#if TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR1A , TCCR1A_COM1A0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#elif TIMER1_OCR1A_MODE == TIMER_OC_TOGGEL
				SET_BIT(TCCR1A , TCCR1A_COM1A0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#elif TIMER1_OCR1A_MODE == TIMER_OC_LOW
				CLR_BIT(TCCR1A , TCCR1A_COM1A0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#elif TIMER1_OCR1A_MODE == TIMER_OC_HIGH
				SET_BIT(TCCR1A , TCCR1A_COM1A0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#else
				#error "Wrong TIMER1_OCR1A_MODE Config"
			#endif

			/*Set OCR1B mode*/
			#if TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR1A , TCCR1A_COM1B0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#elif TIMER1_OCR1B_MODE == TIMER_OC_TOGGEL
				SET_BIT(TCCR1A , TCCR1A_COM1B0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#elif TIMER1_OCR1B_MODE == TIMER_OC_LOW
				CLR_BIT(TCCR1A , TCCR1A_COM1B0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#elif TIMER1_OCR1B_MODE == TIMER_OC_HIGH
				SET_BIT(TCCR1A , TCCR1A_COM1B0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#else
				#error "Wrong TIMER1_OCR1B_MODE Config"
			#endif

			/*Timer1 CTC Interrupt Enable*/
			#if TIMER1_CTCA_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE1A) ;
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE1A) ;
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif

			#if TIMER1_CTCB_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE1B) ;
			#elif TIMER1_CTCB_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE1B) ;
			#else
				#error "Wrong TIMER1_CTCB_INTERRUPT Config"
			#endif

		#elif (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE) ||(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_10_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_9_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_8_BIT_MODE)

			/*Set Waveform generation mode as PWM modes */
			#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TCCR1B,TCCR1B_WGM12);
				SET_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
				CLR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TCCR1B,TCCR1B_WGM12);
				SET_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
				CLR_BIT(TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TCCR1B,TCCR1B_WGM12);
				SET_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_10_BIT_MODE
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_9_BIT_MODE
				CLR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_8_BIT_MODE
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#else
				#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
			#endif

			/*Set the require CTC Values*/
			OCR1A = TIMER1_CTCA_VAL ;
			OCR1B = TIMER1_CTCB_VAL ;

			/*Set ICR1*/
			#if ((TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE))
				ICR1 = TIMER1_ICR1_VAL ;

				#if TIMER1_ICR_EDGE == RISING_EDGE
					SET_BIT(TCCR1B , TCCR1B_ICES1) ;
				#elif TIMER1_ICR_EDGE == FALLING_EDGE
					CLR_BIT(TCCR1B , TCCR1B_ICES1) ;
				#else
				#error "Wrong TIMER1_ICR_EDGE Config"
				#endif
			#else
				/*Do nothing*/
			#endif

			/*Set OCR1A mode*/
			#if TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR1A , TCCR1A_COM1A0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#elif TIMER1_OCR1A_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TCCR1A , TCCR1A_COM1A0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#elif TIMER1_OCR1A_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TCCR1A , TCCR1A_COM1A0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#else
				#error "Wrong TIMER1_OCR1A_MODE Config"
			#endif

			/*Set OCR1B mode*/
			#if TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR1A , TCCR1A_COM1B0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#elif TIMER1_OCR1B_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TCCR1A , TCCR1A_COM1B0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#elif TIMER1_OCR1B_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TCCR1A , TCCR1A_COM1B0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#else
				#error "Wrong TIMER1_OCR1B_MODE Config"
			#endif

			/*Timer1 PWM Interrupt Enable*/
			#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_TOIE1) ;
			#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_TOIE1) ;
			#else
				#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
			#endif

			#if TIMER1_CTCA_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE1A) ;
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE1A) ;
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif

			#if TIMER1_CTCB_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE1B) ;
			#elif TIMER1_CTCB_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE1B) ;
			#else
				#error "Wrong TIMER1_CTCB_INTERRUPT Config"
			#endif

			#if TIMER1_ICR_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_TICIE1) ;
			#elif TIMER1_ICR_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_TICIE1) ;
			#else
				#error "Wrong TIMER1_ICR1_INTERRUPT Config"
			#endif


		#elif (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_10_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_9_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_8_BIT_MODE)

			/*Set Waveform generation mode as PWM modes */
			#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_OCR1A_MODE
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1B,TCCR1B_WGM12);
				SET_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE
				CLR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1B,TCCR1B_WGM12);
				SET_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_10_BIT_MODE
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_9_BIT_MODE
				CLR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_8_BIT_MODE
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1B,TCCR1B_WGM12);
				CLR_BIT(TCCR1B,TCCR1B_WGM13);
			#else
				#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
			#endif

			/*Set the require CTC Values*/
			OCR1A = TIMER1_CTCA_VAL ;
			OCR1B = TIMER1_CTCB_VAL ;

			/*Set ICR1*/
			#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE
				ICR1 = TIMER1_ICR1_VAL ;

				#if TIMER1_ICR_EDGE == RISING_EDGE
					SET_BIT(TCCR1B , TCCR1B_ICES1) ;
				#elif TIMER1_ICR_EDGE == FALLING_EDGE
					CLR_BIT(TCCR1B , TCCR1B_ICES1) ;
				#else
				#error "Wrong TIMER1_ICR_EDGE Config"
				#endif
			#else
				/*Do nothing*/
			#endif

			/*Set OCR1A mode*/
			#if TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR1A , TCCR1A_COM1A0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#elif TIMER1_OCR1A_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TCCR1A , TCCR1A_COM1A0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#elif TIMER1_OCR1A_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TCCR1A , TCCR1A_COM1A0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1A1) ;
			#else
				#error "Wrong TIMER1_OCR1A_MODE Config"
			#endif

			/*Set OCR1B mode*/
			#if TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR1A , TCCR1A_COM1B0) ;
				CLR_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#elif TIMER1_OCR1B_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TCCR1A , TCCR1A_COM1B0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#elif TIMER1_OCR1B_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TCCR1A , TCCR1A_COM1B0) ;
				SET_BIT(TCCR1A , TCCR1A_COM1B1) ;
			#else
				#error "Wrong TIMER1_OCR1B_MODE Config"
			#endif

			/*Timer1 PWM Interrupt Enable*/
			#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_TOIE1) ;
			#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_TOIE1) ;
			#else
				#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
			#endif

			#if TIMER1_CTCA_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE1A) ;
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE1A) ;
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif

			#if TIMER1_CTCB_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE1B) ;
			#elif TIMER1_CTCB_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE1B) ;
			#else
				#error "Wrong TIMER1_CTCB_INTERRUPT Config"
			#endif

			#if TIMER1_ICR_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_TICIE1) ;
			#elif TIMER1_ICR_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_TICIE1) ;
			#else
				#error "Wrong TIMER1_ICR1_INTERRUPT Config"
			#endif
		#else
			#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
		#endif

	/*Set the Required Prescaler*/
	TCCR1B &= TIMER_PRESCALER_MASK ;
	TCCR1B |= TIMER1_PRESCALER ;


}


void TIMER1_voidSetPreload (u16 Copy_u16Preload)
{
	TCNT1 = Copy_u16Preload ;
}



void TIMER1_voidSetCTCA (u16 Copy_u16CTCA)//ton
{
	OCR1A = Copy_u16CTCA ;
}

void TIMER1_voidSetCTCB (u16 Copy_u16CTCB)
{
	OCR1B = Copy_u16CTCB ;
}



void TIMER1_voidSetICR1 (u16 Copy_u16ICR1)//period
{
	ICR1 = Copy_u16ICR1 ;
}



u16 TIMER1_u16GetTimerCounterValue (void)
{
	return TCNT1 ;
}



/*******************************************************************************************************************/

void TIMER_voidSetPWM(u16 Copy_u16CompareValue)
{
	OCR1A = Copy_u16CompareValue;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
	Hint : This func for initial state of trigger (prebuild)
*/
void TIMER_voidICUInitEnable(void)
{
	/* Set trigger source as rising edge Initially  */
	#if (TIMER_u8_ICP_INIT_STATE == TIMER_u8_ICP_RAISING_EDGE)
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	#elif(TIMER_u8_ICP_INIT_STATE == TIMER_u8_ICP_FALLING_EDGE)
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	#endif

	/* Enable Interrupt of ICU */
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
	Hint : This func for change the trigger state (postbuild)
	Options :-
	 1- TIMER_u8_ICP_RAISING_EDGE
	 2- TIMER_u8_ICP_FALLING_EDGE
*/
ES_t TIMER_voidICUSetTriggerEdge(u8 Copy_u8Edge)
{
	ES_t Local_u8ErrorStatus = ES_OK ;

	/* Change The trigger source as Rising edge or Falling edge */
	if (Copy_u8Edge == TIMER_u8_ICP_RAISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_u8Edge == TIMER_u8_ICP_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		Local_u8ErrorStatus = ES_NOT_OK ;
	}
	return Local_u8ErrorStatus;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void TIMER_voidICUEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------

void TIMER_voidICUDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_OCIE1B);
}




u16 TIMER_u16GetICR(void)
{
	return ICR1;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

ES_t TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID)
{
	ES_t Local_u8ErrorState = ES_OK ;

	if (Copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFunc[Copy_u8VectorID] = Copy_pvCallBackFunc ;
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

/*TIMER1 Normal Mode ISR*/
void __vector_9 (void)		__attribute__((signal)) ;
void __vector_9 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_OVF_VECTOR_ID]() ;
	}
}

/*TIMER1 CTCB Mode ISR*/
void __vector_8 (void)		__attribute__((signal)) ;
void __vector_8 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_CTCB_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_CTCB_VECTOR_ID]() ;
	}
}

/*TIMER1 CTCA Mode ISR*/
void __vector_7 (void)		__attribute__((signal)) ;
void __vector_7 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_CTCA_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_CTCA_VECTOR_ID]() ;
	}
}

/*TIMER1 ICU ISR*/
void __vector_6 (void)		__attribute__((signal)) ;
void __vector_6 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_ICU_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_ICU_VECTOR_ID]() ;
	}
}
