/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_7.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 17/7/2024
 *  version    : v1.0
 *  require    : Write a recursive function to check if a string is a palindrome.
 */
#include <stdio.h>
int isPalindrome(char str[], int start, int end);
int main(void)
{
    char str[100];
    int start = 0;
    int end, i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character from the input string
    for (i = 0; str[i] != '\n'; i++)
        ;
    str[i] = '\0';
    end = i - 1;
    if (isPalindrome(str, start, end))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}

int isPalindrome(char str[], int start, int end)
{
    if (start >= end)
    {
        return 1;
    }
    if (str[start] != str[end])
    {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}