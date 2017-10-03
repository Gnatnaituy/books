#include <stdio.h>

int main(){
    int c = getchar();
    printf("getchar() != EOF:%d\nEOF:%d\n", (c != EOF), EOF);

    return 0;
}