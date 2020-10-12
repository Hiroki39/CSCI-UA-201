#include <stdio.h>
#include <stdlib.h>

float powtest(float x, unsigned int exp) {
    /* base case */
    if (exp == 0) {
        return 1.0;
    }

    /* recursive case */
    return x * powtest(x, exp - 1);
}

int main(int argc, char** argv) {
    float p;
    int exp = 0;

    if (argc == 1)
        p = powtest(10.0, 5);
    else {
        sscanf(argv[1], "%f", &p);
        printf("input number is %.6f\n", p);
        exp = atoi(argv[2]);
        printf("input exponent is %d\n", exp);
        p = powtest(p, exp);
    }
    printf("p = %.6f\n", p);
    return 0;
}
