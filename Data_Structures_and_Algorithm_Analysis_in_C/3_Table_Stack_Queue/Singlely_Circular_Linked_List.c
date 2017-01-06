#include "Singlely_Circular_Linked_LIst.h"
#include <stdio.h>
#include <stdlib.h>


pNode CreateList()
{
    int i, length = 0, data = 0;
    pNode pTail = NULL, p_new = NULL;
    pNode pHead = (pNode)malloc(sizeof(Node));
    if(pHead == NULL)
    {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }       
    pHead->Data = 0;
    pHead->pNext = pHead;
    pTail = pHead;

    printf("请输入要创建链表的长度: ");
    scanf("%d", &length);

    for(i=1; i<length+1; i++)
    {
        p_new = (pNode)malloc(sizeof(Node));
        if(p_new == NULL)
        {
            printf("内存分配失败!\n");
            exit(EXIT_FAILURE);
        }

        printf("请输入第%d个节点的元素: ", i);
        scanf("%d", &data);

        p_new->Data = data;
        p_new->pNext = pHead;
        pTail->pNext = p_new;
        pTail = p_new;
    }
    return pHead;
}

void PrintList(pNode pHead)
{
    pNode pTmp = pHead->pNext;
    printf("此时的链表: ");
    while(pTmp != pHead)
    {
        printf(">%d>", pTmp->Data);
        pTmp = pTmp->pNext;
    }
    putchar('\n');
}

void isEmpty(pNode pHead)
{
    if(pHead->pNext == pHead)
        printf("链表为空\n");
    else
        printf("链表不为空\n");
    return ;
}

int ListLength(pNode pHead)
{
    int length = 0;
    pNode pTmp = pHead->pNext;
    while(pTmp != pHead)
    {
        length++;
        pTmp = pTmp->pNext;
    }
    return length;
}

void InsertNode(pNode pHead, int position, int data)
{
    if(position > 0 && position < ListLength(pHead) + 1)
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
    pNode pTmp = NULL;
    if(position > 0 && position < ListLength(pHead))
    {
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

        printf("删除成功！\n");
    }
    else
        printf("超出链表位置！\n");
    return ;
}

void DeleteList(pNode *ppHead)
{
    pNode pTmp= NULL;
    while(*ppHead != NULL)
    {
        if(*ppHead == (*ppHead)->pNext) // 如果只有一个节点
        {
            free(*ppHead);
            *ppHead = NULL;
        }
        else
        {
            pTmp = (*ppHead)->pNext->pNext;
            free((*ppHead)->pNext);
            (*ppHead)->pNext = pTmp;
        }
    }
    printf("释放链表成功!\n");
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

    DeleteList(&List);

    return 0;
}