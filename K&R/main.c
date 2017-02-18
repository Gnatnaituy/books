#include <stdio.h>

int main() {
    // 练习1-6 1-7
    /* int c = getchar();
    printf("getchar() != EOF:%d\nEOF:%d", (c != EOF), EOF); */

    // 练习 1-8
    int c;
    int nSpaces = 0, nTabs = 0, nEnters = 0;

    while ((c = getchar()) != EOF)
        if(c == '\n')
            ++nEnters;
        else if(c == '\t')
            ++nTabs;
        else if(c == ' ')
            ++nSpaces;
    printf("Spaces: %d\nTabs: %d\nEnters: %d\n", nSpaces, nTabs, nEnters);

    return 0;
}