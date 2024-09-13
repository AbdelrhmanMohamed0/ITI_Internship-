/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_1.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 14/7/2024
 *  version    : v1.0
 *  require    : Write a code that can draw pyramid .
 */
#include <stdio.h>
int main(void)
{
    printf("     *     \n");
    printf("    ***    \n");
    printf("   *****   \n");
    printf("  *******  \n");
    printf(" ********* \n");
    printf("***********\n");
    printf("----------------------------\n");
    // Another Solution by using for loop
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6 - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
