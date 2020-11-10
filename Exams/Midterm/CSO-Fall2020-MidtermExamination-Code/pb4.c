#include <stdio.h>

struct Point {
    int x;
    int y;
    char a, b, c, d;
};

int main() {
    // declaring
    struct Point p = {3, 20, 'a', 'b', 'c', 'd'};
    int* ptr = &p.x;

    // accessing
    *ptr = 4;
    printf("output1: %d\n", p.x);

    // pointer arithmetic
    ptr = ptr + 1;
    printf("output2: %d\n", *ptr);

    *ptr = 100;
    printf("output3: %d\n", p.y);

    ptr = ptr + 1;
    *ptr = 256 * 256 * 256 * 74 + 256 * 256 * 75 + 256 * 76 + 77;
    printf("output4: %d\n", *ptr);
    printf("char a = %c, b = %c, c = %c, d = %c\n", p.a, p.b, p.c, p.d);

    *ptr = 256 * 256 * 256 * 69 + 256 * 256 * 68 + 256 * 79 + 67;
    printf("output5: %d\n", *ptr);
    printf("char a = %c, b = %c, c = %c, d = %c\n", p.a, p.b, p.c, p.d);
}

/**
ASCII codes:-
J: 01001010 = 74
K: 01001011 = 75
L: 01001100 = 76
M: 01001101 = 77

J||K||L||M: 01001010 01001011 01001100 01001101
*/
