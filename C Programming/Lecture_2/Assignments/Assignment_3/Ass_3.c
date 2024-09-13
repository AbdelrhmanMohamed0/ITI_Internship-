/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_3.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Write a C program that asks the user to enter 5
                 numbers, and print the maximum number between them .
 */
#include <stdio.h>
#include <limits.h>
int main(void)
{
    int num, max = INT_MIN;
    printf("Please Enter 5 Numbers \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        if (num > max)
            max = num;
    }
    printf("the maximum number between them is %d \n", max);
    return 0;
}
