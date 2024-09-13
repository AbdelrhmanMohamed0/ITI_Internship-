/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_4.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Arithmetic Operations with Error Handling.
 */
#include <stdio.h>
int main(void)
{
    int num1, num2;
    char op;
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);
    printf("Enter two operands: ");
    scanf("%d %d", &num1, &num2);
    switch (op)
    {
    case '+':
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        break;
    case '/':
        if (num2 == 0)
            printf("Error! Division by zero.\n");
        else
            printf("%d / %d = %0.2f\n", num1, num2, (float)num1 / num2);
        break;
    default:
        printf("Error! Invalid operator.\n");
    }   
    return 0;
}
