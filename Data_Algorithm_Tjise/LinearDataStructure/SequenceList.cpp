//
// Created by Hasaker on 2018/10/23.
//

#include "LinearDataStructure.h"


Status InitList(SqList &L) {
    L.element = (ElementType *) malloc(LIST_INIT_SIZE * sizeof(ElementType));
    if (!L.element)
        exit(OVERFLOW);
    L.length = 0;
    L.size = LIST_INIT_SIZE;
    L.increment = LIST_INCREMENT;

    return OK;
}


Status ListEmpty(SqList L) {
    return L.length == 0 ? OK : ERROR;
}


Status ListInsert(SqList &L, int i, ElementType e) {
    if (L.length == L.size) {
        auto * newBase = (ElementType * ) realloc(L.element, (L.size + L.increment) * sizeof(ElementType));
        if (newBase == nullptr)
            return OVERFLOW;
        L.element = newBase;
        L.size += L.increment;
    } else if (i < 1 || i - 1 > L.length) {
        printf("Insert on a wrong place !");
    } else {
        for (int j = L.length - 1; j >= i - 1; j--) {
            L.element[j + 1] = L.element[j];
        }
        L.element[i - 1] = e;
        L.length++;
    }

    return OK;
}


Status ListDelete(SqList &L, int i, ElementType &e) {
    if (L.length == 0) {
        printf("This is a empty list !\n");
    } else if (i < 1 || i > L.length) {
        printf("Delete on a wrong place !");
    }

    e = L.element[i];

    for (int j = i; j < L.length; j++) {
        L.element[i] = L.element[i + 1];
    }
    L.length--;

    return OK;
}


void OutList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.element[i]);
    }
}


Status InitList_Char(SqList_Char &L) {
    L.element = (CharElementType *) malloc(LIST_INIT_SIZE * sizeof(CharElementType));
    if (!L.element)
        exit(OVERFLOW);
    L.length = 0;
    L.size = LIST_INIT_SIZE;
    L.increment = LIST_INCREMENT;

    return OK;
}


Status ListEmpty_Char(SqList_Char L) {
    return L.length == 0 ? OK : ERROR;
}


Status ListInsert_Char(SqList_Char &L, int i, CharElementType e) {
    if (L.length == L.size) {
        auto * newBase = (CharElementType * ) realloc(L.element, (L.size + L.increment) * sizeof(CharElementType));
        if (newBase == nullptr)
            return OVERFLOW;
        L.element = newBase;
        L.size += L.increment;
    } else if (i < 1 || i > L.length) {
        printf("Insert on a wrong place !\n");
    }

    for (int j = L.length - 1; j >= i - 1; j--) {
        L.element[j + 1] = L.element[j];
    }

    L.element[i - 1] = e;
    L.length++;

    return OK;
}


Status ListDelete_Char(SqList_Char &L, int i, CharElementType &e) {
    if (L.length == 0) {
        printf("This is a empty list !\n");
    } else if (i < 1 || i > L.length) {
        printf("Delete on a wrong place !\n");
    }

    e = L.element[i];

    for (int j = i; j < L.length; j++) {
        L.element[i] = L.element[i + 1];
    }
    L.length--;

    return OK;
}


void OutList_Char(SqList_Char L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.element[i]);
    }
}
