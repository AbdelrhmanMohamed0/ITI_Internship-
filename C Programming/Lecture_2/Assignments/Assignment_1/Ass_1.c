/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_1.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Write a C code that ask the user to enter 10 numbers,
                 then ask him to enter another number to search on it in
                 the 1O numbers and print its location in case it is found.
                 In case the number is not found, it will print number not exist .
 */
#include <stdio.h>
int main(void)
{
    int array_nums[10] = {0};
    int num, pos;
    for (int i = 0; i < 10; i++)
    {
        printf("Please Enter Number %d : ", i + 1);
        scanf("%d", &array_nums[i]);
    }
    printf("Please Enter Number to Search : ");
    scanf("%d", &num);
    for (int i = 0; i < 10; i++)
    {
        if (num == array_nums[i])
        {
            pos = i+1;
            break;
        }
        else
            pos = -1;
    }
    if (pos == -1)
        printf("Number %d Not Exist\n",num);
    else
        printf("The Number %d at Position %d\n", num, pos);
    return 0;
}
