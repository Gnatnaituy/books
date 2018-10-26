//
// Created by Hasaker on 2018/10/19.
//

#include <stdio.h>
#include "../LinearDataStructure/LinearDataStructure.h"

void conversion()
{
    SqStack stack;
    ElementType element;
    int decimal_number, number_base;

    printf("输入一个十进制数: ");
    scanf("%d", &decimal_number);
    printf("想要转换的进制: ");
    scanf("%d", &number_base);

    InitStack(stack);
    while (decimal_number) {
        Push(stack, decimal_number % number_base);
        decimal_number /= number_base;
    }

    printf("转换后的数: ");
    while (StackEmpty(stack) == FALSE) {
        Pop(stack, element);
        printf("%d", element);
    }
    printf("\n");

}
