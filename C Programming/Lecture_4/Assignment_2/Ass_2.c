/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_2.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 18/7/2024
 *  version    : v1.0
 *  require    : Create a program to print the addresses of array elements using
 *               both array indexing and pointers, and explain the memory layout 
 *               and address calculation.
 */
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Addresses using array indexing:\n");
    for (int i = 0; i < 5; i++) {
        printf("Address of arr[%d]: %p\n", i, (void*)&arr[i]);
    }
    printf("\nAddresses using pointers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Address of *(arr + %d): %p\n", i, (void*)(arr + i));
    }
    return 0;
}
