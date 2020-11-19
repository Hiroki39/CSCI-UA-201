#include <stdio.h>

int main() {
    int x = 100;
    while (x > 0) {
        printf("%d\n", 2 * x);
        x -= 10;
    }
}