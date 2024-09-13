#include <stdio.h>


void main(void){

    int x=10;
    int *ptr = &x;
    printf("Value of x: %d\n", x);
    *ptr = 20;
    printf("Address of x: %p\n", &x);
    printf("Value of x: %d\n", x);
}