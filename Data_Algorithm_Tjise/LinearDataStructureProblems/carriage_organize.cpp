//
// Created by Hasaker on 2018/10/26.
//

#include <stdio.h>
#include "../LinearDataStructure/LinearDataStructure.h"

void Arrange(SqQueue_Char A, SqQueue_Char &B, SqQueue_Char &C) {
    ElementType e;
    InitQueue(B);
    InitQueue(C);
    while (!QueueEmpty(A)) {
        DeQueue(A, e);
        if (e == 'H')
            EnQueue(B, e);
        else
            EnQueue(C, e);
    }
}

void CarriageArrange() {
    SqQueue A,B,C;
    CharElementType e;

    InitQueue(A);
    printf("请输入软卧S和硬座H的一个组合车组：");
    for(scanf("%c", &e); e!='\n';)	{
        EnQueue(A,e);
        scanf("%c",&e);
    }

    Arrange(A,B,C);

    printf("硬座车组：");
    OutQueue(B);
    printf("软卧车组：");
    OutQueue(C);

}
