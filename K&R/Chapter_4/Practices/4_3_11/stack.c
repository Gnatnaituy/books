#include <stdio.h>

#define MAXVAL 100      // the max depth of stack


int sp = 0;     //position of the next free stack
double val[MAXVAL];     // value stack

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push.\n");
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: empty stack.\n");
        return 0.0;
    }
}
