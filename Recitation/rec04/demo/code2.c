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
    *ptr = 256 * 256 * 256 * 74 + 256 * 256 * 75 + 256 * 76 + 77;  // M, L, k, J
    printf("output4: %d\n", *ptr);
    printf("char a = %c, b = %c, c = %c, d = %c\n", p.a, p.b, p.c, p.d);

    *ptr = -431272883;  // 00011001 10110100 10110011 10110011
    printf("output5: %d\n", *ptr);
    printf("char a = %c, b = %c, c = %c, d = %c\n", p.a, p.b, p.c, p.d);
    // if there's no (unsigned char), C will interpret it as a signed integer
    printf("Decimal notation of char d = %d\n", (unsigned char)p.d);
}

/**
ASCII codes:-
J: 01001010 = 74
K: 01001011 = 75
L: 01001100 = 76
M: 01001101 = 77

J||K||L||M: 01001010 01001011 01001100 01001101

Greek Letter Mu: ‭‭11100110‬ = 230

Mu || K || L || M: ‭‭11100110‬ 01001011 01001100 01001101
*/
