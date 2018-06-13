//
// Created by hasaker on 10/24/17.
//


//返回字符串t在s中最右边出现的位置,若没有则返回-1
int str_rightest_index(char s[], char t[])
{
    int i, j, k, position;

    position = -1;
    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && t[k] == s[j]; k++, j++)
            ;
        if(k > 0 && t[k] == '\0')
            position = i; //将结果保存而不是直接返回结果并结束函数
    }

    return  position;
}
