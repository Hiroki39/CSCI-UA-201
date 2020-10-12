#include <stdio.h>

int is_little_endian() {
    int k = 0x01234567;
    // 01 23 45 67 if big endian
    // 67 45 23 01 if little endian
    char* start = (char*)&k;
    int n = sizeof(k);  // should be 4 bytes
    printf("The Size of Integer: %i\n", n);
    printf("The Stored address is:");
    for (int i = 0; i < n; ++i) {
        printf("%x", start[i]);
    }
    printf("\n");

    unsigned int j = 1;
    char* c = (char*)&j;

    int result = (*c) ? 1 : 0;  // if the first byte is 1, it is big endian
    return result;
}

int main() {
    printf("%s", is_little_endian() ? "Your Machine is Little Endian\n"
                                    : "Your Machine is Big Endian\n");
}
