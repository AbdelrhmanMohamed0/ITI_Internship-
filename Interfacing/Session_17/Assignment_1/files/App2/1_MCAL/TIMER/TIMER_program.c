#include "../../4_LIB/STD_TYPES.h"
#include "../../4_LIB/BIT_MATH.h"
#include "../../4_LIB/ERROR_STATES.h"

#include "TIMER_private.h" 
#include "TIMER_register.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"


/*Global Pointer to array of Function to Hold the Call Back Function Address for Timer*/
static void (*TIMERS_pvCallBackFunc[16])(void) = {NULL} ;  /* we have 8 interrupt sources in timer  */


/*******************************************************************************************************************/
void TIMER0_voidInit(void)
{
	/*Set Configurable Modes*/
		#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE

			/*Initialize Waveform Generation Mode as Normal Mode*/
			CLR_BIT(TCCR0 , TCCR0_WGM00) ;
			CLR_BIT(TCCR0 , TCCR0_WGM01) ;

			/*Set the Required Preload Value*/
			TCNT0 = TIMER0_PRELOAD_VAL ;

			/*Timer0 Overflow Interrupt Enable*/
			#if TIMER0_OVERFLOW_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_TOIE0) ;
			#elif TIMER0_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_TOIE0) ;
			#else
				#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
			#endif

		#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
			/*Initialize Waveform Generation Mode as PWM Mode*/
			SET_BIT(TCCR0 , TCCR0_WGM00) ;
			CLR_BIT(TCCR0 , TCCR0_WGM01) ;

			/*Set CTC PWM MODE*/
			#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR0 , TCCR0_COM00) ;
					CLR_BIT(TCCR0 , TCCR0_COM01) ;
			#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_up_count_SET_ON_down_count
					CLR_BIT(TCCR0 , TCCR0_COM00) ;
					SET_BIT(TCCR0 , TCCR0_COM01) ;
			#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_up_count_CLR_ON_down_count
					SET_BIT(TCCR0 , TCCR0_COM00) ;
					SET_BIT(TCCR0 , TCCR0_COM01) ;
			#else
					#error "Wrong TIMER0_CTC_PWM_MODE Config"
			#endif

			/*Set the Required CTC Value*/
			OCR0 = TIMER0_CTC_VAL ;

		#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE

			/*Initialize Waveform Generation Mode as CTC Mode*/
			CLR_BIT(TCCR0 , TCCR0_WGM00) ;
			SET_BIT(TCCR0 , TCCR0_WGM01) ;

			/*Set the Required CTC Value*/
			OCR0 = TIMER0_CTC_VAL ;
            /*Set OCR0 mode*/
            #if TIMER0_OC0_MODE == TIMER_OC_DISCONNECTED
            CLR_BIT(TCCR0 , TCCR0_COM00) ;
            CLR_BIT(TCCR0 , TCCR0_COM01) ;
            #elif TIMER0_OC0_MODE == TIMER_OC_TOGGEL
            SET_BIT(TCCR0 , TCCR0_COM00) ;
            CLR_BIT(TCCR0 , TCCR0_COM01) ;
            #elif TIMER0_OC0_MODE == TIMER_OC_LOW
            CLR_BIT(TCCR0 , TCCR0_COM00) ;
            SET_BIT(TCCR0 , TCCR0_COM01) ;
            #elif TIMER0_OC0_MODE == TIMER_OC_HIGH
            SET_BIT(TCCR0 , TCCR0_COM00) ;
            SET_BIT(TCCR0 , TCCR0_COM01) ;
            #else
            #error "Wrong TIMER1_OCR1A_MODE Config"
            #endif
			/*Timer0 Compare Match Interrupt Enable*/
			#if TIMER0_CTC_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE0) ;
			#elif TIMER0_CTC_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE0) ;
			#else
				#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
			#endif

		#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

			/*Initialize Waveform Generation Mode as Fast PWM Mode*/
			SET_BIT(TCCR0 , TCCR0_WGM00) ;
			SET_BIT(TCCR0 , TCCR0_WGM01) ;

			/*Set CTC Fast PWM MODE*/
			#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR0 , TCCR0_COM00) ;
					CLR_BIT(TCCR0 , TCCR0_COM01) ;
			#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
					CLR_BIT(TCCR0 , TCCR0_COM00) ;
					SET_BIT(TCCR0 , TCCR0_COM01) ;
			#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
					SET_BIT(TCCR0 , TCCR0_COM00) ;
					SET_BIT(TCCR0 , TCCR0_COM01) ;
			#else
					#error "Wrong TIMER0_CTC_PWM_MODE Config"
			#endif

			/*Set the Required CTC Value*/
			OCR0 = TIMER0_CTC_VAL ;

		#else
			#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"

		#endif

	/*Set the Required Prescaler*/
	TCCR0 &= TIMER_PRESCALER_MASK ;
	TCCR0 |= TIMER0_PRESCALER ;
}

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

