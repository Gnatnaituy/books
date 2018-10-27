//
// Created by Hasaker on 2018/10/26.
//

#include "../LinearDataStructure/LinearDataStructure.h"

void arrange(SqQueue_Char A, SqQueue_Char &B, SqQueue_Char &C) {
    CharElementType e;
    InitQueue_Char(B);
    InitQueue_Char(C);
    while (!QueueEmpty_Char(A)) {
        DeQueue_Char(A, e);
        if (e == 'H')
            EnQueue_Char(B, e);
        else
            EnQueue_Char(C, e);
    }
}

void carriageArrange() {
    SqQueue_Char A,B,C;
    CharElementType e;

    InitQueue_Char(A);
    printf("请输入软卧S和硬座H的一个组合车组：");
    for(scanf("%c", &e); e!='\n';)	{
        EnQueue_Char(A,e);
        scanf("%c",&e);
    }

    arrange(A,B,C);

    printf("硬座车组：");
    OutQueue_Char(B);
    printf("软卧车组：");
    OutQueue_Char(C);

}
