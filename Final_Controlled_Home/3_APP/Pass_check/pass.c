#include "pass.h"
extern ST_userData_t *dbAccounts[MAX_NUMBER_OF_USERS];
volatile u8 z = 0;
u8 get_name[10] = { 0 };
u8 get_pass[10] = { 0 };
void function(void) {
	z = 1;
}

void get_Name(void) {
	USART_u8SendStringSynch((u8 *) "\n\r enter your name");
	USART_u8ReceiveBufferAsynch(get_name, 10, function);
	while (z == 0)
		;
	z = 0;
}
void get_passwoard(void) {
	USART_u8SendStringSynch((u8 *) "\n\r enter your pass");
	USART_u8ReceiveBufferAsynch(get_pass, 10, function);
	while (z == 0)
		;
	z = 0;
}
u8 findUserByUsername(void) {
	for (u8 i = 0; i < MAX_NUMBER_OF_USERS - 5; i++) {
		if (strcmp((char *) get_name, (char *) dbAccounts[i]->userName) == 0) {
			return i;
		}
	}
	return INVALID_USER_INDEX;
}

// Function to check password
u8 checkPassword(u8 user_index) {
	if (strcmp((char *) get_pass, (char *) dbAccounts[user_index]->userPass)
			== 0) {
		return 1;
	} else {
		return 0;
	}
}

u8 check_pass_operation(void) {
	u8 ret = 0;
	u8 x, y;
	u8 num_attemps = 0;
	get_Name();
	get_passwoard();
	x = findUserByUsername();
	if (x != 255) {
		while (num_attemps < 3) {
			y = checkPassword(x);
			num_attemps++;
			if (y == 0 && num_attemps < 3)
			{
				USART_u8SendStringSynch((u8 *)"\n\r===== Wrong pass =====");
				get_passwoard();
			}
			else
			{
				break;
			}
		}
		if (y == 1) {
			USART_u8SendStringSynch((u8 *) "\n\r Welcome ");
			USART_u8SendStringSynch((u8 *) "\n\r Access Granted ");
			ret = 1;
		} else {
			USART_u8SendStringSynch((u8 *) "\n\r Access Denied ");
		}
	} else {
		USART_u8SendStringSynch((u8 *) "\n\r user not found ");
	}
	return ret;
}
