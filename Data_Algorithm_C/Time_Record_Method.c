#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int Sum(int N)
{
    int i, PartialSum;

    PartialSum = 0;
    for(i=0;i<=N;i++)
        PartialSum += i*i*i;
    return PartialSum;
}

int main()
{
    double duration;
    clock_t start, finish;

    start = clock();
    printf("Time to calculate %d by for is ", Sum(10000));
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds.", duration);
    printf("\n");
}
