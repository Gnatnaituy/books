#include <stdlib.h>
#include <stdio.h>

#define limit 100

int main(){
    char c;
    char s[limit];
    enum loop {NO, YES};
    enum loop okloop = YES;

    int i = 0;
    while(okloop == YES){
        if(i >= limit-1)      // outside of valid range
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