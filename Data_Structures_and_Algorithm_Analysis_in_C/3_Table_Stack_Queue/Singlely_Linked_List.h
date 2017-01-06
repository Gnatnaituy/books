#ifndef Linked_List_H
#define Linked_List_H

struct Node; //Node结构体变量声明
typedef struct Node *PtrToNode; //typedef定义新的类,名字叫做PtrToNode,类型是指向Node结构体的指针
typedef PtrToNode List; //定义一个链表，其储存的数据格式是Node结构体，名字是List
typedef PtrToNode Position;
typedef int ElementType;
typedef int Status;


List CreateList(void);
List MakeEmpty(List L);

Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);

Status isEmpty(List L);
Status isLast(Position P, List L);

void Insert(ElementType X, List L, Position P);
void Delete(ElementType X, List L);
void DeleteList(List L);
void PrintList(List L);

ElementType Retrieve(Position P);

#endif

struct Node
{
    ElementType Element; // 存储的数据
    Position    Next;  // 下一个Node的地址
};