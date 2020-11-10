#include <stdio.h>
#include <stdlib.h>

int factorial(int x) {
    int y = 1;
    // comment for stack overflow
    if(x > 1)
        y = x * factorial(x - 1);
    return y; 
}

int main(int argc, char* argv[]) {
    int x = factorial(5);
    printf("Factorial: %d\n", x);

    int arr[20];
    // int arr[10000000]; // size = 4 * 10^7 bytes = 40MB
    printf("Size of array: %ld\n", sizeof(arr));
    return 0;
}