#include <stdio.h>

long scale(long x, long y, long z) {
    z = 3 * z + 4;
    return (x + y) + 4 * z + 3;
}