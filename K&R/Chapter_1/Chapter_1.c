#include <stdio.h>

#define INWORD      1
#define OUTWORD     0
#define MAXLENGTH 100


// 练习 1-6 1-7 关于EOF
void oneSixSeven(){
    int c = getchar();
    printf("getchar() != EOF:%d\nEOF:%d", (c != EOF), EOF);
}


// 练习 1-8 统计制表符,空格,换行符的个数
void oneEight(){
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
}


// 练习 1-9 将输出中多个空格换为一个空格
void oneNight(){
    int c;
    int space = 0;

    while((c = getchar()) != EOF){
        if(c == ' '){
            if(space == 0){
                space = 1;
                putchar(c);
            }
        }
        if(c != ' '){
            space = 0;
            putchar(c);
        }
    }
}


// 练习 1-10 将转义字符换为字符
void oneTen(){
    int c, c1='\\', c2;

    while((c = getchar()) != EOF)
        if(c == '\n'){
            c2 = 'n';
            putchar(c1);
            putchar(c2);
        }else if(c == '\t'){
            c2 = 't';
            putchar(c1);
            putchar(c2);
        }else if(c == ' '){
            c2 = 'b';
            putchar(c1);
            putchar(c2);
        }else
            putchar(c);
}


// 单词计数
void wordCounter(){
    int c, numberLine, numberWord, numberCounter, state;

    state = OUTWORD;
    numberLine = numberWord = numberCounter = 0;
    while((c = getchar()) != '#'){
        ++numberCounter;
        if(c == '\n')
            ++numberLine;
        if(c == '\b' || c == '\n' || c == '\t')
            state = OUTWORD;
        else if(state == OUTWORD){
            state = INWORD;
            ++numberWord;
        }
    }
    printf("Lines:%d\nWords:%d\nCounter:%d\n", numberLine, numberWord, numberCounter);
}


// 练习 1-12 把输入的单词每行一个打印出来
void oneEleven(){
    int c;

    while((c = getchar()) != '#'){
        if(c == '\n' || c == ' ' || c == '\t')
            printf("\n");
        else
            putchar(c);
    }
}


// 统计字数, 空白符和其他字符的个数 用数组
void arrayCounter(){
    int c, i, nWhites, nOthers;
    int nDigit[10];

    nWhites = nOthers = 0;
    for(i = 0; i < 10; i++)
        nDigit[i] = 0;
    while((c = getchar()) != '#'){
        if(c >= '0' && c <= '9')
            ++nDigit[c-'0'];
        else if(c == ' ' || c == '\t' || c == '\n')
            ++nWhites;
        else
            ++nOthers;
    }
    printf("digits=");
    for(i = 0; i < 9; i++)
        printf("%d", nDigit[i]);
    printf(", whitespace=%d, others=%d\n", nWhites, nOthers);
}


// 练习 1-13 打印单词长度频度的直方图
void oneThirteen(){
    int c, i, theLength=0;
    int wordLength[10];

    for(i = 0; i < 10; i++)
        wordLength[i] = 0;
    while((c = getchar()) != '#'){
        if(c != ' ' && c != '\n' && c != '\t')
            ++theLength;
        else{
            ++wordLength[theLength];
            theLength = 0;
        }
    }
    // 水平直方图
    for(i = 0; i < 10; i++){
        if(wordLength[i] != 0){
            printf("%d characters: ", i);
            while(wordLength[i] != 0){
                printf("\\");
                --wordLength[i];
            }
            printf("\n");
        }
    }
    // 垂直直方图

}


// 练习 1-14 打印输入中不同字符出现频度的直方图
void oneFourteen(){
    int c, i;
    int cTimes[26];

    for(i = 0; i < 26; i++)
        cTimes[i] = 0;
    while((c = getchar()) != '#'){
        if(c != '\n' && c != ' ' && c != '\t' && c >= 97 && c <= 122)
            ++cTimes[c-97];
    }
    for(i = 0; i < 26; i++){
        if(cTimes[i] != 0){
            printf("%c:", i+97);
            while(cTimes[i] != 0){
                printf("/");
                --cTimes[i];
            }
            printf("\n");
        }
    }
}


// 练习 1-15 温湿度转换
void fahrtoCelsius(){
    int Fahr, Celsius;
    int lower=0, upper=300, step=10;

    Fahr = lower;
    printf("F\tC\n");
    while(Fahr <= upper){
        Celsius = 5 * (Fahr - 32) / 9;
        printf("%d\t%d\n", Fahr, Celsius);
        Fahr = Fahr + step;
    }
}


// 读入一组文本行,打印出其中的最长一行
int getLine(char s[]){
    // 将一行文本读入到 s 中,病返回其长度
    int c, i;
    for(i = 0; i < MAXLENGTH && ((c = getchar()) != '#') && c != '\n'; i++)
            s[i] = c;

    return i;
}

void copy(char to[], char from[]){
    int i = 0;

    while((to[i] = from[i]) != '\0')
        ++i;
}

void printLongest(){
    int len = 0, max = 0;  // 长度
    char line[MAXLENGTH], longest[MAXLENGTH]; // 内容

    while((len = getLine(line)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0){
        printf("%s:%d", longest, max);
    }
}


// !!!练习 1-17 打印长度超过80的行
void emptyLine(char line[]){
    for(int i=0; i < MAXLENGTH; i++)
        line[i] = 0;
}

void oneSeventeen(){
    int len;
    char line[MAXLENGTH];
    emptyLine(line);

    len = getLine(line);
    if(len > 10)
        printf("%s", line);
}


// !!!练习 1-18 将每个输入行末尾的所有空格和制表符去掉,并将全空白的行删除掉
void oneEighteen(){
    char s[MAXLENGTH], s2[MAXLENGTH];
    emptyLine(s);
    int len = getLine(s);

    while(s[len] == '\t' || s[len] == ' ')
        --len;
    while(len >= 0){
        s2[len] = s[len];
        --len;
    }

    printf("%s", s2);
}


// !!!练习 1-19 写一个 reverse 函数,再写一个程序以行为单位翻转
int len(char s[]){
    int i = 0, counter = 0;

    while(i < MAXLENGTH && s[i] != '\0'){
        ++counter;
        ++i;
    }

    return counter;
}

void reverse(char s[]){
    char rs[MAXLENGTH]; emptyLine(rs);
    int i = 0;

    int slen = len(s);
    while(i < slen){
        rs[slen] = s[i];
        ++i;
    }
    printf("%s", rs);
}
