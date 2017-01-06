#ifndef Circular_Linked_List_H
#define Circular_Linked_List_H

typedef struct Node
{
    Position    Previous;
    ElemenType  Element;
    Position    Next;
} *PtrToNode;

typedef Node List;
typedef PtrToNode Position;
typedef int ElemenType;
typedef int Status;

List CreateList();
List MakeEmpty(List L);
Status isEmpty(List L);
void Insert(ElemenType X, List L, Position P);
void DeleteList(List L);