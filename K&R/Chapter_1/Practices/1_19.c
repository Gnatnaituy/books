#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];

int main(){
    reverse();

    return 0;
}


int mygetline()
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if(c =='\n')
        line[i] = c;

    return i+1; // 数组从０开始
}

void reverse()
{
    int len;
    char reversed_line[MAXLINE];

    while(printf("Input    : ") && (len = mygetline()) > 0)
    {
        // len = line最后一个下标+1 && line[len-1]='\n' 所以 i <= len-2
        for(int i = 0; i <= len-2; i++)
        {
            reversed_line[len-2 - i] = line[i];
        }
        reversed_line[len-1] = '\0'; // 在reversed_line末尾加上'\0'表示行结束，以避免打印出现乱码
        printf("Reversed : %s\n", reversed_line);

        for(int i = 0; i <= len-1; i++)
        {
            line[i] = '\0';
            reversed_line[i] = '\0';
        }
    }
}