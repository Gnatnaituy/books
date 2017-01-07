#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *pPrevious;
    int         data;
    struct Node *pNext;
} Node, *pNode;

pNode CreateList()
{
    pNode List, p_new, pNow;
    List = (pNode)malloc(sizeof(pNode));
    if(List == NULL)
    {
        printf("Failed to malloc.");
        exit(EXIT_FAILURE);
    }
    List->pPrevious = NULL;
    List->data = 0;
    List->pNext = NULL;
    pNow = List;

    int i, length, data;
    printf("Please input the length of the list you want to create: ");
    scanf("%d", &length);
    for(i=1; i<length+1; i++)
    {
        printf("Please input the %dth data: ", i);
        scanf("%d", &data);

        p_new = (pNode)malloc(sizeof(pNode));
        if(p_new == NULL)
        {
            printf("Failed to malloc.");
            exit(EXIT_FAILURE);
        }
        p_new->data = data;
        p_new->pPrevious = pNow;
        p_new->pNext = NULL;
        pNow->pNext = p_new;
        pNow = p_new;
    }
    return List;
}

void PrintList(pNode List)
{
    pNode pTmp = List->pNext;
    printf("List: ");
    while(pTmp != NULL)
    {
        printf("[%d]", pTmp->data);
        pTmp = pTmp->pNext;
    }
    putchar('\n');
}

pNode ChangeNeighborElement(pNode List)
{
    if(List == NULL)
    {
        printf("List is empty!");
        exit(EXIT_FAILURE);
    }

    pNode pTmp = List->pNext;
    List->pNext = List->pNext->pNext;
    List->pNext->pPrevious = List;
    pTmp->pNext = List->pNext->pNext;
    List->pNext->pNext->pPrevious = pTmp;
    List->pNext->pNext = pTmp;
    pTmp->pPrevious = List->pNext;

    return List;
}

int main()
{
    pNode List;
    List = CreateList();
    PrintList(List);
    ChangeNeighborElement(List);
    printf("The list after ChangeNeighborElement: ");
    PrintList(List);

    return 0;
}

