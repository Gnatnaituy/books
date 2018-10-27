//
// Created by Hasaker on 2018/10/23.
//

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
        auto * newBase = (ElementType *) realloc(S.base, (S.size + S.increment) * sizeof(ElementType));
        if (newBase == nullptr)
            return OVERFLOW;
        S.base = newBase;
        S.size += S.increment;
    }
    S.base[S.top++] = e;

    return OK;
}


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


Status InitStack_Char(SqStack_Char &S, int size, int increment){
    S.base = (CharElementType *) malloc(size * sizeof(CharElementType));
    if (S.base == nullptr)
        return OVERFLOW;
    S.top = 0;
    S.size = size;
    S.increment = increment;

    return OK;
}


Status StackEmpty_Char(SqStack_Char &S) {
    if (S.top == 0)
        return TRUE;
    else
        return FALSE;
}


Status Push_Char(SqStack_Char &S, CharElementType e) {
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


Status Pop_Char(SqStack_Char &S, CharElementType &e) {
    if (StackEmpty_Char(S) == FALSE) {
        S.top--;
        e = S.base[S.top];
    } else {
        printf("This stack is already empty !");
    }

    return OK;
}


Status GetTop_Char(SqStack_Char &S, CharElementType &e) {
    if (StackEmpty_Char(S) == FALSE) {
        e = S.base[S.top - 1];
    } else {
        printf("This is a empty stack !");
    }
    return OK;
}
