//
// Created by Hasaker on 2018/11/2.
//

#include "../LinearDataStructure/LinearDataStructure.h"

void manipulateSequenceList() {
    SqList L;
    int cord,i; ElementType a;
    printf("第一次使用必须初始化！\n");
    do{
        printf("      主菜单\n");
        printf("  1 初始化顺序表\n ");
        printf(" 2 插入一个元素\n ");
        printf(" 3 删除一个元素\n ");
        printf(" 4 结束程序运行\n ");
        printf(" --------------\n");
        printf("请输入您的选择( 1, 2, 3, 4)");
        scanf("%d",&cord);
        switch(cord){
            case 1:
                InitList(L);
                OutList(L);
                break;
            case 2:
                printf("请输入要插入的插入位置和数据元素:（如：3 20）");
                scanf("%d%d",&i,&a);
                ListInsert(L,i,a);
                printf("\n插入%d之后的顺序表: ",a);
                OutList(L);
                printf("\n\n");
                break;
            case 3:
                printf("请输入要删除的数据元素的位置:（如： 3）");
                scanf("%d",&i);
                ListDelete(L,i,a);
                printf("\n删除第%d个位置的元素之后的顺序表: ",i);
                OutList(L);
                printf("\n\n");
                break;
            case 4:
                exit(0);
            default:break;
        }
    }while (cord<=4);
}
