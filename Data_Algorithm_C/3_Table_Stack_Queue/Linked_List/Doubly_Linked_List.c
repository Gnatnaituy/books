#include "Doubly_Linked_List.h"
#include <stdlib.h>
#include <stdio.h>


pNode CreateList()
{
    int i, length = 0, data = 0;
    pNode pNext = NULL, pPrevious = NULL, pTail = NULL, p_new = NULL;
    pNode pHead = (pNode)malloc(sizeof(Node));
    if(pHead == NULL)
    {
        printf("内存申请失败!\n");
        exit(EXIT_FAILURE);
    }
    pHead->pNext = NULL;
    pHead->pPrevious = NULL;
    pHead->Data = 0;
    pTail = pHead;

    printf("请输入要创建链表的长度: ");
    scanf("%d", &length);

    for(i = 1; i < length + 1; i++)
    {
        p_new = (pNode)malloc(sizeof(Node));
        if(p_new == NULL)
        {
            printf("内存申请失败!\n");
            exit(EXIT_FAILURE);
        }

        printf("请输入第%d个节点的元素: ", i);
        scanf("%d", &data);

        p_new->Data = data;
        p_new->pPrevious = pTail;
        p_new->pNext = NULL;
        pTail->pNext = p_new;
        pTail = p_new;
    }
    return pHead;
}

void PrintList(pNode pHead)
{
    pNode pTmp = pHead->pNext;
    printf("此时的链表: ");
    while(pTmp != NULL)
    {
        printf(">%d>", pTmp->Data);
        pTmp = pTmp->pNext;
    }
    putchar('\n');
}

void isEmpty(pNode pHead)
{
    if(pHead->pNext == NULL)
        printf("链表为空\n");
    else
        printf("链表不为空\n");
    return ;
}

int ListLength(pNode pHead)
{
    int length = 0;
    pNode pTmp = pHead;
    while(pTmp->pNext != NULL)
    {
        length++;
        pTmp = pTmp->pNext;
    }
    return length;
}

void InsertNode(pNode pHead, int position, int data)
{
    if(position > 0 && position < ListLength(pHead) + 2)
    {
        pNode p_new = NULL;
        p_new = (pNode)malloc(sizeof(Node));
        if(p_new == NULL)
        {
            printf("内存分配失败！\n");
            exit(EXIT_FAILURE);
        }
        while(1)
        {
            position--;
            if(position == 0)
                break;
            pHead = pHead->pNext;
        }
        p_new->Data = data;
        p_new->pPrevious = pHead;
        p_new->pNext = pHead->pNext;
        pHead->pNext = p_new;

        printf("插入成功！\n");
    }
    else
        printf("超出链表长度！\n");
    return ;
}

void DeleteNode(pNode pHead, int position)
{
    if(position > 0 && position < ListLength(pHead) + 1)
    {
        pNode pTmp = NULL;
        while(1)
        {
            position--;
            if(position == 0)
                break;
            pHead = pHead->pNext;
        }
        pTmp = pHead->pNext->pNext;
        free(pHead->pNext);
        pHead->pNext = pTmp;
        printf("释放成功!\n");
    }
    else
        printf("超出链表长度!\n");
    return ;
}

void DeleteList(pNode pHead)
{
    if(pHead->pNext == NULL)
    {
        free(pHead);
        printf("释放链表成功!\n");
    }
    else
    {
        pNode pTmp = NULL;
        while(pHead->pNext != NULL)
        {
            pTmp = pHead->pNext;
            free(pHead);
            pHead = pTmp;
        }
        printf("释放链表成功!\n");
    }
    return ;
}

int main()
{
    pNode List;
    int position, data;

    List = CreateList();
    PrintList(List);
    isEmpty(List);
    printf("链表长度为: %d\n", ListLength(List));

    printf("请输入你要插入的节点位置: ");
    scanf("%d", &position);
    printf("请输入你要插入的节点数据: ");
    scanf("%d", &data);
    InsertNode(List, position, data);
    PrintList(List);

    printf("请输入你要删除的节点位置: ");
    scanf("%d", &position);
    DeleteNode(List, position);
    PrintList(List);

    DeleteList(List);

    return 0;
}