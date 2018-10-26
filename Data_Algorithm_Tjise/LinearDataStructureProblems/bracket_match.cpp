//
// Created by Hasaker on 2018/10/20.
//

#include <cstdlib>
#include <cstdio>
#include "../LinearDataStructure/LinearDataStructure.h"


Status bracket_matching(char * expression, int n) {
    int i = 0;
    CharElementType e;
    SqStack_Sq S;
    InitStack_Sq(S, n, 5);

    while (i < n) {
        switch (expression[i]) {
            case '(':
            case '[':
                Push_Sq(S, expression[i]);
                i++;
                break;
            case ')':
            case ']':
                if (StackEmpty_Sq(S) == TRUE) {
                    return ERROR;
                } else {
                    GetTop_Sq(S, e);
                    if ((expression[i] == ')' && e == '(') || (expression[i] == ']' && e == '[')) {
                        Pop_Sq(S, e);
                        i++;
                    } else {
                        return ERROR;
                    }
                }
                break;
            default:
                i++;
                break;
        }
    }

    if (StackEmpty_Sq(S) == TRUE) {
        printf("This is a right bracket sequence.");
        return OK;
    } else {
        printf("This is a wrong bracket sequence.");
        return ERROR;
    }
}