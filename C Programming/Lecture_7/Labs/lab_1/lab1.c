#include <stdio.h>
#define enable_1 1
#ifdef enable_1
#warning "This is a warning message"
#endif
#ifndef enable_1
#error "This is an error message"
#endif

void main(void)
{

    if (enable_1 == 1)
    {
        printf("Done\n");
    }
    else
    {
        printf("Not done\n");
    }
}