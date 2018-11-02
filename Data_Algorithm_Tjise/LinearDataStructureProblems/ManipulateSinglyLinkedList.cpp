//
// Created by Hasaker on 2018/11/2.
//

#include "../LinearDataStructure/LinearDataStructure.h"

void manipulateSinglyLinkedList() {

    SinglyLinkedList SL;
    int cord, i;
    ElementType a;

    printf("\n第一次使用请先创建一个单链表！\n");
    do {
        printf("      主菜单\n");
        printf("  1 初始化单链表\n ");
        printf(" 2 插入一个元素\n ");
        printf(" 3 删除一个元素\n ");
        printf(" 4 结束程序运行\n ");
        printf(" --------------\n");
        printf("请输入您的选择( 1, 2, 3, 4)");
        scanf("%d", &cord);
        switch(cord) {
            case 1:
                CreateList_SL(SL);
                OutList_SL(SL);
                break;
            case 2:
                printf("\n请输入要插入的插入位置和数据元素（如：3 20）");
                scanf("%d%d", &i, &a);
                if (ListInsert_SL(SL, i, a)) {
                    printf("插入元素成功!\n插入%d元素之后的链表: ", a);
                    OutList_SL(SL);
                    printf("\n");
                } else printf("插入元素失败!\n");
                break;
            case 3:
                printf("请输入要删除的数据元素的位置（如：3）");
                scanf("%d", &i);
                if (ListDelete_SL(SL, i, a)) {
                    printf("删除元素成功\n被删除的元素是: %d\n", a);
                    printf("删除第%d个位置的元素之后的链表: ", i);
                    OutList_SL(SL);
                    printf("\n");
                } else printf("删除位置错误，请重新执行!\n");
                break;
            case 4:
                exit(0);
            default:break;
        }
    } while (cord<=4);
}
