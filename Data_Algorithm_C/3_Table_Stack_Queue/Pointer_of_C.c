#include <stdlib.h>
#include <stdio.h>

int main(){
    int a = 100;
    char str[20] = "c.biancheng.net";
    // 数据在内存中的地址也称为指针，如果一个变量存储了一份数据的指针，我们就称它为指针变量。
    int* b = &a; // int* 表示声明一个指针变量，此时指针变量b的值等于a的地址&a
    printf("a=%d, b=%#X, *b=%d\n", a, b, *b); // %#X表示以十六进制形式输出，并附带前缀0X

    return 0;
}
