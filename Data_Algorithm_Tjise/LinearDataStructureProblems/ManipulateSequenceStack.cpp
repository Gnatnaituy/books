//
// Created by Hasaker on 2018/10/26.
//

#include "../LinearDataStructure/LinearDataStructure.h"

void manipulateSequenceStack() {
    SqStack s;
    ElementType a;
    int choice;

    printf("第一次使用必须初始化!\n");
    do {
        printf("\n-----菜单-----\n");
        printf("1 初始化顺序栈\n");
        printf("2 插入一个元素\n");
        printf("3 删除栈顶元素\n");
        printf("4 结束程序运行\n");
        printf("-------------\n");
        printf("请输入你的选择: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                InitStack(s);
                OutStack(s);
                break;
            case 2:
                printf("请输入要插入的元素数据: ");
                scanf("%d", &a);
                Push(s, a);
                printf("入栈之后的栈:\n");
                OutStack(s);
                printf("\n");
                break;
            case 3:
                Pop(s, a);
                printf("栈顶元素%d出栈之后的栈:\n", a);
                OutStack(s);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    } while (choice <= 4);
}