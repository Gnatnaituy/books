#include "Stack_by_Array.h"
#include <stdlib.h>
#include <stdio.h>

#define MinStackSize  5 

int isEmpty(Stack S)
{
		return S->TopofStack == NULL;
}

int isFull(Stack S)
{
		return S->TopofStack == MaxElements;
}

void MakeEmpty(Stack S)
{
		S->TopofStack = -1;
}

Stack CreateStack(int MaxElements)
{
		Stack S;
		
		if(MaxElements < MinStackSize)
		{
				printf("Stack size is too small!");
				exit(EXIT_FAILURE);
		}
		S = malloc(sizeof(Stack));
		if(S == NULL)
		{
				printf("Out of space!");
				exit(EXIT_FAILURE);
		}

		S->Array = malloc(sizeof(int) * MaxElements);
		if(S->Array == NULL)
		{
				printf("Out of space!");
				exit(EXIT_FAILURE);
		}
		S->Capacity = MaxElements;
		MakeEmpty(S);


		return S;
}

void DisposeStack(Stack S)
{
		if(S != NULL)
		{
				free(S->Array);
				free(S);
		}
}


void Push(int X, Stack S)
{
		if(isFull(S))
		{
				printf("Stack is full!");
				exit(EXIT_FAILURE);
		}
		else
				S->Array[++S->TopofStack] = X;
}

void Pop(Stack S)
{
		if(isEmpty(S))
		{
				printf("Stack is Empty!");
				exit(EXIT_FAILURE);
		}
		else
				S->TopofStack--;
}


int main()
{
		Stack S;
		int MaxElements = 20;
		S = CreateStack(MaxElements);

		return 0;
}
