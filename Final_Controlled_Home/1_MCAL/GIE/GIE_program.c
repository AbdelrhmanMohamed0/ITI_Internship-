#include "../../4_LIB/STD_TYPES.h"
#include "../../4_LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"


void GIE_VoidEnable (void)
{
	SET_BIT (SREG , SREG_I) ;
}

void GIE_VoidDisable (void)
{
	CLR_BIT (SREG , SREG_I) ;
}
