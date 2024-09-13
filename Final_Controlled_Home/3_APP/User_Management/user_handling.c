#include "user_handling.h"
	u8 ret = 0;
u8 userSlots = MAX_NUMBER_OF_USERS;
static u8 NumberOfRegistars = 0;
u8 FLAG='Y';   //because to not store agin in eerprom
u16 FLAG_ADDRESS=FLAG_ADD;
ST_userData_t USER_ONE =
{
		.userNameAdd = 0x00,
		.userPassAdd = 0x18,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_TWO =
{
		.userNameAdd = 0x30,
		.userPassAdd = 0x48,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_THREE =
{
		.userNameAdd = 0x60,
		.userPassAdd = 0x78,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_FOUR =
{
		.userNameAdd = 0x90,
		.userPassAdd = 0xA8,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_FIVE =
{
		.userNameAdd = 0xC0,
		.userPassAdd = 0xD8,
		.userName = "FREE",
		.userPass = "FREE"
};
/*ST_userData_t USER_SIX =
{
		.userNameAdd = 0x108,
		.userPassAdd = 0x120,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_SEVEN =
{
		.userNameAdd = 0x138,
		.userPassAdd = 0x150,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_EGIHT =
{
		.userNameAdd = 0x168,
		.userPassAdd = 0x180,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_NINE =
{
		.userNameAdd = 0x198,
		.userPassAdd = 0x1B0,
		.userName = "FREE",
		.userPass = "FREE"
};
ST_userData_t USER_TEN =
{
		.userNameAdd = 0x1C8,
		.userPassAdd = 0x1E0,
		.userName = "FREE",
		.userPass = "FREE"
};
*/

ST_userData_t *dbAccounts[MAX_NUMBER_OF_USERS] =
{
		&USER_ONE,
		&USER_TWO,
		&USER_THREE,
		&USER_FOUR,
		&USER_FIVE,
		/*&USER_SIX,
		&USER_SEVEN,
		&USER_EGIHT,
		&USER_NINE,
		&USER_TEN*/
};
u8 volatile ff=0;
void funn(void){
	ff=1;
}
void User_init(ST_userData_t *dbAccounts){
	USART_voidInit();
	EEPROM_voidInit();
	FLAG=EEPROM_u8ReadDataByte(FLAG_ADDRESS);
/*
	for(u8 i=0;i<255;i++)
	{
		EEPROM_voidSendDataByte(i,0xff);
	}
*/
	if(FLAG!='Y'){
	for(u8 i=0;i<MAX_NUMBER_OF_USERS-5;i++){
	EEPROM_voidSendFrame(dbAccounts[i].userNameAdd,dbAccounts[i].userName,strlen(dbAccounts[i].userName));
	EEPROM_voidSendDataByte(dbAccounts[i].userNameAdd+strlen(dbAccounts[i].userName),'\0');
	EEPROM_voidSendFrame(dbAccounts[i].userPassAdd,dbAccounts[i].userPass,strlen(dbAccounts[i].userPass));
	EEPROM_voidSendDataByte(dbAccounts[i].userPassAdd+strlen(dbAccounts[i].userPass),'\0');
	}
	EEPROM_voidSendFrame(FLAG_ADDRESS,"Y",1);
	}
	else{
		for(u8 i=0;i<MAX_NUMBER_OF_USERS-5;i++)
		{
			eraseUser(&dbAccounts[i]);
		}
		for(u8 i=0;i<MAX_NUMBER_OF_USERS-5;i++)
		{
			EEPROM_voidReadFrame(dbAccounts[i].userNameAdd,dbAccounts[i].userName,strlen((dbAccounts[i].userName))+1);
			EEPROM_voidReadFrame(dbAccounts[i].userPassAdd,dbAccounts[i].userPass,strlen((dbAccounts[i].userPass))+1);
		}
	}
}

u8 addNewUser(ST_userData_t *_user)
{
	u8 ret = 0;
	USART_u8SendStringSynch((u8 *)"\n\r===== Adding New User =====");
	if(NumberOfRegistars == MAX_NUMBER_OF_USERS)
	{
		USART_u8SendStringSynch((u8 *)"\n\r You Reach The Max Number Of Users");
	}
	else
	{
		u8 tempname[USER_NAME_MAX_SIZE]={0};
		u8 temppass[USER_PASS_MAX_SIZE]={0};
		USART_u8SendStringSynch((u8 *)"\n\rEnter User Name : ");
		USART_u8ReceiveBufferAsynch(tempname,USER_NAME_MAX_SIZE,funn);
		while(ff==0);
		ff=0;
		eraseUser(_user);
		strcpy((char *)_user->userName,(char *)tempname);
		if(!isUserExist(_user))
		{
			ret = 1;
		}
		if(ret == 1)
		{
			USART_u8SendStringSynch((u8 *)"\n\rEnter User Password : ");
			USART_u8ReceiveBufferAsynch(temppass,USER_PASS_MAX_SIZE,funn);
			while(ff==0);
			ff=0;
			strcpy((char *)_user->userPass,(char *)temppass);
			EEPROM_voidSendFrame(_user->userNameAdd,_user->userName,strlen((_user->userName))+1);
			EEPROM_voidSendFrame(_user->userPassAdd,_user->userPass,strlen((_user->userPass))+1);
			USART_u8SendStringSynch((u8 *)"\n\rUser Added Successfully ");
			NumberOfRegistars++;
		}
		else
		{
			USART_u8SendStringSynch((u8 *)"\n\rUser Is Already Exist");
		}
	}
	return ret;
}
u8 editUser(ST_userData_t *_user)
{
	u8 ret = 0;
	USART_u8SendStringSynch((u8 *)"\n\r===== Editing User =====");

	u8 tempname[USER_NAME_MAX_SIZE];
	u8 temppass[USER_PASS_MAX_SIZE];
	USART_u8SendStringSynch((u8 *)"\n\rEnter User Name : ");
	USART_u8ReceiveBufferAsynch(tempname,USER_NAME_MAX_SIZE,funn);
	while(ff==0);
	ff=0;
	if(isUserExist(_user))
	{
		u8 func_ret = isFreeSlot(_user);
		if(func_ret == 0)
		{
			eraseUser(_user);
			strcpy((char *)_user->userName,(char *)tempname);
			ret = 1;
		}
	}
	if(ret == 1)
	{
		USART_u8SendStringSynch((u8 *)"\n\rEnter User Password : ");
		USART_u8ReceiveBufferAsynch(temppass,USER_PASS_MAX_SIZE,funn);
		while(ff==0);
		ff=0;
		strcpy((char *)_user->userPass,(char *)temppass);
		EEPROM_voidSendFrame(_user->userNameAdd,_user->userName,strlen((_user->userName))+1);
		EEPROM_voidSendFrame(_user->userPassAdd,_user->userPass,strlen((_user->userPass))+1);
		USART_u8SendStringSynch((u8 *)"\n\rUser Edited Successfully ");
	}
	else
	{
		USART_u8SendStringSynch((u8 *)"\n\rUser Is Not Exist");
	}
	return ret;
}

u8 isUserExist(ST_userData_t *userName)
{
	u8 i = 0;
	u8 name[10]={0};
	while(i < (userSlots-5))
	{
		EEPROM_voidReadFrame(userName->userNameAdd,name,USER_NAME_MAX_SIZE);
		if(!strcmp((char *)userName->userName,(char *)name))
		{
			ret = 1;
			return ret;
		}
		i++;
	}
	return ret;
}

void UsersList()
{
	u8 i = 0;
	while(i < userSlots)
	{
		USART_u8SendStringSynch((u8 *)"\n\r");
		USART_u8SendData((i) + '0');
		USART_u8SendStringSynch((u8 *)" - User Name :   ");
		USART_u8SendStringSynch((dbAccounts[i]->userName));
		i++;
	}
}

void eraseUser(ST_userData_t *_user)
{
	u8 i = 0;
	u8 j = 0;
	while(i < USER_NAME_MAX_SIZE)
	{
		strcpy((char *)_user->userName[i],"\0");
		i++;
	}
	while(j < USER_PASS_MAX_SIZE)
	{
		strcpy((char *)_user->userPass[j],"\0");
		j++;
	}
}

void removeUser(ST_userData_t *_user)
{
	strcpy((char *)_user->userName,"FREE");
	strcpy((char *)_user->userPass,"FREE");
	EEPROM_voidSendFrame(_user->userNameAdd,"FREE",strlen("FREE"));
	EEPROM_voidSendDataByte(_user->userNameAdd+strlen("FREE"),'\0');
	EEPROM_voidSendFrame(_user->userPassAdd,"FREE",strlen("FREE"));
	EEPROM_voidSendDataByte(_user->userPassAdd+strlen("FREE"),'\0');
	NumberOfRegistars--;
	USART_u8SendStringSynch((u8 *)"\n\rUser Removed Successfully ");
}

u8 isFreeSlot(ST_userData_t *_user)
{

		u8 ret = 0;
		if(strcmp("FREE",(char *)_user->userName)==0)
		{
			ret = 1;
		}

		return ret;
}

