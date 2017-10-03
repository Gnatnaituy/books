#include <stdio.h>

int main(){
    int c;
    int count_spaces = 0;

    while((c=getchar()) != EOF){
        if(c == ' '){
            if(count_spaces == 0){
                count_spaces = 1;
                putchar(c);
            }
        }
        if(c != ' '){
            count_spaces = 0;
            putchar(c);
        }
    }
    printf("\n");
}