//App1
#include"../../4_LIB/STD_TYPES.h"
#include"../../4_LIB/ERROR_STATES.h"
#include"../../2_HAL/SWITCH/SWITCH_CONFIG.h"
#include"../../2_HAL/SWITCH/SWITCH_INTERFACE.h"
#include"../../2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_CONFIG.h"
#include"../../2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_INTERFACE.h"
#include<util/delay.h>
#define  SEGMENT_NUM_1  0
#define  SEGMENT_NUM_2  1

extern Switch_Arr_Stru_SwitchState[SW_NUM];
extern SEG_t SEVSEG_AstrSegConfig[SEG_NUM];
int main(void) {
	SWITCH_EnuInit(Switch_Arr_Stru_SwitchState);
	Seven_Segment_enuInit(SEVSEG_AstrSegConfig);
	u8 States = 1, flag = 0, i=0;
	while (1) {
		do {
			SWITCH_EnuGetStates(Switch_Arr_Stru_SwitchState, &States);
			if (States == 0)
				flag = 1;
		} while (States == 0);
		if (flag == 1) {
			i++;
			flag = 0;
		}
		Seven_Segment_enuDisplayNum(SEGMENT_NUM_1, i % 10);
		Seven_Segment_enuDisplayNum(SEGMENT_NUM_2, i / 10);
		if (i > 99)
			i = 0;
	}

	return 0;
}
