#include <stdio.h>
#include <stdlib.h>

void prod(int* x, int* y) {
    int v1 = *x;
    int v2 = *y;
    *x = v1 * v2;
}

int main() {
    int x = 5;
    int* ptr = 0;
    prod(&x, ptr);

    return 0;
}
