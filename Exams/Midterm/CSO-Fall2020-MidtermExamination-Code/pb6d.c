#include <stdio.h>

struct Point {
    int x;
    char a, b, c, d;
    int y;
};

int main() {
    struct Point p = {3, 'a', 'b', 'c', 'd', 20};
    int* ptr = &p.x;

    // Section1: changing p.x
    *ptr = 4;
    printf("p.x: %d\n", p.x);

    // Section2: changing p.a and p.b
    ptr = ptr + 1;
    char* c_ptr = (char*)ptr;
    *c_ptr = 'A';
    c_ptr++;
    *c_ptr = 'B';
    c_ptr++;
    *c_ptr = 'C';
    c_ptr++;
    *c_ptr = 'D';
    printf("p.a: %c\n", p.a);
    printf("p.b: %c\n", p.b);
    printf("p.c: %c\n", p.c);
    printf("p.d: %c\n", p.d);

    // Section3: changing p.y
    ptr = (int*)++c_ptr;
    *ptr = 30;
    printf("p.y: %d\n", p.y);
}
