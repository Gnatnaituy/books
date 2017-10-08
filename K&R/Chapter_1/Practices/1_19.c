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

    return i+1; // Array indicator start from 0 
}

void reverse()
{
    int len;
    char reversed_line[MAXLINE];

    while(printf("Input    : ") && (len = mygetline()) > 0)
    {
        // len = line's lasr indicator +1 && line[len-1]='\n' so i <= len-2
        for(int i = 0; i <= len-2; i++)
        {
            reversed_line[len-2 - i] = line[i];
        }
        reversed_line[len-1] = '\0'; // represent the end of reversed_line
        printf("Reversed : %s\n", reversed_line);

        for(int i = 0; i <= len-1; i++)
        {
            line[i] = '\0';
            reversed_line[i] = '\0';
        }
    }
}