#include <stdio.h>

int main() {
    float f = -1.5;
    int i = f;
    printf("%i\n", i);

    f = 1.5;
    i = f;
    printf("%i\n", i);

    f = i;
    printf("%f\n", f);

    int j = 2147483647;
    double d = j;
    f = j;

    printf("%f, %f\n", f, d);
}
