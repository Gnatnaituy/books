#include <stdio.h>

void mystrcpy(char *s, char *t){
    while(*s++ = *t++)
        ;
}


int main(){
    char *s1;
    char *s2 = "You are my son";

    mystrcpy(s1, s2);

    return 0;
}
