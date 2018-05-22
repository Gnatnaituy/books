#ifndef Stack_H
#define Stack_H

typedef struct Node
{
	int		Data;
	struct  Node   *Next;	
} *Stack;

int isEmpty(Stack S);
Stack CreateStack( void );
void DisposeStack( Stack S);
void MakeEmpty(Stack S);
void Push(int Data, Stack S);
int Top(Stack S);
void Pop(Stack S);

#endif

