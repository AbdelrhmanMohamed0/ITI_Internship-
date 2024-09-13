/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    lab_3.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 15/7/2024
 *  version    : v1.0
 *  require    : Vowel or Consonant .
 */
#include <stdio.h>
int main(void)
{
    char ch, flag = 0;
    printf("Enter a single character: ");
    scanf("%c", &ch);
    // Convert the character to lowercase to handle both upper and lower case inputs
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += 32;
        flag = 1;
    }
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        if (flag == 1)
            printf("The character '%c' is a vowel.\n", ch - 32);
        else
            printf("The character '%c' is a vowel.\n", ch);
        break;
    default:
        if ((ch >= 'a' && ch <= 'z'))
            printf("The character '%c' is a consonant.\n", ch);
        else
            printf("The character '%c' is neither a vowel nor a consonant.\n", ch);
    }
    return 0;
}
