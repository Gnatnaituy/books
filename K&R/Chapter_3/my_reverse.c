//
// Created by hasaker on 10/23/17.
//
#include <string.h>

void my_reverse(char s[])
{
    size_t i, j, len = strlen(s);
    char c;

    for(i = 0, j = len-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}