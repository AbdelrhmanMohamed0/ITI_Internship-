/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_2.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Write a function that prints n-th Fibonacci series .
 */
#include <stdio.h>
void Fibonacci(int num);
int main(void)
{
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    Fibonacci(num);
    return 0;
}
void Fibonacci(int num)
{
    int a = 0, b = 1, c, i;
    if (num <= 0)
    {
        printf("Please enter a positive number.\n");
        return;
    }
    printf("Fibonacci Series: %d %d", a, b);
    for (i = 2; i < num; i++)
    {
        c = a + b;
        printf(" %d", c);
        a = b;
        b = c;
    }
    printf("\n");
}
