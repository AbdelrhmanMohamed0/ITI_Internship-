/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_3.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 18/7/2024
 *  version    : v1.0
 *  require    : Create a simple calculator in C using an array of 
 *               pointers to functions for addition,subtraction,
 *               multiplication,and division.
 */
#include <stdio.h>
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int main(void) {
    int (*calculator[4])(int, int) = {add, subtract, multiply, divide};
    int choice, num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Select operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int result = calculator[choice - 1](num1, num2);
    printf("Result: %d\n", result);
    return 0;
}
int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}