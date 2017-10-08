#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j;

    for(i = 0; s1[i] != '\0'; i++)
    {
        for(j = 0; s2[j] != '\0'; j++)
        {
            if(s2[j] == s1[i])
            {
                return i + 1;
            }
        }
    }
    return 0;
}

int main()
{
    int a = any("qwertyuiop", "asdfy");
    printf("%d\n", a);

    return 0;
}