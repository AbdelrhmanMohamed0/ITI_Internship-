/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_4.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Write a recursive function to generate the nth Fibonacci number .
 */
#include <stdio.h>

int Fibonacci(int n);

int main(void)
{
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibonacci Series: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", Fibonacci(i));
    }
    printf("\n");
    return 0;
}

int Fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
