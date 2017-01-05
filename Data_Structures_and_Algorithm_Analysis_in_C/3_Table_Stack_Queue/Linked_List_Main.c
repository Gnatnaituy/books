#include "Linked_List.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
    Position L, p;
    L = CreateList();
    printf("是否为空: %d\n", isEmpty(L));
    p = L;
    Insert(3, L, p);
    p = L->Next;
    Insert(6, L, p);
    printf("是否为空: %d\n", isEmpty(L));
    printf("打印链表: ");
    PrintList(L);

    return 0;
}