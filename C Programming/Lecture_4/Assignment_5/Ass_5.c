/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_5.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 18/7/2024
 *  version    : v1.0
 *  require    : Write a C code that defines a function which takes an
 *               array as input argument and apply the bubble sorting
 *               algorithm on it, then print the result.
 */
#include <stdio.h>
void bubbleSort(int arr[], int size);
int main(void)
{
    int arr[] = {5, 2, 8, 12, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
void bubbleSort(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}