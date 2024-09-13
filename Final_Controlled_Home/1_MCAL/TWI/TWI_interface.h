#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

/*Set master address to 0 if master will not be addressed*/

void TWI_voidInitMaster(u8 Copy_u8Address);

void TWI_voidInitSlave(u8 Copy_u8Address);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByteWithACK(u8 *Copy_pu8DataByte);

TWI_ErrStatus TWI_MasterReadDataByteWithoutACK(u8 *Copy_pu8DataByte);

TWI_ErrStatus TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_SlaveReadDataByte(u8* Copy_pu8DataByte);

TWI_ErrStatus TWI_u8SendFrame(u8 A_u8Address,u8 *PA_u8buffer,u8 len);


void TWI_SendStopCondition(void);
void TWI_voidDisableACK(void);
void TWI_voidDisableTWI(void);
void TWI_voidEnableACK(void);
void TWI_voidEnableTWI(void);
void TWI_SendACK(void);
void TWI_SendNACK(void);

#endif
