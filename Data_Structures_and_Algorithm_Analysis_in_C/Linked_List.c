#ifdef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int isEmpty(List L);
int isLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position);

#endif

struct Node
{
    ElementType Element;
    Position    Next;
};

int isEmpty(List L)
{
    return L->Next == NULL;
}


int isLast(List L)
{
    return P->Next == NULL;
}


Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while(P != NULL && P->Element != X)
        P = P->Next

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
        FataError("Out of space!!!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->next = TmpCell;
}


void DeleteList(List L)
{
    Position P, Tmp;

    p = L->Next;  //Header assumed
    L->Next = NULL;
    while(p != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}


int main()
{
    L = {1,2,3,4,5,6,7,8,9};
    printf(isEmpty(L));
}
