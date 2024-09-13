/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_1.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 21/7/2024
 *  version    : v1.0
 *  require    : Create a program to perform arithmetic operations on complex numbers using structs.
 */
#include <stdio.h>
typedef struct complex
{
    float real;
    float imag;
} complex;
complex add(complex c1, complex c2);
complex sub(complex c1, complex c2);
complex mul(complex c1, complex c2);
complex div(complex c1, complex c2);
void display(complex c);
int main(void)
{
    complex c1, c2, result;
    printf("Enter the real and imaginary part of the complex number 1: ");
    scanf("%f %f", &c1.real, &c1.imag);
    printf("Enter the real and imaginary part of the complex number 2: ");
    scanf("%f %f", &c2.real, &c2.imag);
    result = add(c1, c2);
    display(result);
    result = sub(c1, c2);
    display(result);
    result = mul(c1, c2);
    display(result);
    result = div(c1, c2);
    display(result);
    return 0;
}
complex add(complex c1, complex c2)
{
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}
complex sub(complex c1, complex c2)
{
    complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}
complex mul(complex c1, complex c2)
{
    complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}
complex div(complex c1, complex c2)
{
    complex result;
    result.real = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    result.imag = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    return result;
}
void display(complex c)
{
    printf("Sum of the complex numbers: %.2f + %.2fi\n", c.real, c.imag);
}
