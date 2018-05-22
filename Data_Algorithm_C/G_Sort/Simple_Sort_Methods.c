//
// Created by Horo on 2/12/17.
//

// 插入排序
void InsertionSort(int A[], int N)
{
    int j, P, Tmp;

    for(P = 1; P < N; P++)
    {
        Tmp = A[P];
        for(j = P; j > 0 && A[j-1] > Tmp; j++)
            A[j] = A[j-1];
        A[j] = Tmp;
    }
}

// 希尔排序
void ShellSort(int A[], int N)
{

}
