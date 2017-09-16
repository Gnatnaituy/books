#include <stdio.h>

int main(){

    float Fahr, Cels;
    int lower = 0, upper = 300, step = 20;

    Cels = lower;
    while(Cels <= upper){
        Fahr = (9.0/5.0) * Cels + 32.0;
        printf("%6.1f %3.0f\n", Cels, Fahr);
        Cels += step;
    }
}