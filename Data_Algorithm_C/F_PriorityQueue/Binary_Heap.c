//
// Created by Horo on 2/11/17.
//
#include <stdlib.h>
#include <stdio.h>

#define MinPriorityQueueSize 10

typedef int ElementType;

typedef struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType  *Elements;
} *PriorityQueue;


int IsEmpty(PriorityQueue H)
{
    if(H->Size == 0)
        return 1;
    else
        return 0;
}


int IsFull(PriorityQueue H)
{
    if(H->Size == H->Capacity)
        return 1;
    else
        return 0;
}


PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;

    if(MaxElements < MinPriorityQueueSize)
        exit(EXIT_FAILURE);

    H = malloc(sizeof(struct HeapStruct));
    if(H == NULL)
        exit(EXIT_FAILURE);
    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
    if(H->Elements == NULL)
        exit(EXIT_FAILURE);

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = 0;

    return H;
}


void Insert(ElementType X, PriorityQueue H)
{
    int i;

    if(IsFull(H))
    {
        printf("Heap is full !");
        return;
    }

    for(i = ++H->Size; H->Elements[i/2] > X; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}


ElementType DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;

    if(IsEmpty(H))
    {
        printf("Heap is empty !");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for(i = 1; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if(Child != H->Size && H->Elements[Child +1] < H->Elements[Child])
            Child++;
        if(LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}


int main()
{
    PriorityQueue MyHeap;
    MyHeap = Initialize(1007);
    Insert(123, MyHeap);
    Insert(1224, MyHeap);
    Insert(12, MyHeap);
    Insert(1202, MyHeap);
    int a = DeleteMin(MyHeap);
    printf("%d\n", a);
    printf("%d\n", MyHeap->Elements[1]);
    int *b = MyHeap->Elements;
    int c = b;
    int d = b[1];
    int e = b[2];
    int f = b[0];
    printf("%d", b);

    return 0;
}