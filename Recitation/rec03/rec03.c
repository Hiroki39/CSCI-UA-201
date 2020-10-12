#include <stdio.h>

void swap_by_value(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_by_reference(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    printf("Enter a and b: ");
    int a1, b1;

    scanf("%i%i", &a1, &b1);

    int a2 = a1;
    int b2 = b1;

    swap_by_value(a1, b1);
    swap_by_reference(&a2, &b2);

    printf("Swap by value: %i %i\n", a1, b1);
    printf("Swap by reference: %i %i\n", a2, b2);
}
