#include "Linked_List.h"
#include <stdlib.h>

// Place in the interface file
struct Node
{
    ElementType Element;
    Position    Next;
};

List MakeEmpty(List L)
{
    if(L != NULL)
        DeleteList(L);
    L = malloc(sizeof(struct Node));
    if(L == NULL)
        printf("List is NULL\n");
    L->Next = NULL;
    return L;
}

// Return Ture if L is empty
int isEmpty(List L)
{
    return L->Next == NULL;
}

// return ture if P is in the last position of L
// Paramater is not used in this implementation
int isLast(Position P, List L)
{
    return P->Next == NULL;
}

// Return Position of X in L, NULL if not found
Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while(P != NULL && P->Element != X)
        P = P->Next;

    return P;
}


Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;

    return P;
}


// 链表的删除例程
void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if(!isLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}


void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("List is NULL\n");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}


void DeleteList(List L)
{
    Position P, Tmp;

    P = L->Next;  //Header assumed
    L->Next = NULL;
    while(P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

