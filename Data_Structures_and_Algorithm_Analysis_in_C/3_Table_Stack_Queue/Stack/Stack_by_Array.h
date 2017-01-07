#ifndef Stack_by_Array_H
#define Stack_by_Array_H

typedef struct StackRecord
{
		int Capacity;
		int TopofStack;
		struct StackRecord *Array;
} *Stack;

int isEmpty(Stack S);
int isFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X, Stack S);
void Pop(Stack S);

#endif
