#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*unsigned Integer data types*/
typedef unsigned char                  u8;
typedef unsigned short int             u16;
typedef unsigned long int              u32;
typedef unsigned long  long            u64;
/*signed Integer data types*/				  
typedef signed char                    s8;
typedef signed short  int              s16;
typedef signed long int                s32;
typedef signed long  long              s64;
/*Real data types*/
typedef float                          f32;
typedef double                         f64;
typedef long double                    f128;
/*more -----------------*/
typedef volatile unsigned char         v_u8;
typedef volatile signed char           v_s8;
typedef volatile unsigned short int    v_u16;
typedef volatile signed short  int     v_s16;
typedef volatile unsigned long int     v_u32;
typedef volatile signed long int       v_s32;
typedef volatile unsigned long  long   v_u64;
typedef volatile signed long  long     v_s64;

#endif