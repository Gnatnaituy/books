#include <stdio.h>
#include "program_structure_and_execution/representing_and_manipulating_information/swap_x_y.c"

int main() {
    int x = 100, y = 200;
    inplace_swap(&x, &y);
    printf("x: %d, y: %d", x, y);

    return 0;
}
