#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];

int main(){
    int len;

    while(printf("Input  : ") && (len = mygetline()-1) > 0)
    {
        if(line[len] == ' ' || line[len] == '\t')
            --len;
        printf("Output : %sLength:%d\n", line);

        for(int i = 0; i < len; i++)
            line[i] = '\0';
    }

    return 0;
}


int mygetline()
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c =='\n')
    {
        line[i] = c;
        ++i;
    }

    return i;
}
