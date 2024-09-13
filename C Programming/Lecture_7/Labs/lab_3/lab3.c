#include <stdio.h>
#include <stdlib.h>
void main(void)
{

    int *ptr =(int *) calloc(5 , sizeof(int));
    printf("%p\n",ptr);
    ptr=realloc(ptr, 10 * sizeof(int));
    printf("%p\n",ptr);
}