#include <stdio.h>

int main(){
    int c = getchar();
    printf("getchar() != EOF:%d\nEOF:%d", (c != EOF), EOF);

    return 0;
}