#include <stdio.h>

int main()
{
    int c;
    int Alphabet[26];

    for(int i = 0; i < 26; i++)
        Alphabet[i] = 0;

    while((c = getchar()) != EOF)
    {
        if(c != ' ' && c != '\n' && c != '\t' && c >= 97 && c <= 122)
            ++Alphabet[c-97];
    }
    
    for(int i=0; i<26; i++)
    {
        if(Alphabet[i] != 0){
            printf("\n%c: ", i+97);
            while(Alphabet[i] != 0)
            {
                printf("X");
                --Alphabet[i];
            }
        }
    }
    printf("\n");
}