/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_5.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Write a recursive function to calculate the power of a number .
 */
#include <stdio.h>

int power(int base, int exp);

int main(void)
{
    int base, exp;
    printf("please enter base and positive exponent : ");
    scanf("%d %d", &base, &exp);
    printf("power of %d = %d  ", base, power(base, exp));

    return 0;
}

int power(int base, int exp)
{
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base;
    else
        return base * power(base, exp - 1);
}
