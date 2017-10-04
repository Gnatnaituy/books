#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

void world_count(){
    int c, nlines, nwords, nchars, state;

    state = OUT_WORD;
    nlines = 1;
    nwords = nchars = 0;
    while((c = getchar()) != EOF){
        ++nchars;
        if(c == '\n')
            ++nlines;
        if(c == ' ' || c == '\n' || c =='\t')
            state = OUT_WORD;
        else if(state == OUT_WORD){
            state = IN_WORD;
            ++nwords;
        }
    }
    printf("\nwords:%d\nlines:%d\nchars:%d\n", nwords, nlines, nchars);
}

int main(){
    world_count();
}