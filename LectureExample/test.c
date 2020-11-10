#include <float.h>
#include <stdio.h>

long pcount_do(unsigned long x) {
    long result = 0;
    do {
        result += x & 0x1;
        x >>= 1;
    } while (x);
    return result;
}

int main() { pcount_do(100u); }
