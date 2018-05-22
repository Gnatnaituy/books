//
// Created by Horo on 2/11/17.
//

#include <stdio.h>
#include <stdlib.h>

#define MinTableSize 10

#ifndef _Quadratic_Probing_H

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

#endif

enum KindOfEntry{Legitimate, Empty, Deleted};

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
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
    HashTable H;
    int i;

    if(TableSize < MinTableSize)
    {
        printf("Table size is too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        printf("Put of space !");
    H->TableSize = TableSize;
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if(H->TheCells == NULL)
        printf("Out of space !");
    for(i=0; i<H->TableSize; i++)
        H->TheCells[i].Info = Empty;

    return H;
}


Position Find(ElementType Key, HashTable H)
{
    Position CurrentPosition;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPosition = Hash(Key, H->TableSize);
    while(H->TheCells[CurrentPosition].Info != Empty && H->TheCells[CurrentPosition].Element != Key)
    {
        CurrentPosition += 2 * ++CollisionNum - 1;
        if(CurrentPosition >= H->TableSize)
            CurrentPosition -= H->TableSize;
    }

    return CurrentPosition;
}


void Insert(ElementType Key, HashTable H)
{
    Position Pos;

    Pos = Find(Key, H);
    if(H->TheCells[Pos].Info != Legitimate)
    {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}


HashTable Rehash(HashTable H)
{
    int i, OldSize;
    Cell *OldCells;

    OldCells = H->TheCells;
    OldSize = H->TableSize;

    H = InitializeTable(2 * OldSize);

    for(i=0; i<OldSize; i++)
        if(OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, H);

    free(OldCells);

    return H;
}