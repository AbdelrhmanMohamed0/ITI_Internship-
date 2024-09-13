#ifndef ERROR_STATES_H_
#define ERROR_STATES_H_

typedef enum{
ES_NOT_OK,
ES_OK,
ES_NULL_POINTER,
ES_OUT_OF_RANGE,
ES_ADC_IDLE,
ES_ADC_BUSY,
ES_TIMEOUT_STATE,
ES_USART_BUSY,
ES_USART_IDLE,
ES_IDLE,
ES_BUSY
}ES_t;
typedef enum{
	MasterReadByteErr,
	SlaveWriteByteErr,
	NoError,
	SlaveReadByteErr,
	MasterWriteByteErr,
	SlaveAddressWithReadErr,
	SlaveAddressWithWriteErr,
	RepeatedStartError,
	StartConditionErr,

}TWI_ErrStatus;


#endif
