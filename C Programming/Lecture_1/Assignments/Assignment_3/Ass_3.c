/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_3.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 14/7/2024
 *  version    : v1.0
 *  require    : Write a code that takes 2 numbers and print their
                 summation, subtraction, anding, oring, and Xoring .
 */
#include <stdio.h>
int main(void)
{
    int num1, num2;
    printf("Please Enter Number 1 : ");
    scanf("%d", &num1);
    printf("Please Enter Number 2 : ");
    scanf("%d", &num2);
    printf("%d+%d=%d\n", num1, num2, (num1 + num2));
    printf("%d-%d=%d\n", num1, num2, (num1 - num2));
    printf("%d&%d=%d\n", num1, num2, (num1 & num2));
    printf("%d|%d=%d\n", num1, num2, (num1 | num2));
    printf("%d^%d=%d\n", num1, num2, (num1 ^ num2));
}
