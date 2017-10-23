#include <stdio.h>
#include "Chapter_3/Practices/3_5.c"

int main(void){
    char s1[] = "";
    itob(1007, s1, 16);
    printf("%s", s1);

    return 0;
}