#include <stdlib.h>
#include <stdio.h>

int main(){
    enum loop {NO, YES};
    enum look okloop = YES;

    i = 0;
    while(okloop == YES){
        if(i >= lim-1)      // outside of valid range
            okloop = NO;
        else if((c = getchar()) == '\n')
            okloop = NO;
        else if(c == EOF)   // end of file?
            okloop = NO;
        else{
            s[i] = c;
            ++i;
        }
    }
}