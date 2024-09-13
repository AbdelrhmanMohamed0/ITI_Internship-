/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_5.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    :  Factor Finder .
 */
#include <stdio.h>
int main(void)
{
    int num, i;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factors of %d are: ", num);
    for(i = 1; i <= num; ++i)
    {
        if(num % i == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}

