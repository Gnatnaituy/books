#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while(low <= high && x != v[mid])
    {
        if(x < v[mid])
            high = mid  -1;
        else if(x > v[mid])
            low = mid + 1;
        mid = (low  + high) / 2;
    }

    if(x == v[mid])
        return x;
    else
        return -1;
}

int main(void)
{
    int v[] = {1,1,1,1,1,2,3,4,5,6,7,8};
    int x = binsearch(3, v, 12);
    printf("%d\n", x);

    return 0;
}