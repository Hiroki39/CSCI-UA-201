// printArray() will have no idea of the size of arr because the program only
// recieve a pointer

#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int i;
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < arr_size; i++) printf("%d\n", arr[i]);
    return 0;
}