void TIMER2_voidInit(void)
{
	/*Set Configurable Modes*/
		#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE

			/*Initialize Waveform Generation Mode as Normal Mode*/
			CLR_BIT(TCCR2 , TCCR2_WGM20) ;
			CLR_BIT(TCCR2 , TCCR2_WGM21) ;

			/*Set the Required Preload Value*/
			TCNT2 = TIMER2_PRELOAD_VAL ;

			/*Timer2 Overflow Interrupt Enable*/
			#if TIMER2_OVERFLOW_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_TOIE2) ;
			#elif TIMER2_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_TOIE2) ;
			#else
				#error "Wrong TIMER2_OVERFLOW_INTERRUPT Config"
			#endif

		#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
			/*Initialize Waveform Generation Mode as PWM Mode*/
			SET_BIT(TCCR2 , TCCR2_WGM20) ;
			CLR_BIT(TCCR2 , TCCR2_WGM21) ;

		#define TIMER0_CTC_PWM_MODE						TIMER_CLR_ON_CTC_up_count_SET_ON_down_count

			/*Set CTC PWM MODE*/
			#if TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR2 , TCCR2_COM20) ;
					CLR_BIT(TCCR2 , TCCR2_COM21) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_up_count_SET_ON_down_count
					CLR_BIT(TCCR2 , TCCR2_COM20) ;
					SET_BIT(TCCR2 , TCCR2_COM21) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_up_count_CLR_ON_down_count
					SET_BIT(TCCR2 , TCCR2_COM20) ;
					SET_BIT(TCCR2 , TCCR2_COM21) ;
			#else
					#error "Wrong TIMER2_CTC_PWM_MODE Config"
			#endif

			/*Set the Required CTC Value*/
			OCR2 = TIMER2_CTC_VAL ;

		#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE

			/*Initialize Waveform Generation Mode as CTC Mode*/
			CLR_BIT(TCCR2 , TCCR2_WGM20) ;
			SET_BIT(TCCR2 , TCCR2_WGM21) ;

			/*Set the Required CTC Value*/
			OCR2 = TIMER2_CTC_VAL ;
            /*Set OCR2 mode*/
            #if TIMER2_OC2_MODE == TIMER_OC_DISCONNECTED
            CLR_BIT(TCCR2 , TCCR2_COM20) ;
            CLR_BIT(TCCR2 , TCCR2_COM21) ;
            #elif TIMER2_OC2_MODE == TIMER_OC_TOGGEL
            SET_BIT(TCCR2 , TCCR2_COM20) ;
            CLR_BIT(TCCR2 , TCCR2_COM21) ;
            #elif TIMER2_OC2_MODE == TIMER_OC_LOW
            CLR_BIT(TCCR2 , TCCR2_COM20) ;
            SET_BIT(TCCR2 , TCCR2_COM21) ;
            #elif TIMER2_OC2_MODE == TIMER_OC_HIGH
            SET_BIT(TCCR2 , TCCR2_COM20) ;
            SET_BIT(TCCR2 , TCCR2_COM21) ;
            #else
            #error "Wrong TIMER1_OCR1A_MODE Config"
            #endif
			/*Timer2 Compare Match Interrupt Enable*/
			#if TIMER2_CTC_INTERRUPT == DISABLE
				CLR_BIT(TIMSK , TIMSK_OCIE2) ;
			#elif TIMER2_CTC_INTERRUPT == ENABLE
				SET_BIT(TIMSK , TIMSK_OCIE2) ;
			#else
				#error "Wrong TIMER2_OVERFLOW_INTERRUPT Config"
			#endif

		#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

			/*Initialize Waveform Generation Mode as Fast PWM Mode*/
			SET_BIT(TCCR2 , TCCR2_WGM20) ;
			SET_BIT(TCCR2 , TCCR2_WGM21) ;

			/*Set CTC Fast PWM MODE*/
			#if TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR2 , TCCR2_COM20) ;
					CLR_BIT(TCCR2 , TCCR2_COM21) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
					CLR_BIT(TCCR2 , TCCR2_COM20) ;
					SET_BIT(TCCR2 , TCCR2_COM21) ;
			#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
					SET_BIT(TCCR2 , TCCR2_COM20) ;
					SET_BIT(TCCR2 , TCCR2_COM21) ;
			#else
					#error "Wrong TIMER2_CTC_PWM_MODE Config"
			#endif

			/*Set the Required CTC Value*/
			OCR2 = TIMER2_CTC_VAL ;

		#else
			#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"

		#endif

	/*Set the Required Prescaler*/
	TCCR2 &= TIMER_PRESCALER_MASK ;
	TCCR2 |= TIMER2_PRESCALER ;
}

