#ifndef USER_MANAGMENT_USER_HNADLING_H_
#define USER_MANAGMENT_USER_HNADLING_H_

#include "../../4_LIB/STD_TYPES.h"
#include "../../4_LIB/ERROR_STATES.h"
#include "../../1_MCAL/USART/USART_interface.h"
#include "../../2_HAL/EEPROM/EEPROM_interface.h"
#include <string.h>
#include <util/delay.h>
#include "user_handling_cfg.h"
#define FLAG_ADD    0xF0

typedef struct
{
	u16 userNameAdd;
	u16 userPassAdd;
	u8 userName[USER_NAME_MAX_SIZE];
	u8 userPass[USER_PASS_MAX_SIZE];

}ST_userData_t;

void User_init(ST_userData_t *dbAccounts);
u8 addNewUser(ST_userData_t *_user);
u8 editUser(ST_userData_t *_user);
void removeUser(ST_userData_t *_user);
void UsersList();
u8 isFreeSlot(ST_userData_t *_user);
u8 isUserExist(ST_userData_t *userName);
void eraseUser(ST_userData_t *_user);
#endif /* USER_MANAGMENT_USER_HNADLING_H_ */
