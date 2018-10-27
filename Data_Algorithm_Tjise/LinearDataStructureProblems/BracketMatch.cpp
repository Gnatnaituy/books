//
// Created by Hasaker on 2018/10/20.
//

#include "../LinearDataStructure/LinearDataStructure.h"


Status bracketMatch(char * expression, int n) {
    int i = 0;
    CharElementType e;
    SqStack_Char S;
    InitStack_Char(S, n, 5);

    while (i < n) {
        switch (expression[i]) {
            case '(':
            case '[':
                Push_Char(S, expression[i]);
                i++;
                break;
            case ')':
            case ']':
                if (StackEmpty_Char(S) == TRUE) {
                    return ERROR;
                } else {
                    GetTop_Char(S, e);
                    if ((expression[i] == ')' && e == '(') || (expression[i] == ']' && e == '[')) {
                        Pop_Char(S, e);
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

    if (StackEmpty_Char(S) == TRUE) {
        printf("This is a right bracket sequence.");
        return OK;
    } else {
        printf("This is a wrong bracket sequence.");
        return ERROR;
    }
}