/*******************************************************************************************************************/
void TIMER0_voidSetPreload (u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload ;
}

void TIMER1_voidSetPreload (u16 Copy_u16Preload)
{
	TCNT1 = Copy_u16Preload ;
}


void TIMER2_voidSetPreload (u8 Copy_u8Preload)
{
	TCNT2 = Copy_u8Preload ;
}

void TIMER0_voidSetCTC (u8 Copy_u8CTC)
{
	OCR0 = Copy_u8CTC ;
}

void TIMER1_voidSetCTCA (u16 Copy_u16CTCA)//ton
{
	OCR1A = Copy_u16CTCA ;
}

void TIMER1_voidSetCTCB (u16 Copy_u16CTCB)
{
	OCR1B = Copy_u16CTCB ;
}

void TIMER2_voidSetCTC (u8 Copy_u8CTC)
{
	OCR2 = Copy_u8CTC ;
}

void TIMER1_voidSetICR1 (u16 Copy_u16ICR1)//period
{
	ICR1 = Copy_u16ICR1 ;
}

u8 TIMER0_u8GetTimerCounterValue (void)
{
	return TCNT0 ;
}

u16 TIMER1_u16GetTimerCounterValue (void)
{
	return TCNT1 ;
}

u8 TIMER2_u8GetTimerCounterValue (void)
{
	return TCNT2 ;
}

