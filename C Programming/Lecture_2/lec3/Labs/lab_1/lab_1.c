/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_1.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Power Calculation .
 */
#include <stdio.h>
int main(void)
{
    int num, power;
    long int res = 1;
    printf("please enter number and power ");
    scanf("%d %d", &num, &power);
    for (int i = 0; i < power; i++)
    {
        res = res * num;
    }
    printf("result = %ld", res);
    return 0;
}
