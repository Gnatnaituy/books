//
// Created by Ravooo on 2021/7/30.
//
#include "program_structure_and_execution/representing_and_manipulating_information/swap_x_y.c"

void reverse_array(int[] a, int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}