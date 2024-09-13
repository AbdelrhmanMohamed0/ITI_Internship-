#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);
u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);
void EEPROM_voidSendFrame(u16 Copy_u16StartAddress, u8 *Copy_u8Frame, u16 Copy_u16Length);
void EEPROM_voidReadFrame(u16 Copy_u16StartAddress, u8 *Copy_u8Frame, u16 Copy_u16Length);
#endif
