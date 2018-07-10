#include <stdio.h>
#include <memory.h>
#include "Chapter2/show_bytes.c"

int main() {
//    int  a = 123456789;
//    int *p = &a;
//    test_show_bytes(p);
    const char *s = "abcdef\n";
    show_bytes((byte_pointer) s, strlen(s));

    return 0;
}