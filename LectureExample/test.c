#include <float.h>
#include <stdio.h>

int main() {
    int x = 0x80000000;
    int z;
    printf("%i\n", x - 1);
    printf("%i\n", (x - 1) >> 31);
    printf("%i\n", ((x - 1) >> 31) & 1);
    z = !((x - 1) >> 31) & 1;
    printf("%i\n", z);

    int y = 0x80000000;
    y = y - 1;
    printf("%i\n", y);
    printf("%i\n", y >> 31);
    printf("%i\n", (y >> 31) & 1);
    printf("%i\n", !((y >> 31) & 1));
}
