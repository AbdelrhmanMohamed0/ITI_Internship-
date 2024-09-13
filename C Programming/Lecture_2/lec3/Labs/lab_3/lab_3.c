/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_3.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Write a C program to reverse a given number .
 */
#include <stdio.h>
int main(void)
{
    int num, res = 0, rem = 0;
    printf("enter number : ");
    scanf("%d", &num);
    while (num != 0)
    {
        rem = num % 10;
        res = (res * 10) + rem;
        num /= 10;
    }
    printf("res = %d", res);
    return 0;
}
