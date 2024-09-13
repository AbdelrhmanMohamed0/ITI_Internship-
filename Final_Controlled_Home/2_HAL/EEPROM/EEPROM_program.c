
#include "../../4_LIB/STD_TYPES.h"
#include "../../4_LIB/ERROR_STATES.h"
#include "../../1_MCAL/DIO/DIO_INTERFACE.h"
#include "../../1_MCAL/TWI/TWI_interface.h"


#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"

#include <util/delay.h>

//----------------------------------------------------------------------------------------------------------------------------------------------------

void EEPROM_voidInit(void){
	DIO_Enu_SetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8INPUT);
	DIO_Enu_SetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8INPUT);
	DIO_Enu_SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8LOW);
	DIO_Enu_SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8LOW);
	TWI_voidInitMaster(0x0);
	TWI_voidInitSlave(0xA0);
}

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{
	u8 Local_u8AddressPacket=0x00;
	//if 24C08 :
	//Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);

	//if 24C02 :
	 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;


	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet*/
	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((u8)Copy_u16LocationAddress);

	/*Send the data byte to the memory location*/
	TWI_MasterWriteDataByte(Copy_u8DataByte);

	/*Send stop condition*/
	TWI_SendStopCondition();

	/*Delay until the write cycle is finished*/
	_delay_ms(10);

}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress)
{
	u8 Local_u8AddressPacket=0x00, Local_u8Data;

	//if 24C08 :
		//Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (u8)(Copy_u16LocationAddress >>8);
	//if 24C02 :
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;

	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet with write request*/
	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((u8)Copy_u16LocationAddress);

	/*Send repeated start to change write request into read request*/
	TWI_SendRepeatedStart();

	/*Send the address packet with read request*/
	TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);

	/*Get the data from memory*/
	TWI_MasterReadDataByteWithACK(&Local_u8Data);

    /* Send NACK after last byte */
    TWI_SendNACK();

	/*send the stop condition*/
	TWI_SendStopCondition();

	return Local_u8Data;
}

void EEPROM_voidSendFrame(u16 Copy_u16StartAddress, u8 *Copy_u8Frame, u16 Copy_u16Length) {
    for (u16 i = 0; i < Copy_u16Length; i++) {
        EEPROM_voidSendDataByte(Copy_u16StartAddress + i, Copy_u8Frame[i]);
        _delay_ms(10);  // Ensure time for EEPROM write cycle
    }
}

void EEPROM_voidReadFrame(u16 Copy_u16StartAddress, u8 *Copy_u8Frame, u16 Copy_u16Length) {
    for (u16 i = 0; i < Copy_u16Length; i++) {
        Copy_u8Frame[i] = EEPROM_u8ReadDataByte(Copy_u16StartAddress + i);
        _delay_ms(10);  // Ensure time for EEPROM read cycle
    }
}
