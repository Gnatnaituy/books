#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BSIZE 250


int alreadyInList(FILE* list, char name) {
    char lbuf[BSIZE];
    // go to the beginning of the list
    fseek(list, 0, SEEK_SET);
    // read each line in the list
    while (fgets(lbuf, BSIZE, list)) {
        // strip off the new line
        char * newline = strchr(lbuf, '\n');
        if (newline != 0)
            *newline = '\0';
        if (strcmp(lbuf, name) == 0)
            return 1;
    }
    return 0;
}


int main() {
    char buf[BSIZE];
    FILE* list = fopen("emlist.txt", "a+t");
    if(list == 0) {
        perror("Could not open emlist.txt");
        exit(1);
    }
    while (1) {
        gets(buf);
        if(alreadyInList(list, buf)) {
            printf("Already in list: %s", buf);
            fflush(stdout);
        }
        else {
            fseek(list, 0, SEEK_END);
            fprintf(list, "%s\n", buf);
            fflush(list);
            printf("%s added to list", buf);
            fflush(stdout);
        }
    }
}