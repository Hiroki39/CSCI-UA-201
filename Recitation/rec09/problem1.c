#include <stdio.h>

long absdiff(long x, long y) {
    long result;
    if (x > y)
        result = x - y;
    else
        result = y - x;
    return result;
}

int main() {
    long dif1 = absdiff(10, 7);
    long dif2 = absdiff(7, 10);

    printf("dif1: %ld\ndif2: %ld\n", dif1, dif2);
}
