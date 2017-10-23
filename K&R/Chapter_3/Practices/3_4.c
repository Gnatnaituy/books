#include "../my_reverse.c"
#define abs(x) ((x) < 0 ? -(x) : (x))


// itoa:将字符n转换为字符串并保存到s中
void itoa(int n, char s[])
{
    int sign = n;
    int i = 0;

    do
        s[i++] = abs(n % 10) + '0'; //整数+'0'成为对应该数字的字符
    while((n /= 10) != 0);

    if(sign < 0)
        s[i++] = '-'; //录入n的符号
    s[i] = '\0';

    my_reverse(s);
}
