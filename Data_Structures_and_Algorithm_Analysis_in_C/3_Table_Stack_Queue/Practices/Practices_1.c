#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    int Element;
    Position Next;
};

void printArray(List L)
{
    Position p;
    p = L;
    while( p->Next != NULL)
    {
        printf( "%d", p->Next->Element );
        p = p->Next;
    }
    printf("\n");
}

Position CreateTable(void)
{
    PtrToNode L;
    L = malloc(sizeof(struct Node));
    if(L == NULL)
    {
        printf("out of space");
        return 0;
    }
    L->Next = NULL;
    return L;
}

int main()
{
    int i;
    Position L,p;
    PtrToNode TmpCell;
    L = CreateTable();
    p = L;
    for(i=0; i<3; i++)
    {
        TmpCell = malloc(sizeof(struct Node));
        if(TmpCell == NULL)
        {
            printf("error");
            return 0;
        }
        p->Next = TmpCell;
        TmpCell->Element = i;
        TmpCell->Next = NULL;
        p = TmpCell;
    }
    printArray(L);
}