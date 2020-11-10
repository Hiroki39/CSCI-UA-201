#include <stdio.h>

// x = %rdi
// y = %rsi
// z = %rdx
long scale(long x, long y, long z) {
    long a = x + y; // variable to hold the value of %rax
    z = 4 + z + 2 * z;
    a = 3 + a + z * 4;
    // long arr[10];
    // for(long i=0;i<10;i++)
    //     scanf("%ld",arr + i);
    // return a + arr[0];
    return a;
}

long sum() {
    long y = scale(3,4,5);
    y = y + 5;
    return y;
}

// order = %rdi, %rsi, %rdx, %rcx, %r8, %r9