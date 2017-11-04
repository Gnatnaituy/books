#include <stdio.h>
#include "Chapter_4/quick_sort.c"


int main(void)
{
    int a[] = {2333, 123, 1, 5, 56, 2, 55, 789};
    quick_sort(a, 0, 7);

    return 0;
}
