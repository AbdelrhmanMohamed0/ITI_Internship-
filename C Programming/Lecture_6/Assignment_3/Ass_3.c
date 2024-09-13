/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_3.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 21/7/2024
 *  version    : v1.0
 *  require    : Use struct and arrow operator to access 3 variables arranged in memory.
 */
#include <stdio.h>

typedef long int uint32_t;
uint32_t a = 0;
uint32_t b = 0;
uint32_t c = 0;

typedef struct
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
} MyStruct;

int main(void)
{
    MyStruct *ptr =(MyStruct *)&a;

    ptr->x = 22;
    ptr->y = 33;
    ptr->z = 44;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}