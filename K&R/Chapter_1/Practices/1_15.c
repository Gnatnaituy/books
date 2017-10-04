#include <stdio.h>

void FtoC()
{
    int fahr, cels;
    int lower=0, upper=300, step=20;

    fahr = lower;
    while(fahr <= upper)
    {
        cels = 5 * (fahr -32)/9;
        printf("%d\t%d\n", fahr, cels);
        fahr += step;
    }
}

int main()
{
    FtoC();

    return 0;
}