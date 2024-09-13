/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_1.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 18/7/2024
 *  version    : v1.0
 *  require    : encryption method.
 */
#include <stdio.h>
char str[] = "Hello World";
void Encrypt(char *msg);
void Decrypt(char *msg);
int main()
{
    printf("Message: %s\n", str);
    Encrypt(str);
    printf("Encrypted Message: %s\n", str);
    Decrypt(str);
    printf("Decrypted Message: %s\n", str);
}
void Encrypt(char *msg)
{
    int i, len;
    for (i = 0; msg[i] != '\0'; i++)
        ;
    len = i;
    for (i = 0; i < len; i++)
    {
        msg[i] = ((msg[i] ^ 5) + 3) ^ 22;
    }
}
void Decrypt(char *msg)
{
    int i, len;
    for (i = 0; msg[i] != '\0'; i++)
        ;
    len = i;
    for (i = 0; i < len; i++)
    {
        msg[i] = (((msg[i] ^ 22) - 3) ^ 5);
    }
}
