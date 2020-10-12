#include <stdio.h>

int main() {
    // declaring
    int x = 3;
    int y = 20;
    int* ptr = &x;

    // accessing
    *ptr = 4;
    printf("%d\n", x);

    // pointer arithmetic
    ptr = ptr + 1;
    printf("%d\n", *ptr);

    *ptr = 100;
    printf("%d\n", y);
}
