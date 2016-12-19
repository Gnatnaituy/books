typedef int ElementType;

#ifndef _Linked_List_H
#define _Linked_List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
Position Header(List L);
Position First(List L);
Position Advance(List L);
int isEmpty(List L);
int isLast(Position P, List L);
void Delete(ElementType X, List L);
void DeleteList(List L);
void Insert(ElementType X, List L, Position P);
ElementType Retrieve(Position P);
#endif
