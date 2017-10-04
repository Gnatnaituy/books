#include <stdio.h>

int main()
{
    int c, word_lenth, state;
    int word_lenthes[10];

    // 初始化变量
    word_lenth = 0;
    for(int x=0; x < 10; x++)
        word_lenthes[x] = 0;

    // 将单词长度录入数组
    while((c = getchar()) != EOF)
    {
        if(c != ' ' && c != '\n' && c != '\t')
            ++word_lenth;
        else
        {
            ++word_lenthes[word_lenth];
            word_lenth = 0;
        }
    }
    
    // 打印直方图
    for(int i=0; i<10; i++)
    {
        if(word_lenthes[i] != 0){
            printf("\n%d: ", i);
            while(word_lenthes[i] != 0)
            {
                printf("X");
                --word_lenthes[i];
            }
        }
    }
    printf("\n");
}