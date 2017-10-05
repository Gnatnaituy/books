#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];
char longer_than_80[MAXLINE];

int main(){
    int len;

    while(printf("Input  : ") && (len = mygetline()) > 0)
    {
        if(len >= 80){
            copy();
            printf("Output : %s\n", longer_than_80);
        }
        else
            printf("Shorter than 80.\n");

        
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

int copy()
{
    int i;
    extern char line[], longer_than_80[];

    i = 0;
    while((longer_than_80[i] = line[i]) != '\0')
        ++i;

    return 0;
}