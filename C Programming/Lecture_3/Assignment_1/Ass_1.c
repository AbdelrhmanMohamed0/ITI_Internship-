/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_1.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Given a string consisting of alphabets and digits
                 find the frequency of each digit in the given string .
 */
#include <stdio.h>
int main(void)
{
    char array[100] = {0};
    char count[10] = {0};
    int num, i = 0;
    printf("Enter your String consisting of alphabets and digits \n");
    scanf("%s", array);
    for (i = 0; array[i] != '\0'; i++)
    {
        if (array[i] >= '0' && array[i] <= '9')
        {
            num = array[i] - '0';
            count[num]++;
        }
    }
    printf("frequency is : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", count[i]);
    }
    return 0;
}
