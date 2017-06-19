#include <stdio.h>


void mystrcpy(char *s, char *t){
    while(*s++ = *t++)
        ;
}


void swap(int *px, int *py){
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}


int main(){
    char *s1;
    char *s2 = "You are my son";
    int *d1;
    int d = 3;
    d1 = &d;
    int *d2 = 5;

    printf("%d\n", *d1);
    // mystrcpy(s1, s2);
    // swap(d1, d2);

    // printf("%s\n%s\n", s1, s2);
    // printf("%d\n%d\n", d1, d2);


    return 0;
}
