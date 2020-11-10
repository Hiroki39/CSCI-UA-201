// in the orriginal version, the ptr will try to print out '\0', result in the
// error
#include <stdio.h>

int main() {
    char str[] = "Hello";
    char* ptr = str;
    while (*ptr != '\0') {
        printf("%c\n", *ptr);
        ptr++;
    }
    return 0;
}
