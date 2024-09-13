/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_2.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Sum of Digits.
 */
#include <stdio.h>
int main(void)
{
    long int num = 0;
    int res = 0;
    printf("enter number : ");
    scanf("%ld", &num);
    while (num != 0)
    {
        res += (num % 10);
        num /= 10;
    }
    printf("sum = %d", res);
    return 0;
}
