#include <stdio.h>

int bitcount(unsigned x)
{
    int b;

    for(b = 0; x != 0; x >> 1)
        if(x & 01)
            b++;

    return b;
}

int main(void)
{
    int a = bitcount('222');
    printf("%d\n", a);

    return 0;
}
