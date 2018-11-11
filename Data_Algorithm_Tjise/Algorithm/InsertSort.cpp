//
// Created by Hasaker on 2018/11/8.
//

#include "Algorithm.h"


Status CreateList(RcdSqList &L) {
    L.rcd = (RcdType *) malloc(MAXSIZE * sizeof(RcdType));
    if (L.rcd == nullptr)
        return OVERFLOW;
    return OK;
}


void Display(RcdSqList &L) {
    for (int i = 1; i < L.length + 1; ++i) {
        printf("%6d", L.rcd[i].key);
    }
    printf("\n");
}


void InsertSort(RcdSqList &L) {
    for (int i = 1; i < L.length; i++) {
        if (L.rcd[i + 1].key < L.rcd[i].key) {
            L.rcd[0] = L.rcd[i + 1];
            int j = i + 1;
            do {
                j--;
                L.rcd[j + 1] = L.rcd[j];
            } while (L.rcd[0].key < L.rcd[j - 1].key);
            L.rcd[j] = L.rcd[0];
        }
        Display(L);
    }
}


int testInsertSort(int argc, char ** argv) {
    RcdSqList L;
    CreateList(L);
    printf("请输入要排序的集合的长度(length < 20): ");
    scanf("%d", &L.length);
    printf("请输入待排序的各个数字: ");
    for (int i = 1; i < L.length + 1; ++i)
        scanf("%d", &L.rcd[i].key);
    printf("你输入的原始集合是:");
    Display(L);
    InsertSort(L);
    printf("排序后的结果是:");
    Display(L);
}