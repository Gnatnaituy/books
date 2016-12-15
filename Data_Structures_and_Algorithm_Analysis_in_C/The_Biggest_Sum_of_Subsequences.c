// 最大的子序列和问题
// 给定整数N1、N2、N3....（可能有负数),求j∑k=i
// Ak的最大值(如果所有整数均为负数，则最大子序列和为0)

#include "stdio.h"
#include "stdlib.h"  
#include "time.h" 
#define MAX3(a,b,c)  (a>b?(a>c?a:c):(b>c?b:c))

//解法1
int MaxSubsequenceSum1(const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for(i = 0; i < N; i++)
        for(j = i; j < N;j++)
        {
            ThisSum = 0;
            for (k = i;k <= j; k++)
                ThisSum += A[k];

            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    return MaxSum;
}

//解法2
int MaxSubsequenceSum2(const int A[], int N)
{
    int ThisSum, MaxSum, i, j;
    
    MaxSum = 0;
    for (i = 0;i < N;i++)
    {
        ThisSum = 0;
        for(j = i;j < N;j++)
        {
            ThisSum += A[j];

            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

//解法3
static int MaxSubSum(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if(Left == Right)  //Base Case 
        if(A[Left] > 0)
        {
            return A[Left];
        }
        else
        {
            return 0;
        }

    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);
    
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for(i = Center; i >= Left; i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for(i = Center + 1; i <= Right; i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return MAX3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum3(const int A[], int N)
{
    return MaxSubSum(A, 0, N - 1);
}

//算法4
int MaxSubsequenceSum4(const int A[], int N)
{
    int ThisSum, MaxSum, j;

    ThisSum = MaxSum = 0;
    for(j = 0; j < N;j++)
    {
        ThisSum += A[j];

        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main()
{
    const int A[10] = {1,3,4,-5,6,7,8,-10,-4,23};
    int N = 10;
    clock_t start, finish;
    double duration;

    printf("The answer is %d.\n", MaxSubsequenceSum4(A, N));

    start = clock();
    printf("The time costed by using MaxSubSequence1 is ");
    MaxSubsequenceSum1(A, N);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds.\n", duration);


    start = clock();
    printf("The time costed by using MaxSubSequence4 is ");
    MaxSubsequenceSum2(A, N);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds.\n", duration);


    start = clock();
    printf("The time costed by using MaxSubSequence3 is ");
    MaxSubsequenceSum3(A, N);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds.\n", duration);


    start = clock();
    printf("The time costed by using MaxSubSequence4 is ");
    MaxSubsequenceSum4(A, N);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds.\n", duration);
}
