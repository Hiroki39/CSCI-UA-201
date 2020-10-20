#include <stdio.h>

unsigned compression(unsigned x, unsigned y) {
    /* the result contain the least significant bytes of x and remaining bytes
     * of y */
    int result;
    char* x_ptr = (char*)&x;
    char* y_ptr = (char*)&y;
    char* result_ptr = (char*)&result;
    *result_ptr = *x_ptr;
    for (int i = 0; i < sizeof(x) - 1; ++i) {
        ++y_ptr;
        ++result_ptr;
        *result_ptr = *y_ptr;
    }
    // result_ptr = (char*)&result;
    // for (int i = 0; i < sizeof(x); ++i) {
    //     printf("%x", result_ptr[i]);
    // }
    // printf("\n");
    return result;
}

int main(int argc, char const* argv[]) {
    unsigned x = 0x89ABCDEF;
    unsigned y = 0x12345678;
    unsigned result = compression(x, y);
    printf("%x\n", result);
    return 0;
}
