#include <stdio.h>

struct Point {
    int x;
    float y;
    char z;
};

int main() {
    struct Point p1 = {3, 1.67f, 'e'};

    // Accessing members of point p1
    p1.x = 20;
    printf("x = %d, y = %f, z = %c\n", p1.x, p1.y, p1.z);
    printf("Size of int = %lu, float = %lu, char = %lu\n", sizeof(p1.x),
           sizeof(p1.y), sizeof(p1.z));
    printf("Size of struct = %lu\n", sizeof(struct Point));
    return 0;
}
