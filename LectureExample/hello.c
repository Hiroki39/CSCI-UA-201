#include <stdio.h>

int add2(int x) {
    x = x + 2;
    return x;
}

int main(int argc, char** argv) {
    int a = 4;
    a = add2(a);
    // Print the string
    printf("a is %i\n", a);
    return 0;
}
