#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

	/*Timer1 Config*/

	/*Set Timer1 Waveform Generation Mode
	 * Choose between
	 * 1. TIMER1_NORMAL_MODE
	 * 2. TIMER1_PWM_8_BIT_MODE
	 * 3. TIMER1_PWM_9_BIT_MODE
	 * 4. TIMER1_PWM_10_BIT_MODE
	 * 5. TIMER1_CTC_OCR1A_MODE
	 * 6. TIMER1_FAST_PWM_8_BIT_MODE
	 * 7. TIMER1_FAST_PWM_9_BIT_MODE
	 * 8. TIMER1_FAST_PWM_10_BIT_MODE
	 * 9. TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
	 * 10.TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
	 * 11.TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	 * 12.TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
	 * 13.TIMER1_CTC_ICR1_MODE
	 * 14.TIMER1_FAST_PWM_ICR1_MODE
	 * 15.TIMER1_FAST_PWM_OCR1A_MODE
	 */
	#define TIMER1_WAVEFORM_GENERATION_MODE		TIMER1_FAST_PWM_ICR1_MODE

	/*Set the Required Prescaler
	 * Choose between
	 * - TIMER_NO_CLOCK_SOURCE
	 * - TIMER_NO_PRESCALER_FACTOR
	 * - TIMER_DIVISION_FACTOR_8
	 * - TIMER_DIVISION_FACTOR_64
	 * - TIMER_DIVISION_FACTOR_256
	 * - TIMER_DIVISION_FACTOR_1024
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
	 */
	#define TIMER1_PRESCALER					TIMER_DIVISION_FACTOR_8

	/*Set Preload Value for Normal Mode*/
	#define TIMER1_PRELOAD_VAL					0

	/*Set CTCA Value*/
	#define TIMER1_CTCA_VAL						700      //Duty

	/*Set CTCB Value*/
	#define TIMER1_CTCB_VAL						0

	/*Set Input Capture Value*/
	#define TIMER1_ICR1_VAL						20000    //period

	/*Set Compare Match Output for OCR1A
	 * Choose between
	 * 		CTC mode				||	PWM & FAST PWM mode
	 *
	 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
	 * 2. TIMER_OC_TOGGEL			||
	 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_SET_ON_TOP
	 * 4. TIMER_OC_HIGH				|| TIMER_SET_ON_CTC_CLR_ON_TOP
	 */
	#define TIMER1_OCR1A_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP

	/*Set Compare Match Output for OCR1A
	 * Choose between
	 *
	 * 		CTC mode				||	PWM & FAST PWM mode
	 *
	 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
	 * 2. TIMER_OC_TOGGEL			||
	 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_SET_ON_TOP
	 * 4. TIMER_OC_HIGH				|| TIMER_SET_ON_CTC_CLR_ON_TOP
	 */
	#define TIMER1_OCR1B_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP

	/*Set Timer1 Input Capture Noise Canceler
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_NOISE_CANCELER			DISABLE

	/*Set Timer1 Input Capture Edge
	 * Choose between
	 * 1. FALLING_EDGE
	 * 2. RISING_EDGE
	 */
	#define TIMER1_ICR_EDGE				RISING_EDGE

	/*Set Timer1 Overflow Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_OVERFLOW_INTERRUPT			DISABLE

	/*Set Timer1 CTCB Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_CTCB_INTERRUPT			DISABLE

	/*Set Timer1 CTCA Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_CTCA_INTERRUPT			DISABLE

	/*Set Timer1 Input Capture Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_INTERRUPT			DISABLE

#endif /* TIMER_CONFIG_H_ */
