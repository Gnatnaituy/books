#ifndef Singlely_Circular_Linked_List_H
#define Singlely_Circular_Linked_List_H


typedef struct Node
{   
    int         Data;
    struct Node *pNext;
} Node, *pNode;

pNode CreateList(); // 创建链表
void PrintList(pNode pHead); // 打印链表 
void isEmpty(pNode pHead); // 判断链表是否为空
int ListLength(pNode pHead); // 计算链表长度
void InsertNode(pNode pHead, int position, int data); // 插入节点
void DeleteNode(pNode pHead, int position); // 删除节点
void DeleteList(pNode *ppHead); // 删除链表

#endif