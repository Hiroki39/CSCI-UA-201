#include <stdio.h>

unsigned replace_byte(unsigned x, int k, char byte) {
    /* replace the (k + 1)th byte of x with the input byte */
    char* x_ptr = (char*)&x;
    x_ptr[k] = byte;
    return x;
}

int main(int argc, char const* argv[]) {
    unsigned x = 0x12345678;
    char c = 0xAB;
    x = replace_byte(x, 2, c);
    printf("%x\n", x);
    // char* x_ptr = (char*)&x;
    // printf("%li\n", sizeof(x));
    // for (int i = 0; i < sizeof(x); ++i) {
    //     printf("%x ", x_ptr[i]);
    // }
    // printf("\n");
    return 0;
}
