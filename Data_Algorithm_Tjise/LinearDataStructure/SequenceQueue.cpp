//
// Created by Hasaker on 2018/10/26.
//

#include "LinearDataStructure.h"
#include <cstdlib>
#include <cstdio>


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

void test_queue() {
    SqQueue Q;
    int cord;
    ElementType a;
    printf("You must initialing the queue before you using it !");
    do {
        printf("\n主菜单\n");
        printf(" 1 初始化循环队列 \n");
        printf(" 2 进队一个元素 \n");
        printf(" 3 出队一个元素 \n");
        printf(" 4 结束程序运行 ");
        printf("\n--------------------------\n");
        printf("请输入您的选择( 1, 2, 3, 4)");
        scanf("%d",&cord);
        printf("\n");
        switch(cord){
            case 1:
                InitQueue(Q); //调用初始化算法;
                OutQueue(Q);
                break;
            case 2:
                printf("请输入要插入的数据元素：a=");
                scanf("%d",&a);
                EnQueue (Q, a); //调用进队算法;
                printf("%d 进队之后的队列：", a);
                OutQueue(Q);
                break;
            case 3:
                DeQueue (Q, a); //调用出队算法;
                printf("队头元素 %d 出队之后的队列：", a);
                OutQueue(Q);
                break;
            case 4:
                exit(0);
            default:break;
        }
    } while (cord<=4);
}
