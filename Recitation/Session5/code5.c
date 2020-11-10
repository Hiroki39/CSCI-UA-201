#include <stdio.h>

struct Point
{
   int x;
   int y;
   char a,b,c,d;
};

int main() {
    // declaring
    struct Point p = {3, 20, 'a', 'b', 'c', 'd'};
    int *ptr = &p.x;

    // accessing
    *ptr = 4;
    printf("output1: %d\n", p.x);

    // pointer arithmetic
    ptr = ptr + 1;
    printf("output2: %d\n", *ptr);

    *ptr = 100;
    printf("output3: %d\n", p.y);

    ptr = ptr + 1;
    // *ptr = 256*256*256*74 + 256*256*75 + 256*76 + 77;
    // printf("output4: %d\n", *ptr);
    // printf("char a = %c, b = %c, c = %c, d = %c\n", p.a, p.b, p.c, p.d);

    // no change in pointer value, unlike casting primitive data types
    char* ptr2 = (char*)ptr;
    *ptr2 = 'J';
    *(ptr2 + 1) = 'K';
    *(ptr2 + 2) = 'L';
    *(ptr2 + 3) = 'M';
    printf("char a = %c, b = %c, c = %c, d = %c\n", p.a, p.b, p.c, p.d);
    printf("output4 *ptr: %d\n", *ptr);
    printf("output4 *ptr2: %c\n", *ptr2);
}


/**
ASCII codes:-
J: 01001010 = 74
K: 01001011 = 75
L: 01001100 = 76
M: 01001101 = 77

J||K||L||M: 01001010 01001011 01001100 01001101

mew: ‭‭11100110‬ = 230

mew || K || L || M: ‭‭11100110‬ 01001011 01001100 01001101
*/