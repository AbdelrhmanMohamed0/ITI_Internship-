#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit (void);

ES_t   USART_u8SendData (u8 Copy_u8Data);

ES_t   USART_u8RecevieData (u8 * Copy_u8ReceviedData) ;

ES_t   USART_u8SendStringSynch (const u8 * Copy_pchString);
ES_t   USART_u8SendStringAsynch (const u8 * Copy_pchString , void (* NotificationFunc)(void)) ;

ES_t   USART_u8ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize) ;
ES_t   USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) ;

#endif
