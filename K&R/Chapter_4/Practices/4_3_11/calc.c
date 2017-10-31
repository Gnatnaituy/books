#include <stdio.h>
#include <math.h>
#include "calculator.h"
#include "../../chapter_4.c"


#define MAXOP   100       //max size of operand or operator

int calc()
{
    int type;
    double operand2;
    char s[MAXOP];

    while((type = get_op(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                operand2 = pop();
                if(operand2 != 0.0)
                    push(pop() / operand2);
                else
                    printf("Error: zero divisor\n");
                break;
            case '%':
                operand2 = pop();
                if(operand2 != 0.0)
                    push(fmod(pop(), operand2));
                else
                    printf("Error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

