#include <stdio.h>
#include <stdlib.h>

#define TRUE        1
#define FASLE       0
#define ERROR       0
#define OK          1
#define INFEASIBLE  -1
#define OVERFOW     -2
#define MAXSIZE     20

typedef char TElemType;
typedef int  Status;


typedef struct BiTNode {
    TElemType data;
    struct BiTNode * lchild, * rchild;
} BiTNode, * BiTree;

typedef struct {
    BiTree * elem;
    int top;
    int size;
} LStack;

typedef struct {
    BiTree * base;
    int front;
    int rear;
    int maxSize;
} LQueue;


Status CreateBiTree(BiTree &T) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        T = NULL;
    } else {
        if (!(T = (BiTNode *) malloc(MAXSIZE * sizeof(BiTNode)))) {
            exit(OVERFOW);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }

    return OK;
}

Status InitStack_LS(LStack &S) {
    S.elem = (BiTree *) malloc(MAXSIZE * sizeof(BiTree));
    if (S.elem == NULL) return OVERFOW;
    S.top = 0;
    S.size = MAXSIZE;

    return OK;
}

int StackEmpty_LS(LStack &S) {
    return S.top == 0;
}

Status Push_LS(LStack &S, BiTree e) {
    S.elem[S.top] = e;
    S.top++;

    return OK;
}

void Pop_LS(LStack &S, BiTree &e) {
    S.top--;
    e = S.elem[S.top];
}

Status PrintCharElement(TElemType e) {
    printf("%c  ", e);

    return OK;
}

BiTNode * GoFarLeft(BiTree T, LStack &S) {
    if (T == NULL) {
        return NULL;
    }
    while (T->lchild != NULL) {
        Push_LS(S, T);
        T = T->lchild;
    }

    return T;
}

Status InitQueue_L(LQueue &Q) {
    Q.base = (BiTree *) malloc(MAXSIZE * sizeof(BiTree));
    if (Q.base == NULL) {
        return OVERFOW;
    }
    Q.maxSize = MAXSIZE;
    Q.rear = 0;
    Q.front = 0;

    return OK;
}

Status DeQueue_L(LQueue &Q, BiTree &e) {
    if (Q.front == Q.rear) {
        return FASLE;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % Q.maxSize;

    return TRUE;
}

Status EnQueue_L(LQueue &Q, BiTree e) {
    if ((Q.rear + 1) % Q.maxSize == Q.front) {
        return FASLE;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxSize;

    return TRUE;
}

void InorderTraverse_I(BiTree T, Status (* visit) (TElemType e)) {
    LStack S;
    InitStack_LS(S);
    BiTree p;
    p = GoFarLeft(T, S);
    while (p != NULL) {
        visit(p->data);
        if (p->rchild != NULL) {
            p = GoFarLeft(p->rchild, S);
        } else if (StackEmpty_LS(S) != TRUE) {
            Pop_LS(S, p);
        } else {
            p = NULL;
        }
    }
}

void LevelOrderTraverse(BiTree &T, Status (* visit) (TElemType e)) {
    if (T != NULL) {
        LQueue Q;
        InitQueue_L(Q);
        BiTree p = T;
        visit(p->data);
        EnQueue_L(Q, p);
        while (DeQueue_L(Q, p) == OK) {
            if (p->lchild != NULL) {
                visit(p->lchild->data);
                EnQueue_L(Q, p->lchild);
            }
            if (p->rchild != NULL) {
                visit(p->rchild->data);
                EnQueue_L(Q, p->rchild);
            }
        }
    }
}

int main() {
    BiTree T = NULL;
    int s = 0, m = 0, n = 0, d = 0;
    printf("请按先序次序输入各结点的值，以#表示空树: \n");
    CreateBiTree(T);
    printf("二叉树已建立完毕！\n");
    printf("中序遍历: ");
    InorderTraverse_I(T, PrintCharElement);
    printf("层次遍历: ");
    LevelOrderTraverse(T, PrintCharElement);

    return 0;
}



