/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_4.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 18/7/2024
 *  version    : v1.0
 *  require    : Implementation of a swap function in C using pointers.
 *               This function will swap the values of two integers.
 */
#include <stdio.h>
void swap(int *a, int *b);
int main(void)
{
    int num1 = 10;
    int num2 = 20;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}