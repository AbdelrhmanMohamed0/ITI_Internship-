#include <util/delay.h>

#include "../../4_LIB/STD_TYPES.h"
#include "../../4_LIB/BIT_MATH.h"
#include "../../4_LIB/ERROR_STATES.h"
#include "../../1_MCAL/DIO/DIO_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"
#include "KEYPAD_PRIVATE.h"
#include "KEYPAD_CONFIG.h"

ES_t KPD_enu_Init(void)
{
	ES_t Local_EnuErrorState = ES_NOT_OK;

	/*This code equivalent to connect pull up for the pins of the rows */

	DIO_Enu_SetPinDirection(KPD_PORT, KPD_R0, DIO_u8INPUT);
	DIO_Enu_SetPinDirection(KPD_PORT, KPD_R1, DIO_u8INPUT);
	DIO_Enu_SetPinDirection(KPD_PORT, KPD_R2, DIO_u8INPUT);
	DIO_Enu_SetPinDirection(KPD_PORT, KPD_R3, DIO_u8INPUT);

	DIO_Enu_SetPinValue(KPD_PORT, KPD_R0, DIO_u8HIGH);
	DIO_Enu_SetPinValue(KPD_PORT, KPD_R1, DIO_u8HIGH);
	DIO_Enu_SetPinValue(KPD_PORT, KPD_R2, DIO_u8HIGH);
	DIO_Enu_SetPinValue(KPD_PORT, KPD_R3, DIO_u8HIGH);

	/*connect the pins of the columns as output pins (HIGH)*/

	DIO_Enu_SetPinDirection(KPD_PORT, KPD_C0, DIO_u8OUTPUT);
	DIO_Enu_SetPinDirection(KPD_PORT, KPD_C1, DIO_u8OUTPUT);
	DIO_Enu_SetPinDirection(KPD_PORT, KPD_C2, DIO_u8OUTPUT);
	DIO_Enu_SetPinDirection(KPD_PORT, KPD_C3, DIO_u8OUTPUT);

	DIO_Enu_SetPinValue(KPD_PORT, KPD_C0, DIO_u8HIGH);
	DIO_Enu_SetPinValue(KPD_PORT, KPD_C1, DIO_u8HIGH);
	DIO_Enu_SetPinValue(KPD_PORT, KPD_C2, DIO_u8HIGH);
	DIO_Enu_SetPinValue(KPD_PORT, KPD_C3, DIO_u8HIGH);

	Local_EnuErrorState = ES_OK;

	return Local_EnuErrorState;
}

ES_t KPD_enu_GetPressed(u8 *Copy_pu8Value)
{
	ES_t Local_EnuErrorState = ES_NOT_OK;
	u8 LOC_u8PinState;
	u8 LOC_u8ColumnIndex, LOC_u8RowIndex;
	static u8 LOC_u8KPDColumnArr[COLS_NUM] = {KPD_C0, KPD_C1, KPD_C2, KPD_C3};
	static u8 LOC_u8KPDRowArr[ROWS_NUM] = {KPD_R0, KPD_R1, KPD_R2, KPD_R3};
	*Copy_pu8Value = NOTPRESSED;
	for (LOC_u8ColumnIndex = 0; LOC_u8ColumnIndex < COLS_NUM; LOC_u8ColumnIndex++)
	{
		DIO_Enu_SetPinValue(KPD_PORT, LOC_u8KPDColumnArr[LOC_u8ColumnIndex], DIO_u8LOW);
		for (LOC_u8RowIndex = 0; LOC_u8RowIndex < ROWS_NUM; LOC_u8RowIndex++)
		{
			DIO_Enu_GetPinValue(KPD_PORT, LOC_u8KPDRowArr[LOC_u8RowIndex], &LOC_u8PinState);
			if (LOC_u8PinState == DIO_u8LOW)
			{
				*Copy_pu8Value = KPD_u8Buttons[LOC_u8RowIndex][LOC_u8ColumnIndex];
				while (LOC_u8PinState == DIO_u8LOW)
				{
					DIO_Enu_GetPinValue(KPD_PORT, LOC_u8KPDRowArr[LOC_u8RowIndex], &LOC_u8PinState);
				}
				Local_EnuErrorState = ES_OK;
				return Local_EnuErrorState;
			}
		}
		DIO_Enu_SetPinValue(KPD_PORT, LOC_u8KPDColumnArr[LOC_u8ColumnIndex], DIO_u8HIGH);
	}
	Local_EnuErrorState = ES_OK;
	return Local_EnuErrorState;
}
