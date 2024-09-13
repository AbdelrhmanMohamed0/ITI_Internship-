/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_3.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    :  Factorial Calculation .
 */
#include <stdio.h>
int factorial(int num);
int main(void)
{
    int num;
    printf("please enter number : ");
    scanf("%d", &num);
    printf("factorial of %d = %d ", num, factorial(num));
    return 0;
}
int factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}
