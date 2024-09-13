#include "../../../4_LIB/STD_TYPES.h"
#include "../../../4_LIB/ERROR_STATES.h"
#include "../../../1_MCAL/DIO/DIO_INTERFACE.h"

#include "Seven_segment_CONFIG.h"
#include "Seven_segment_PRIVATE.h"

SEG_t SEVSEG_AstrSegConfig [SEG_NUM] =
{
		{DIO_u8PORTA , DIO_u8PIN1 , //pin a
		 DIO_u8PORTA , DIO_u8PIN2 , //pin b
		 DIO_u8PORTA , DIO_u8PIN3 , //pin c
		 DIO_u8PORTA , DIO_u8PIN4 , //pin d
		 DIO_u8PORTA , DIO_u8PIN5 , //pin e
		 DIO_u8PORTA , DIO_u8PIN6 , //pin f
		 DIO_u8PORTA , DIO_u8PIN7 , //pin g
		 NOT_CONNECTED , NOT_CONNECTED , //pin cmn
		 NOT_CONNECTED , NOT_CONNECTED , //pin dot
		 COMMON_CATHODE //type
		} , //seg 0

		{DIO_u8PORTC , DIO_u8PIN0 , //pin a
		 DIO_u8PORTC , DIO_u8PIN1 , //pin b
		 DIO_u8PORTC , DIO_u8PIN2 , //pin c
		 DIO_u8PORTC , DIO_u8PIN3 , //pin d
		 DIO_u8PORTC , DIO_u8PIN4 , //pin e
		 DIO_u8PORTC , DIO_u8PIN5 , //pin f
		 DIO_u8PORTC , DIO_u8PIN6 , //pin g
		 NOT_CONNECTED , NOT_CONNECTED , //pin cmn
		 NOT_CONNECTED , NOT_CONNECTED , //pin dot
		 COMMON_CATHODE //type
		} // seg 1
};
