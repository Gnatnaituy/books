#include "Singlely_Linked_List.h"
#include <stdlib.h>
#include <stdio.h>


List CreateList(void)
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


Status isEmpty(List L)
{
    return L->Next == NULL;
}


Status isLast(Position P, List L)
{
    return P->Next == NULL;
}


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

void PrintList(List L)
{
    Position p;
    p = L;
    while( p->Next != NULL)
    {
        printf( "%c", p->Next->Element );
        p = p->Next;
    }
    printf("\n");
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

int main()
{
    List L;
    Position p;
    char c, d;
    int q;
    L = CreateList();
    printf("是否为空: %d\n", isEmpty(L));
    
    p = L;
    printf("请输入二进制数，按#号键结束：\n");
    scanf("%c", &c);
    while(c != '#')
    {
        Insert(c, L, p);
        p = p->Next;
        scanf("%c", &c);
    }
    getchar();
    printf("当前链表为: ");
    PrintList(L);

    return 0;
}
