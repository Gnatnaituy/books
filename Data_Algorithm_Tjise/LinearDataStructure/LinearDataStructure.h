//
// Created by Hasaker on 2018/10/23.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINEAR_DATA_STRUCTURE_H
#define DATASTRUCTUREANDALGORITHM_LINEAR_DATA_STRUCTURE_H

#include <cstdlib>
#include <cstdio>
#include <iostream>

#define OK          1
#define ERROR       0
#define TRUE        1
#define FALSE       0
#define OVERFLOW   -2

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5
#define MAXSIZE         30


// Data type of LinearDataStructure
typedef int ElementType;
typedef char CharElementType;
typedef int Status;

typedef struct {
    ElementType * base;
    int top;
    int size;
    int increment;
} SqStack;

typedef struct {
    CharElementType * base;
    int top;
    int size;
    int increment;
} SqStack_Char;

typedef struct {
    ElementType * element;
    int front;
    int rear;
    int maxSize;
} SqQueue;

typedef struct {
    CharElementType * element;
    int front;
    int rear;
    int maxSize;
} SqQueue_Char;


// SequenceQueue
Status InitQueue(SqQueue &Q);
Status QueueEmpty(SqQueue &Q);
Status EnQueue(SqQueue &Q, ElementType e);
Status DeQueue(SqQueue &Q, ElementType &e);
Status OutQueue(SqQueue Q);
Status InitQueue_Char(SqQueue_Char &Q);
Status QueueEmpty_Char(SqQueue_Char &Q);
Status EnQueue_Char(SqQueue_Char &Q, CharElementType e);
Status DeQueue_Char(SqQueue_Char &Q, CharElementType &e);
Status OutQueue_Char(SqQueue_Char Q);


// SequenceStack
Status InitStack(SqStack &S);
Status StackEmpty(SqStack &S);
Status Push(SqStack &S, ElementType e);
Status Pop(SqStack &S, ElementType &e);
void OutStack(SqStack S);
Status InitStack_Char(SqStack_Char &S, int size, int increment);
Status StackEmpty_Char(SqStack_Char &S);
Status Push_Char(SqStack_Char &S, CharElementType e);
Status Pop_Char(SqStack_Char &S, CharElementType &e);
Status GetTop_Char(SqStack_Char &S, CharElementType &e);


// Methods of LinearDataStructure
void manipulateSequenceStack();
void manipulateSequenceQueue();
Status bracketMatch(char * expression, int n);
void decimalConversion();
void arrange(SqQueue_Char A, SqQueue_Char &B, SqQueue_Char &C);
void carriageArrange();

#endif //DATASTRUCTUREANDALGORITHM_LINEAR_DATA_STRUCTURE_H
