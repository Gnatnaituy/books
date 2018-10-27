//
// Created by Hasaker on 2018/10/26.
//

#include "../LinearDataStructure/LinearDataStructure.h"

void manipulateSequenceQueue() {
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