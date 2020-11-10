#include <stdio.h>
#include <stdlib.h>

char max_char(char c1, char c2) {
    if (c1 > c2)
        return c1;
    else
        return c2;
}

int max_int(int i1, char i2) {
    if (i1 > i2)
        return i1;
    else
        return i2;
}

long max_long(long l1, long l2) {
    if (l1 > l2)
        return l1;
    else
        return l2;
}

int main() {
    printf("%c\n", max_char('a', 'A'));
    printf("%d\n", max_int(97, 65));
    printf("%ld\n", max_long(97, 65));
}
