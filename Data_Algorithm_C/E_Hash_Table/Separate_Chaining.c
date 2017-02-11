//
// Created by Horo on 2/9/17.
//

#include <stdlib.h>
#include <stdio.h>


#ifndef _Separate_Chaining_H

struct ListNode;
typedef struct ListNode *Position;
typedef Position List;
struct HashTab;
typedef struct HashTab *HashTable;
typedef int ElementType;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable T);
Position Find(ElementType Key, HashTable T);
void Insert(ElementType Key, HashTable T);
ElementType Retrieve(Position P);

#endif

struct ListNode
{
    ElementType Element;
    Position           Next;
};

struct HashTab
{
    int TableSize;
    List *TheLists;
};


int Hash(const int *Key, int TableSize)
{
    unsigned int HashValue = 0;

    while(*Key != '\0')
        HashValue = (HashValue << 5) + *Key++;

    return HashValue % TableSize;
}


HashTable InitializeTable(int TableSize)
{
    HashTable T;
    int i;

    if(TableSize < 10)
    {
       printf("Table size too small !");
        return NULL;
    }

    T = malloc(sizeof(struct HashTab));
    if(T == NULL)
        printf("Out of space !");

    T->TableSize = TableSize;

    T->TheLists = malloc(sizeof(List) * T->TableSize);
    if(T->TheLists == NULL)
        printf("Out of space !");

    T->TheLists = malloc(T->TableSize * sizeof(struct ListNode));

    return T;

}


Position Find(ElementType Key, HashTable T)
{
    Position P;
    List L;

    L = T->TheLists[Hash(Key, T->TableSize)];
    P = L->Next;
    while(P != NULL && P->Element != Key)
        P = P->Next;

    return P;

}


void Insert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key , H);
    if(Pos == NULL)
    {
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL)
        {
            printf("Out of space !");
        }
        else
        {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
                 NewCell->Element = Key;
                 L->Next = NewCell;
        }
    }
}