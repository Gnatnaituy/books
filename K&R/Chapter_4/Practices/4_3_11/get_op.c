#include <stdio.h>
#include <ctype.h>
#include "calculator.h"


int get_op(char s[])
{
    int c, i;

    while((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;

    if(!isdigit(c) && c != '.' && c != '-')
        return c;   //not a number

    if(c == '-')
    {
        if(isdigit(c = get_ch()) || c == '.')
            s[++i] = c;     //negative number
        else
        {
            if(c != EOF)
                unget_ch(c);
            return '-';     //minus sign
        }
    }

    if(isdigit(c))      //collect integer part
        while(isdigit(s[++i] = c = get_ch()))
            ;
    if(c == '.')        //collect fraction part
        while(isdigit(s[++i] = c = get_ch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        unget_ch(c);

    return NUMBER;
}