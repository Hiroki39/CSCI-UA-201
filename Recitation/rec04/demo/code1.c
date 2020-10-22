#include <stdio.h>

int main() {
    float x = 2.0f;
    for (int i = 1; i < 130; i++) {
        printf("i=%d, x=%f\n", i, x);
        x *= 2.0f;
    }

    return 1;
}
