/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_4.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Decimal to Binary Conversion .
 */
#include <stdio.h>
int main(void)
{
    int num, i;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Binary number of %d is: ", num);
    for (i = 31; i >= 0; i--)
    {
        if (num & (1 << i))
            printf("1");
        else
            printf("0");
    }
    return 0;
}
