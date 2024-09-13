#include "master.h"
extern ST_userData_t USER_ONE,USER_TWO,USER_THREE,USER_FOUR,USER_FIVE;
                     /*USER_SIX,USER_SEVEN,USER_EGIHT,USER_NINE,USER_TEN*/
extern ST_userData_t *dbAccounts[MAX_NUMBER_OF_USERS];
u8 operation[2] = {0};
u8 user[2]={0};
volatile u8 flag=0;
void fun(void){
flag=1;
}
void master_user_interface()
{

	User_init(*dbAccounts);
	USART_u8SendStringSynch((u8 *)"\n\r===== User Management System =====");
	USART_u8SendStringSynch((u8 *)"\n\r===== Choose Operation =====");
	USART_u8SendStringSynch((u8 *)"\n\r1 - Add User ");
	USART_u8SendStringSynch((u8 *)"\n\r2 - Edit User ");
	USART_u8SendStringSynch((u8 *)"\n\r3 - Remove User ");
	USART_u8SendStringSynch((u8 *)"\n\r4 - Exit ");
	USART_u8SendStringSynch((u8 *)"\n\rEnter Choice : ");
	while(1)
	{
		while(flag==0){
		USART_u8ReceiveBufferAsynch(operation,1,fun);
	    }
	    flag=0;
	     switch(operation[0])
		{
		case '1' :
		{
			UsersList();
			USART_u8SendStringSynch((u8 *)"\n\rChoose Free User Slot : ");
			while(flag==0){
			USART_u8ReceiveBufferAsynch(user,1,fun);
			}
			flag=0;
			switch(user[0])
			{
			case '0' : addNewUser(&USER_ONE); break;
			case '1' : addNewUser(&USER_TWO); break;
			case '2' : addNewUser(&USER_THREE); break;
			case '3' : addNewUser(&USER_FOUR); break;
			case '4' : addNewUser(&USER_FIVE); break;
			/*case '5' : addNewUser(&USER_SIX); break;
			case '6' : addNewUser(&USER_SEVEN); break;
			case '7' : addNewUser(&USER_EGIHT); break;
			case '8' : addNewUser(&USER_NINE); break;
			case '9' : addNewUser(&USER_TEN); break;*/
			default: USART_u8SendStringSynch((u8 *)"\n\rWrong Entry!\n\r ");
			}
			USART_u8SendStringSynch((u8 *)"\n\r===== Choose Operation =====");
			USART_u8SendStringSynch((u8 *)"\n\r1 - Add User ");
			USART_u8SendStringSynch((u8 *)"\n\r2 - Edit User ");
			USART_u8SendStringSynch((u8 *)"\n\r3 - Remove User ");
			USART_u8SendStringSynch((u8 *)"\n\r4 - Exit ");
			USART_u8SendStringSynch((u8 *)"\n\rEnter Choice : ");
			break;
		}
		case '2':
		{
			UsersList();
			USART_u8SendStringSynch((u8 *)"\n\rChoose User To Edit : ");
			while(flag==0){
			USART_u8ReceiveBufferAsynch(user,1,fun);
			}
			flag=0;
			switch(user[0])
			{

			case '0' : editUser(&USER_ONE); break;
			case '1' : editUser(&USER_TWO); break;
			case '2' : editUser(&USER_THREE); break;
			case '3' : editUser(&USER_FOUR);break;
			case '4' : editUser(&USER_FIVE); break;
			/*case '5' : editUser(&USER_SIX); break;
			case '6' : editUser(&USER_SEVEN); break;
			case '7' : editUser(&USER_EGIHT); break;
			case '8' : editUser(&USER_NINE); break;
			case '9' : editUser(&USER_TEN); break;*/
			default: USART_u8SendStringSynch((u8 *)"\n\rWrong Entry!\n\r ");
			}
			USART_u8SendStringSynch((u8 *)"\n\r===== Choose Operation =====");
			USART_u8SendStringSynch((u8 *)"\n\r1 - Add User ");
			USART_u8SendStringSynch((u8 *)"\n\r2 - Edit User ");
			USART_u8SendStringSynch((u8 *)"\n\r3 - Remove User ");
			USART_u8SendStringSynch((u8 *)"\n\r4 - Exit ");
			USART_u8SendStringSynch((u8 *)"\n\rEnter Choice : ");
			break;
		}
		case '3':
		{
			UsersList();
			USART_u8SendStringSynch((u8 *)"\n\rChoose User To Remove : ");
			while(flag==0){
			USART_u8ReceiveBufferAsynch(user,1,fun);
			}
			flag=0;
			switch(user[0])
			{
			case '0' : removeUser(&USER_ONE); break;
			case '1' : removeUser(&USER_TWO); break;
			case '2' : removeUser(&USER_THREE); break;
			case '3' : removeUser(&USER_FOUR);break;
			case '4' : removeUser(&USER_FIVE); break;
			/*case '5' : removeUser(&USER_SIX); break;
			case '6' : removeUser(&USER_SEVEN); break;
			case '7' : removeUser(&USER_EGIHT); break;
			case '8' : removeUser(&USER_NINE); break;
			case '9' : removeUser(&USER_TEN); break;*/
			default: USART_u8SendStringSynch((u8 *)"\n\rWrong Entry!\n\r ");
			}
			USART_u8SendStringSynch((u8 *)"\n\r===== Choose Operation =====");
			USART_u8SendStringSynch((u8 *)"\n\r1 - Add User ");
			USART_u8SendStringSynch((u8 *)"\n\r2 - Edit User ");
			USART_u8SendStringSynch((u8 *)"\n\r3 - Remove User ");
			USART_u8SendStringSynch((u8 *)"\n\r4 - Exit ");
			USART_u8SendStringSynch((u8 *)"\n\rEnter Choice : ");
			break;
		}
		case '4':
		{
			USART_u8SendStringSynch((u8 *)"\n\r===== Please Wait While Saving Your Data =====\r\n\r\n");
			return;
		}
		default :
		{
			USART_u8SendStringSynch((u8 *)"\n\rWrong Choice Try Again : ");
			USART_u8SendStringSynch((u8 *)"\n\r===== Choose Operation =====");
			USART_u8SendStringSynch((u8 *)"\n\r1 - Add User ");
			USART_u8SendStringSynch((u8 *)"\n\r2 - Edit User ");
			USART_u8SendStringSynch((u8 *)"\n\r3 - Remove User ");
			USART_u8SendStringSynch((u8 *)"\n\r4 - Exit ");
			USART_u8SendStringSynch((u8 *)"\n\rEnter Choice : ");
			break;
		}
		}
	}
}
