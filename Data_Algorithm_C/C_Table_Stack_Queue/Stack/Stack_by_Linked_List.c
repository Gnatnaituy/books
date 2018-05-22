#include "Stack_by_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>


int isEmpty(Stack S)
{
		return S->Next == NULL;
}

Stack CreateStack(void)
{
		Stack S;

		S = (Stack)malloc(sizeof(Stack));
		if(S == NULL)
		{
				printf("Failed to malloc.");
				exit(EXIT_FAILURE);
		}
		S->Next == NULL;
		MakeEmpty(S);
		printf("CreateStack Succuss!");
}

void MakeEmpty(Stack S)
{
		if(S == NULL)
		{
				printf("Empty Stack!");
				exit(EXIT_FAILURE);
		}
		else
				while( !isEmpty(S) )
						Pop(S);
		printf("MakeEmpty Succuss!");
}

void Push(int Data, Stack S)
{
		Stack TmpCell;

		TmpCell = malloc( sizeof( Stack ) );
		if( TmpCell == NULL)
		{
				printf("Failed to malloc.");
				exit(EXIT_FAILURE);
		}
		else
		{
				TmpCell->Data = Data;
				TmpCell->Next = S->Next;
				S->Next = TmpCell;
		}
		printf("Push Succuss!");
}

void Pop( Stack S)
{
		Stack FirstCell;

		if(isEmpty(S))
		{
				printf("Empty Stack!");
				exit(EXIT_FAILURE);
		}
		else
		{
				FirstCell = S->Next;
				S->Next = S->Next->Next;
				free(FirstCell);
		}
		printf("Pop Succuss!");
}

int Top(Stack S)
{
		if(isEmpty(S))
		{
				printf("Empty Stack!");
				exit(EXIT_FAILURE);
		}
		else
				return S->Next->Data;
		return 0;
}

void PrintStock( Stack S)
{
		if( isEmpty( S ))
		{
				printf("Empty Stock!");
				exit(EXIT_FAILURE);
		}
		else
		{
				while(S->Next != NULL)
				{
						printf("%d", S->Data);
						S = S->Next;
				}
		}
		printf("PrintStock Succuss!");
}

int main()
{
		Stack S;
		S = CreateStack();
		int i;
		for(i = 0; i < 20; i++)
		{
				Push(i, S);
				PrintStock(S);
		}

		return 0;
}

