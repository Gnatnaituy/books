#include <stdio.h>
#include "Chapter_4/Practices/4_12.c"


int main(void)
{
    char s[100];
    itoa(1234, s);
    printf("%s", s);

    return 0;
}
