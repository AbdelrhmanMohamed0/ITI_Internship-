#include "../../4_LIB/STD_TYPES.h"
#include "../../4_LIB/ERROR_STATES.h"
#include "../../1_MCAL/DIO/DIO_INTERFACE.h"
#include "SWITCH_PRIVATE.h"
#include "SWITCH_CONFIG.h"


// make extern from this array into your app.c extern SW_t Switch_Arr_Stru_SwitchState [SW_NUM];

SW_t Switch_Arr_Stru_SwitchState [SW_NUM] =
{
//	    u8 SW_PortID , u8 SW_PinID , u8 SW_Status 
		{DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PULL_UP}
};
