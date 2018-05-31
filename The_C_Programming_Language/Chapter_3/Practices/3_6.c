//修改itoa函数,使其接受三个参数,第三个参数为最小字段宽度
//必要时在左边填充一定的空格

#include "../my_reverse.c"
#define abs(x) ((x) < 0 ? -(x) : (x))


void itoa(int n, char s[], int width)
{
    int sign = n;
    int i = 0;

    do
        s[i++] = abs(n % 10) + '0'; //整数+'0'成为对应该数字的字符
    while((n /= 10) != 0);

    if(sign < 0)
        s[i++] = '-'; //录入n的符号

    if(i < width)
    {
        for(;i < width; i++)
            s[i] = ' ';
    }

    my_reverse(s);

}
