#include <float.h>
#include <stdio.h>

int main() {
    int x = 0x7FFFFFFF;
    int x_plus_one = x + 1;
    printf("%i\n", x_plus_one + x_plus_one);
}
