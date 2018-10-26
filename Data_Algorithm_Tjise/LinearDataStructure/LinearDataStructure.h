//
// Created by Hasaker on 2018/10/23.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINEAR_DATA_STRUCTURE_H
#define DATASTRUCTUREANDALGORITHM_LINEAR_DATA_STRUCTURE_H

#define OK          1
#define ERROR       0
#define TRUE        1
#define FALSE       0
#define OVERFLOW   -2

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5
#define MAXSIZE         30

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


// SequenceQueue.cpp
Status InitQueue(SqQueue &Q);
Status QueueEmpty(SqQueue &Q);
Status EnQueue(SqQueue &Q, ElementType e);
Status DeQueue(SqQueue &Q, ElementType &e);
Status OutQueue(SqQueue Q);
Status InitQueue_Char(SqQueue_Char &Q);
Status QueueEmpty_Char(SqQueue_Char &Q);
Status EnQueue_Char(SqQueue_Char &Q, CharElementType e);
Status DeQueue_Char(SqQueue_Char &Q, CharElementType &e);
Status OutQueue(SqQueue_Char Q);
void test_queue();

// SequenceStack
Status InitStack(SqStack &S);
Status StackEmpty(SqStack &S);
Status Push(SqStack &S, ElementType e);
Status Pop(SqStack &S, ElementType &e);
void OutStack(SqStack S);
Status InitStack_Sq(SqStack_Char &S, int size, int increment);
Status StackEmpty_Sq(SqStack_Char &S);
Status Push_Sq(SqStack_Char &S, CharElementType e);
Status Pop_Sq(SqStack_Char &S, CharElementType &e);
Status GetTop_Sq(SqStack_Char &S, CharElementType &e);
void test_sq_stack();

// bracket_match.cpp
Status bracket_matching(char * expression, int n);

// decimal_conversion.cpp
void conversion();

// carriage_organize.cpp
void Arrange(SqQueue A, SqQueue &B, SqQueue &C);
void CarriageArrange();

#endif //DATASTRUCTUREANDALGORITHM_LINEAR_DATA_STRUCTURE_H
