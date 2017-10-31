//
// Created by hasaker on 10/24/17.
//

#include <stdio.h>
#include <ctype.h>

//将行保存到s中,并返回该行的长度
int my_getline(char s[], int lim)
{
    int c, i=0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}


// str_index函数:返回t在s中的位置,若未找到返回-1
int str_index(char s[], char t[])
{
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}


//把字符串s转化为相应的双精度浮点数
double atof(char s[])
{
    double value, power;
    int i, sign;

    for(i = 0; isspace(s[i]); i++)
        ; //跳过空白符
    sign = (s[i] == '-') ? -1 : 1; //保存正负数消息
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(value = 0.0; isdigit(s[i]); i++)
        value = 10.0 * value + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++)
    {
        value = 10.0 * value + (s[i] - '0');
        power *= 10.0;
    }

    return sign * value / power;

}