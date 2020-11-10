#include <stdio.h>

// %rdi:x  %rsi:y  %rdx:z
long test(long x, long y, long z) {
    if (y > x) {
        return 2 * y;
    }

    // L2
    if (z > y) {
        return 3 * z;
    }

    // L4
    return 12 * x;
}