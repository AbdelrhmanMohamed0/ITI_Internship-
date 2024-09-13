
#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../1_MCAL/DIO/DIO_INTERFACE.h"
#include "LED_CONFIG.h"
#include "LED_PRIVATE.h"

LED_t LED_Arr_Str_LedConfig [LED_NUM] =
{
		{DIO_u8PORTC, DIO_u8PIN0, LED_SOURCE, LED_OFF},
		{DIO_u8PORTC, DIO_u8PIN1, LED_SOURCE, LED_OFF},
};
