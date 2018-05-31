#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

void main(){
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
            printf("\n"); // change line if state == OUT_WORD
        }
        printf("%c", c);
    }
    printf("\nwords:%d lines:%d chars:%d\n", nwords, nlines, nchars);
}
