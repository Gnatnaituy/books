//
// Created by Hasaker on 2018/10/23.
//

//
// Created by Hasaker on 2018/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinearDataStructure.h"


Status InitStack(SqStack &S) {
    S.base = (ElementType *) malloc(STACK_INIT_SIZE * sizeof(ElementType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = 0;
    S.size = STACK_INIT_SIZE;
    S.increment = STACK_INCREMENT;
    return OK;
}


Status StackEmpty(SqStack &S) {
    if (S.top == 0)
        return TRUE;
    else
        return FALSE;
}


Status Push(SqStack &S, ElementType e) {
    if (S.top >= S.size) {
        // realloc 是 reallocate的缩写 及'重新分配'
        auto * newBase = (ElementType *) realloc(S.base, (S.size + S.increment) * sizeof(ElementType));
        if (newBase == nullptr)
            return OVERFLOW;
        S.base = newBase;
        S.size += S.increment;
    }
    S.base[S.top++] = e;

    return OK;
}


// &e表示对e的引用 例如int &a = b; 其实a就是b,只是给b取了另一个名字
Status Pop(SqStack &S, ElementType &e) {
    if (StackEmpty(S) == FALSE) {
        S.top--;
        e = S.base[S.top];
    } else {
        printf("已经到栈底啦!\n");
    }

    return OK;
}


void OutStack(SqStack S) {
    ElementType e;

    if (StackEmpty(S) == TRUE) {
        printf("这是一个空栈!\n");
    } else {
        while (StackEmpty(S) == FALSE) {
            Pop(S, e);
            printf("|%d|\n", e);
        }
        printf("\n");
    }
}


Status InitStack_Sq(SqStack_Char &S, int size, int increment){
    S.base = (CharElementType *) malloc(size * sizeof(CharElementType));
    if (S.base == nullptr)
        return OVERFLOW;
    S.top = 0;
    S.size = size;
    S.increment = increment;

    return OK;
}


Status StackEmpty_Sq(SqStack_Char &S) {
    if (S.top == 0)
        return TRUE;
    else
        return FALSE;
}


Status Push_Sq(SqStack_Char &S, CharElementType e) {
    CharElementType * newBase;
    if (S.top >= S.size) {
        newBase = (CharElementType *) realloc(S.base, (S.size + S.increment) * sizeof(CharElementType));
        if (newBase == nullptr)
            return OVERFLOW;
        S.base = newBase;
        S.size += S.increment;
    }
    S.base[S.top++] = e;
    return OK;
}


Status Pop_Sq(SqStack_Char &S, CharElementType &e) {
    if (StackEmpty_Sq(S) == FALSE) {
        S.top--;
        e = S.base[S.top];
    } else {
        printf("This stack is already empty !");
    }

    return OK;
}


Status GetTop_Sq(SqStack_Char &S, CharElementType &e) {
    if (StackEmpty_Sq(S) == FALSE) {
        e = S.base[S.top - 1];
    } else {
        printf("This is a empty stack !");
    }
    return OK;
}


void test_sq_stack() {
    SqStack s;
    ElementType a;
    int choice;

    printf("第一次使用必须初始化!\n");
    do {
        printf("\n-----菜单-----\n");
        printf("1 初始化顺序栈\n");
        printf("2 插入一个元素\n");
        printf("3 删除栈顶元素\n");
        printf("4 结束程序运行\n");
        printf("-------------\n");
        printf("请输入你的选择: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                InitStack(s);
                OutStack(s);
                break;
            case 2:
                printf("请输入要插入的元素数据: ");
                scanf("%d", &a);
                Push(s, a);
                printf("入栈之后的栈:\n");
                OutStack(s);
                printf("\n");
                break;
            case 3:
                Pop(s, a);
                printf("栈顶元素%d出栈之后的栈:\n", a);
                OutStack(s);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    } while (choice <= 4);
}


