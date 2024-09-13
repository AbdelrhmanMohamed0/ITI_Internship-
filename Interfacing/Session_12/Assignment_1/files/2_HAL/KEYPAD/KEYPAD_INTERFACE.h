#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define NOTPRESSED '\0'

ES_t KPD_enu_Init(void);
ES_t KPD_enu_GetPressed( u8 * Copy_pu8Value );

#endif /* KPD_INTERFACE_H_ */
