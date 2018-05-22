#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];

int main(){
    int len;

    while(printf("Input  : ") && (len = mygetline()) > 0)
    {
        printf("Output : %s\n", line);

        for(int i = 0; i < len; i++) // 重置line
            line[i] = '\0';
    }

    return 0;
}


int mygetline(void)
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c =='\n')
    {
        line[i] = c;
        ++i; //　长度从一开始计数，而数组下标从零开始
    }

    return i;
}
