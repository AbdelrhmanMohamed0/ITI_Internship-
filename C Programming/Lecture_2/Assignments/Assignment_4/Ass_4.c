/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_4.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Write a C code that prints the area of a polygon.
 */
#include <stdio.h>
#include <math.h>
#define PI 22.0/7.0
int main(void)
{
    int num_sides;
    float length_sides, area;
    printf("Please enter the number of sides : ");
    scanf("%d", &num_sides);
    printf("Please enter the length for each side : ");
    scanf("%f", &length_sides);    
    // Check if the number of sides is valid
    if(num_sides < 3) {
        printf("The number of sides must be at least 3.");
        return 1;
    }
    // Calculate the area of the regular polygon
    area =(num_sides * length_sides * length_sides)/(4.0 * tan(PI/ num_sides));
    printf("The area of this polygon is : %0.3f", area);
    return 0;
}
