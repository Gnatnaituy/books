#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          data;
    struct Node *Next;
} Node, *pNode;

pNode CreateList()
{
    pNode List, p_new, pNow;
    List = malloc(sizeof(pNode));
    if(List == NULL)
    {
        printf("Failed to malloc.");
        exit(EXIT_FAILURE);
    }
    List->data = 0;
    List->Next = NULL;
    pNow = List;

    int i, length, data;
    printf("Please input the length of the list you want to create: ");
    scanf("%d", &length);
    for(i=1; i<length+1; i++)
    {
        printf("Please input the %dth data: ", i);
        scanf("%d", &data);

        p_new = (pNode)malloc(sizeof(Node));
        if(p_new == NULL)
        {
            printf("Failed to malloc.");
            exit(EXIT_FAILURE);
        }
        p_new->data = data;
        p_new->Next = NULL;
        pNow->Next = p_new;
        pNow = p_new;
    }
    return List;
}

void PrintList(pNode List)
{
    pNode pTmp = List->Next;
    printf("List: ");
    while(pTmp != NULL)
    {
        printf("[%d]", pTmp->data);
        pTmp = pTmp->Next;
    }
    putchar('\n');
}

void ChangeNeighborElement(pNode List)
{
    if(List == NULL)
    {
        printf("List is empty!");
        exit(EXIT_FAILURE);
    }
    pNode pTmp = List->Next;
    List->Next = List->Next->Next;
    pTmp->Next = List->Next->Next;
    List->Next->Next = pTmp;
    printf("The List after ChangeNeighborElement: ");
    PrintList(List);
}

int main()
{
    pNode List;
    List = CreateList();
    PrintList(List);
    ChangeNeighborElement(List);

    return 0;
}
