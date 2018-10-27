//
// Created by Hasaker on 2018/10/26.
//

#include "LinearDataStructure.h"


Status InitQueue(SqQueue &Q) {
    Q.element = (ElementType *) malloc(MAXSIZE * sizeof(ElementType));
    if (!Q.element)
        return OVERFLOW;
    Q.front = Q.rear = 0;
    Q.maxSize = MAXSIZE;

    return OK;
}


Status QueueEmpty(SqQueue &Q) {
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}


Status EnQueue(SqQueue &Q, ElementType e) {
    if ((Q.rear + 1) % Q.maxSize == Q.front)
        return ERROR;
    Q.element[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxSize;

    return OK;
}


Status DeQueue(SqQueue &Q, ElementType &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.element[Q.front];
    Q.front = (Q.front + 1) % Q.maxSize;

    return OK;
}


Status OutQueue(SqQueue Q) {
    ElementType e;
    if (QueueEmpty(Q)) {
        printf("This is a empty queue !");
    } else {
        while (!QueueEmpty(Q)) {
            DeQueue(Q, e);
            printf("%6d", e);
        }
        printf("\n");
    }
}


Status InitQueue_Char(SqQueue_Char &Q) {
    Q.element = (CharElementType *) malloc(MAXSIZE * sizeof(CharElementType));
    if (!Q.element)
        return OVERFLOW;
    Q.front = Q.rear = 0;
    Q.maxSize = MAXSIZE;

    return OK;
}


Status QueueEmpty_Char(SqQueue_Char &Q) {
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}


Status EnQueue_Char(SqQueue_Char &Q, CharElementType e) {
    if ((Q.rear + 1) % Q.maxSize == Q.front)
        return ERROR;
    Q.element[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxSize;

    return OK;
}


Status DeQueue_Char(SqQueue_Char &Q, CharElementType &e) {
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.element[Q.front];
    Q.front = (Q.front + 1) % Q.maxSize;

    return OK;
}


Status OutQueue_Char(SqQueue_Char Q) {
    CharElementType e;
    if (QueueEmpty_Char(Q))
        printf("This is a empty queue !");
    else {
        while (!QueueEmpty_Char(Q)) {
            DeQueue_Char(Q, e);
            printf("%c", e);
        }
        printf("\n");
    }
}