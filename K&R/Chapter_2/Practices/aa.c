#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3] = {10,20,30};
    printf("%d\n", sizeof(a)/sizeof(a[0]));

    return 0;
}