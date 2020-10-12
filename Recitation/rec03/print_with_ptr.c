#include <stdio.h>

int main() {
    const int SIZE = 6;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int* cursor = arr;

    for (int i = 0; i < SIZE; ++i) {
        printf("%i ", *cursor);
        cursor++;
    }
    printf("\n");
}
