#include <stdio.h>

int main(){
    int c;
    int count_spaces=0, count_tabs=0, count_enters=0;

    while((c=getchar()) != EOF){
        if(c == ' ')
            ++count_spaces;
        else if(c == '\t')
            ++count_tabs;
        else if(c == '\n')
            ++count_enters;
    }

    printf("\nSpaces:%d\nTabs:%d\nEnters:%d\n", count_spaces, count_tabs, count_enters);
}
