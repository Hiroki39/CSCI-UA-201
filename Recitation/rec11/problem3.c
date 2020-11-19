#include <stdio.h>
#include <stdlib.h>

int division(int val, int div) {
    while (val > div) {
        val -= div;
    }
    if (val < div) {
        return val;
    } else {
        return 0;
    }
}

int main() {
    printf("%d\n", division(17, 3));
    printf("%d\n", division(21, 7));
}