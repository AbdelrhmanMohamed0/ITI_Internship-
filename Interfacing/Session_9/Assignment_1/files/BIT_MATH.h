#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(REG, BIT) (REG |= (1 << BIT))
#define CLR_BIT(REG, BIT) (REG &= ~(1 << BIT))
#define TOG_BIT(REG, BIT) (REG ^= (1 << BIT))
#define GIT_BIT(REG, BIT) ((REG >> BIT) & 0x1)

#endif
