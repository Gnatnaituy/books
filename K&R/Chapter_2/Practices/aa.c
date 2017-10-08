#include <stdio.h>

int main()
{
    int a[3][2]={10,20,30,40,50,60}, (*p)[2];
    p = a;
    printf("%d\n", *(*(p + 2) + 1));

    return 0;
}