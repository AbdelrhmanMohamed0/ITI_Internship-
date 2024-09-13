/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_1.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Leap Year Checker.
 */
#include <stdio.h>
int main(void)
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                printf("%d is a leap year.", year);
            else
                printf("%d is not a leap year.", year);
        }
        else
            printf("%d is a leap year.", year);
    }
    else
        printf("%d is not a leap year.", year);
    return 0;
}
