#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];      //use as the buff space of unget_ch
static int bufp = 0;       // the next free space in buff

int get_ch(void)        //get a character(maybe one unget_ch()ed)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void unget_ch(int c)    //push the character to the input stream
{
    if(bufp >= BUFSIZE)
        printf("unget_ch: too many characters\n");
    else
        buf[bufp++] = c;
}