/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_6.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Write a recursive function to find the sum of digits of a given number .
 */
#include <stdio.h>

int sumOfDigits(int num);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int sum = sumOfDigits(num);
    printf("Sum of digits: %d\n", sum);
    return 0;
}

int sumOfDigits(int num)
{
    static int sum = 0;
    if (num == 0)
    {
        return sum;
    }
    else
    {
        sum += num % 10;
        sumOfDigits(num / 10);
    }
}