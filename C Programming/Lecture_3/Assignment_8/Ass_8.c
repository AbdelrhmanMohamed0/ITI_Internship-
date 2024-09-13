/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_8.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Write a function to check if a given number is a prime number.
 */
#include <stdio.h>
int isPrime(int num);
int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPrime(number))
    {
        printf("%d is a prime number.\n", number);
    }
    else
    {
        printf("%d is not a prime number.\n", number);
    }
    return 0;
}
int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}