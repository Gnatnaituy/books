//
// Created by Hasaker on 2018/11/8.
//

#ifndef DATASTRUCTUREANDALGORITHM_ALGORITHM_H
#define DATASTRUCTUREANDALGORITHM_ALGORITHM_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define MAXSIZE     20

typedef int Status;
typedef int KeyType;

typedef struct {
    KeyType key;
} RecordType, RcdType;

typedef struct {
    RcdType * rcd;
    int length;
} RcdSqList;


Status CreateList(RcdSqList &L);
void Display(RcdSqList &L);
void InsertSort(RcdSqList &L);
int testInsertSort(int argc, char ** argv);
void ShellSort(RcdSqList &L);
int testShellSort(int argc, char ** argv);

#endif //DATASTRUCTUREANDALGORITHM_ALGORITHM_H
