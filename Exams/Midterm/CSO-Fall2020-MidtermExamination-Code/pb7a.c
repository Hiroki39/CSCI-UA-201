#include <stdio.h>
#include <stdlib.h>

void foo() {
    int* ptr = (int*)malloc(sizeof(int) * 10000000);
    for (int i = 0; i < 10000000; i++) ptr[i] = i;
    free(ptr);
}

int main(int argc, char* argv[]) {
    int* arr = (int*)malloc(10000000 * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    printf("Size of array: %ld\n", sizeof(arr));
    for (int i = 0; i < 100; i++) arr[i] = i;

    while (1) {
        foo();
    }

    return 0;
}
