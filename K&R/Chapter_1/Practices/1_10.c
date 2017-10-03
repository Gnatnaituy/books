#include <stdio.h>

int main(){
    int c;

    printf("Input : ");
    c = getchar();
    printf("\nOutput: ");

    do{ 
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }
        else if(c == '\b'){
            putchar('\\');
            putchar('b');
        }
        else if(c == '\\'){
            putchar('\\');
        }
        else
            putchar(c);
    }
    while((c = getchar()) != EOF);

    printf("\n");
}