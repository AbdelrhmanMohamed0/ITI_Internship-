/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_6.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 18/7/2024
 *  version    : v1.0
 *  require    : Write a C code that define 3 int variables x, y and z
 *               and 3 pointers to int p, q and r. Set x, y, z to three 
 *               distinct values. Set p, q, r to the addresses of x, y, z
 *               respectively.
 */

#include <stdio.h>
int main() {
    int x, y, z;
    int *p, *q, *r;
    x = 10;
    y = 20;
    z = 30;
    p = &x;
    q = &y;
    r = &z;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("p = %p\n", p);
    printf("q = %p\n", q);
    printf("r = %p\n", r);
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);
    printf("*r = %d\n", *r);
    printf("Swapping pointers.\n");
    int *temp = r;
    r = p;
    p = q;
    q = temp;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("p = %p\n", p);
    printf("q = %p\n", q);
    printf("r = %p\n", r);
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);
    printf("*r = %d\n", *r);
    return 0;
}