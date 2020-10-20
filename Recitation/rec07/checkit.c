#include <stdio.h>

int checkit(char c, int x) {
    if (c == 'a') {
        return !!x;
    } else if (c == 'b') {
        return !!(x + 1);
    } else if (c == 'c') {
        return x & 1;
    } else {
        return (x >> 30) & 1;
    }
}

int main(int argc, char const* argv[]) {
    printf("%i\n", checkit('a', 23));
    printf("%i\n", checkit('b', 23));
    printf("%i\n", checkit('c', 23));
    printf("%i\n", checkit('d', 23));
    return 0;
}
