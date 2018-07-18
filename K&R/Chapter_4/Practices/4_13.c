//
// Created by hasaker on 11/4/17.
//

#include <string.h>


// reverse: reverse string s in place
void reverse(char s[])
{
    void reverser(char s[], int i, int len);

    reverser(s, 0, strlen(s));
}


// reverser: reverse string s in place recursively
void reverser(char s[], int i, int len)
{
    int c, j;

    j = len - (i + 1);
    if(i < j)
    {
        c = s[j];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}