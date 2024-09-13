/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_2.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Prime Number Checker.
 */
#include <stdio.h>
int main(void)
{
    int num, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num <= 1)
        flag = 1;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%d is a prime number.", num);
    else
        printf("%d is not a prime number.", num);
    return 0;
}
