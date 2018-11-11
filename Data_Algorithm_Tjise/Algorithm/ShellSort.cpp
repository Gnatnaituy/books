//
// Created by Hasaker on 2018/11/8.
//

#include "Algorithm.h"


void ShellSort(RcdSqList &L) {
    int j;
    for (int increment = L.length / 2; increment > 0; increment /= 2) {
        for (int i = increment + 1; i < L.length + 1; i++) {
            L.rcd[0] = L.rcd[i];
            for (j = i - increment; j > 0; j -= increment) {
                if (L.rcd[0].key < L.rcd[j].key)
                    L.rcd[j + increment] = L.rcd[j];
                else
                    break;
            }
            L.rcd[j + increment] = L.rcd[0];
            Display(L);
        }
    }
}


int  testShellSort(int argc, char ** argv) {
    RcdSqList L;
    CreateList(L);
    printf("请输入要排序的集合的长度(length < 20):");
    scanf("%d", &L.length);
    printf("请输入待排序的各个数字:");
    for (int i = 1; i < L.length + 1; ++i) {
        scanf("%d", &L.rcd[i].key);
    }
    printf("你输入的原始集合是:");
    Display(L);
    ShellSort(L);
    printf("排序后的结果是:");
    Display(L);

    return 0;
}