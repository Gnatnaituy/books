#include "../my_reverse.c"

//将整数n转换位以b为底的数,并将转换结果以字符的形式保存在字符串s中
void itob(int n, char s[], int b)
{
    int i, j, sign;

    if((sign = n) < 0)  //record sign
        n = -n;     //make n positive
    i = 0;
    do  //generate digits in reverse order
    {
        j = n % b;  //get next digit
        s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
    }while((n /= b) > 0);   // delete it
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    my_reverse(s);
}