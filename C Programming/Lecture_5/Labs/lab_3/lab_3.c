#include <stdio.h>
void main(void)
{
    /*unsigned Integer data types*/
    typedef unsigned char u8;
    typedef unsigned short int u16;
    typedef unsigned long int u32;
    typedef unsigned long long u64;
    /*signed Integer data types*/
    typedef signed char s8;
    typedef signed short int s16;
    typedef signed long int s32;
    typedef signed long long s64;
    /*Real data types*/
    typedef float f32;
    typedef double f64;
    typedef long double f128;
    printf("size of unsigned char: %d\n", sizeof(u8));
    printf("size of unsigned short: %d\n", sizeof(u16));
    printf("size of unsigned int: %d\n", sizeof(u32));
    printf("size of unsigned long: %d\n", sizeof(u32));
    printf("size of unsigned long long: %d\n", sizeof(u64));
    printf("size of signed char: %d\n", sizeof(s8));
    printf("size of signed short: %d\n", sizeof(s16));
    printf("size of signed int: %d\n", sizeof(s32));
    printf("size of signed long: %d\n", sizeof(s32));
    printf("size of signed long long: %d\n", sizeof(s64));
    printf("size of float: %d\n", sizeof(f32));
    printf("size of double: %d\n", sizeof(f64));
    printf("size of long double: %d\n", sizeof(f128));
}
