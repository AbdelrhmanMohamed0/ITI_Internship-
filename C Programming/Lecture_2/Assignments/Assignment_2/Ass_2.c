/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_2.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Write a C code that accept the radius of a circle
                 from the user and computes the area and perimeter.
 */
#include <stdio.h>
#define PI 3.14
int main(void)
{
    float radius;
    printf("the radius of the  circle : ");
    scanf("%f", &radius);
    printf("area of the circle = %.2f \n", (PI * radius * radius));
    printf("perimeter of the circle = %.2f \n", (2 * PI * radius));
    return 0;
}
