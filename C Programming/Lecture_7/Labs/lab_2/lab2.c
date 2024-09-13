#include <stdio.h>
#include <stdlib.h>
void main(void)
{

    int *ptr = malloc(5 * sizeof(unsigned short));
    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 3;
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", ptr[i]);
    }
}