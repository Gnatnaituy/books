#include <stdio.h>

// escape
void escape(char s[], char t[]){
    int i, j;

    for(i = j = 0; t[i] != '\0'; i++){
        switch(t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

// unescape
void unescape(char s[], char t[]){
    int i, j;

    for(i = j = 0; t[i] != '\0'; i++){
        if(t[i] != '\\')
            s[j++] = t[i];
        else
            switch(t[++i]){
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
    }
    s[j] = '\0';
}

// unescape version 2
void unescape_v2(char s[], char t[]){
    int i, j;

    for(i = j = 0;  t[i] != '\0'; i++){
        switch(t[i]){
            case '\\':
                switch(t[++i]){
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}


int main(void){
    char string0[] = "I'm\tyour\n\tfather.";
    char string1[] = "I'm your father.";
    char string2[] = "";
    char string3[] = "";
    char string4[] = "";

    escape(string2, string1);
    printf("%s\n", string2);

    unescape(string3, string0);
    printf("%s\n", string3);

    unescape_v2(string4, string0);
    printf("%s\n", string4);

    return 0;
}