/*******************************************************************************************************************/
u8 GET_PERSCALER_SELECT(u8 TIMER_NUM){
	u16 prescaler=0;
#if TIMER_NUM ==TIMER0
#if TIMER0_PRESCALER == TIMER_NO_CLOCK_SOURCE
	prescaler=0;
#elif TIMER0_PRESCALER ==TIMER_NO_PRESCALER_FACTOR
	prescaler=0;
#elif TIMER0_PRESCALER ==TIMER_DIVISION_FACTOR_8
	prescaler=8;
#elif TIMER0_PRESCALER ==TIMER_DIVISION_FACTOR_64
	prescaler=64;
#elif TIMER0_PRESCALER ==TIMER_DIVISION_FACTOR_256
	prescaler=256;
#elif TIMER0_PRESCALER ==TIMER_DIVISION_FACTOR_1024
	prescaler=1024;
#endif

#elif TIMER_NUM ==TIMER1
#if TIMER1_PRESCALER == TIMER_NO_CLOCK_SOURCE
	prescaler=0;
#elif TIMER1_PRESCALER ==TIMER_NO_PRESCALER_FACTOR
	prescaler=0;
#elif TIMER1_PRESCALER ==TIMER_DIVISION_FACTOR_8
	prescaler=8;
#elif TIMER1_PRESCALER ==TIMER_DIVISION_FACTOR_64
	prescaler=64;
#elif TIMER1_PRESCALER ==TIMER_DIVISION_FACTOR_256
	prescaler=256;
#elif TIMER1_PRESCALER ==TIMER_DIVISION_FACTOR_1024
	prescaler=1024;
#endif

#elif TIMER_NUM ==TIMER2
#if TIMER2_PRESCALER == TIMER_NO_CLOCK_SOURCE
	prescaler=0;
#elif TIMER2_PRESCALER ==TIMER_NO_PRESCALER_FACTOR
	prescaler=0;
#elif TIMER2_PRESCALER ==TIMER_DIVISION_FACTOR_8
	prescaler=8;
#elif TIMER2_PRESCALER ==TIMER_DIVISION_FACTOR_64
	prescaler=64;
#elif TIMER2_PRESCALER ==TIMER_DIVISION_FACTOR_256
	prescaler=256;
#elif TIMER2_PRESCALER ==TIMER_DIVISION_FACTOR_1024
	prescaler=1024;
#endif

#endif
return prescaler;
}

void Generate_PWM_SW(u32 freq,u8 duty){
	u32 top ;
	u16 temp_OCR;
#if GENERATE_PWM_PIN == OC1A
	TIMER1_voidInit();
	top = (F_CPU / (freq * GET_PERSCALER_SELECT(TIMER1))) - 1;
	temp_OCR=(duty * (top + 1)) / 100 - 1;
	TIMER1_voidSetICR1(top);
	TIMER1_voidSetCTCA(temp_OCR);
#elif GENERATE_PWM_PIN == OC1B
	TIMER1_voidInit();
	top = (F_CPU / (freq * GET_PERSCALER_SELECT(TIMER1))) - 1;
	temp_OCR=(duty * (top + 1)) / 100 - 1;
	TIMER1_voidSetICR1(top);
	TIMER1_voidSetCTCB(temp_OCR);
#endif
}

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
void Timer0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TOIE0);
}
void Timer0_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TOIE0);
}
void Timer0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_OCIE0);
}

void Timer0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_OCIE0);
}

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

void Timer2_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TOIE2);
}
void Timer2_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TOIE2);
}
void Timer2_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_OCIE2);
}

void Timer2_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_OCIE2);
}



u16 TIMER_u16GetICR(void)
{
	return ICR1;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

/* Hint : prebuild config  */
void TIMER_voidWDTSleep(void)
{
	/* CLear The Prescaler bits  */
	WDTCR &= WDT_PS_MASKING ;
	/* Set The required prescaller */
	WDTCR |= WDT_PRESCALER ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void TIMER_voidWDTEnable (void)
{
	SET_BIT (WDTCR , WDTCR_WDE);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void TIMER_voidWDTDisable (void)
{
	/* Set Bit 3&4 at the same CLK cycle  */
	WDTCR |= 0b00011000 ;
	/* WDTCR_WDE = 0 */
	/* I don't care for any value in this Reg Cuz I want to Disable */
	WDTCR = 0 ;
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

/*TIMER0 Normal Mode ISR*/
void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID]() ;
	}
}

/*TIMER0 CTC Mode ISR*/
void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID]() ;
	}
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

/*TIMER2 Normal Mode ISR*/
void __vector_5 (void)		__attribute__((signal)) ;
void __vector_5 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID]() ;
	}
}

/*TIMER2 CTC Mode ISR*/
void __vector_4 (void)		__attribute__((signal)) ;
void __vector_4 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID]() ;
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
