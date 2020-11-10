// original code fails because arr is freed after sum() so that error occurs
// when product() is executed
#include <stdio.h>
#include <stdlib.h>

int sum(int* arr) {
    int x = 0;
    for (int i = 0; i < 1000000; i++) x += arr[i];
    return x;
}

int product(int* arr) {
    int x = 1;
    for (int i = 0; i < 1000000; i++) x *= arr[i];
    return x;
}

int main(int argc, char* argv[]) {
    int* arr = (int*)malloc(1000000 * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    for (int i = 0; i < 1000000; i++) arr[i] = i;

    printf("Sum of array: %d\n", sum(arr));
    printf("Product of array: %d\n", product(arr));

    free(arr);
    return 0;
}
