/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_10.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Write a function to calculate the sum of all elements in an array.
 */
#include <stdio.h>
int sumArray(int arr[], int size);
void main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = sumArray(arr, size);
    printf("The sum of the array elements is: %d\n", result);
}
int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}