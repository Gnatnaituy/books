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
#define LIST_INIT_SIZE  100
#define LIST_INCREMENT  10


// Data type of LinearDataStructure
typedef int ElementType;
typedef char CharElementType;
typedef int Status;


// SequenceList Node in int
typedef struct {
    ElementType * element;
    int length;
    int size;
    int increment;
} SqList;

// SequenceList Node in char
typedef struct {
    CharElementType * element;
    int length;
    int size;
    int increment;
} SqList_Char;

// SequenceStack Node in int
typedef struct {
    ElementType * base;
    int top;
    int size;
    int increment;
} SqStack;

// SequenceStack Node in char
typedef struct {
    CharElementType * base;
    int top;
    int size;
    int increment;
} SqStack_Char;

// SequenceQueue Node in int
typedef struct {
    ElementType * element;
    int front;
    int rear;
    int maxSize;
} SqQueue;

// SequenceQueue Node in char
typedef struct {
    CharElementType * element;
    int front;
    int rear;
    int maxSize;
} SqQueue_Char;

// SinglyLinkedList Node in int
typedef struct SLNode {
    ElementType data;
    struct SLNode * next;
} SLNode, * SinglyLinkedList;

// SinglyLinkedList Node in char
typedef struct SLNode_Char {
    CharElementType data;
    struct SLNode_Char * next;
} SLNode_Char, * SinglyLinkedList_Char;

// DoublyLinkedList Node in int
typedef struct DLNode {
    ElementType data;
    struct DLNode * previous;
    struct DLNode * next;
} DLNode, * DoublyLinkedList;

// DoublyLinkedList Node in char
typedef struct DLNode_Char {
    CharElementType data;
    struct DLNode_Char * previous;
    struct DLNode_Char * next;
} DLNode_Char, * DoublyLinkedList_Char;


// SequenceList
Status InitList(SqList &L);
Status ListEmpty(SqList L);
Status ListInsert(SqList &L, int i, ElementType e);
Status ListDelete(SqList &L, int i, ElementType &e);
void OutList(SqList L);
Status InitList_Char(SqList_Char &L);
Status ListEmpty_Char(SqList_Char L);
Status ListInsert_Char(SqList_Char &L, int i, CharElementType e);
Status ListDelete_Char(SqQueue_Char &L, int i, CharElementType &e);
void OutList_Char(SqQueue_Char L);


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


// LinkedList
// Singly Linked List
Status InitList_SL(SinglyLinkedList &L);
Status DestoryList_SL(SinglyLinkedList &L);
Status  ClearList_SL(SinglyLinkedList &L);
Status ListEmpty_SL(SinglyLinkedList L);
int ListLength_SL(SinglyLinkedList L);
SLNode * Search_SL(SinglyLinkedList L, ElementType e);
SLNode * NextElement_SL(SLNode * p);
SLNode * MakeNode_SL(ElementType e);
Status InsertAfter_SL(SLNode * p, SLNode * q);
Status DeleteAfter_SL(SLNode * p, ElementType &e);
Status ListInsert_SL(SinglyLinkedList &SL, int i, ElementType e);
Status ListDelete_SL(SinglyLinkedList &SL, int i, ElementType &e);
Status CreateList_SL(SinglyLinkedList &SL);
Status OutList_SL(SinglyLinkedList L);
void InverseList_SL(SinglyLinkedList SL);
void MergeList_SL(SinglyLinkedList &SLa, SinglyLinkedList &SLb, SinglyLinkedList &SLc);


// Methods of LinearDataStructure
void manipulateSequenceList();
void manipulateSequenceStack();
void manipulateSequenceQueue();
void manipulateSinglyLinkedList();
Status bracketMatch(char * expression, int n);
void decimalConversion();
void arrange(SqQueue_Char A, SqQueue_Char &B, SqQueue_Char &C);
void carriageArrange();

#endif //DATASTRUCTUREANDALGORITHM_LINEAR_DATA_STRUCTURE_H
