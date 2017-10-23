#include <stdio.h>
#include "Chapter_3/Practices/3_6.c"

int main(void)
{
    char s2[100] = "";
    itoa(12345667, s2, 8);
    printf("%s\n", s2);

    return 0;
}

//3_2.c
//int main(void)
//{
//    char string0[] = "I'm\tyour\n\tfather.";
//    char string1[] = "I'm your father.";
//    char string2[] = "";
//    char string3[] = "";
//    char string4[] = "";
//
//    escape(string2, string1);
//    printf("%s\n", string2);
//
//    unescape(string3, string0);
//    printf("%s\n", string3);
//
//    unescape_v2(string4, string0);
//    printf("%s\n", string4);
//
//    return 0;
//}