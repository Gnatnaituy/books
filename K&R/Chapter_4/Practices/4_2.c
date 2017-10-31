//
// Created by hasaker on 10/24/17.
//

#include <ctype.h>

//把字符串s转化为相应的双精度浮点数,并支持科学计数法
double atof_with_e(char s[])
{
    double value, power;
    int i, sign, sign_e, value_e;

    //跳过空白符
    for(i = 0; isspace(s[i]); i++)
        ;
    //保存正负数消息
    sign = (s[i] == '-') ? -1 : 1;
    //跳过符号
    if(s[i] == '+' || s[i] == '-')
        i++;

    //整数部分
    for(value = 0.0; isdigit(s[i]); i++)
        value = 10.0 * value + (s[i] - '0');
        //字符-'0'变成对应的整数
    if(s[i] == '.')
        i++;
    //小数部分
    for(power = 1.0; isdigit(s[i]); i++)
    {
        value = 10.0 * value + (s[i] - '0');
        power *= 10.0; //power为小数点的位数
    }

    //科学计数法部分
    if(s[i] == 'e' || s[i] == 'E')
    {
        i++;
        sign_e = (s[i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(value_e = 0;isdigit(s[i]); i++)
            value_e = 10 * value_e + (s[i] - '0');
        for(;value_e > 0; value_e--)
        {
            if(sign_e == -1)
                power *= 10.0;
            else
                power /= 10.0;
        }
    }


    return sign * value / power;

}