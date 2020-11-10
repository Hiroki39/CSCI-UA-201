#include <stdio.h>

int main () {
    // use addressOf operator
    int x = 2;
    int y = 3;

    printf("Address of x variable: %x\n", &x);
    printf("Address of y variable: %x\n", &y);
    printf("\n");



    // pointer variable declaration
    int *ip;
    ip = &x;


    // dereference
    x += 4;
    printf("Value of ip: %x\n", ip);
    printf("Value stored at ip location: %d\n", *ip);
    printf("\n");


    // pointer arithmetic
    *ip = *ip + 8;
    printf("Value of x: %d\n", x);
    printf("Value of y: %d\n", y);
    printf("\n");

    ip = ip + 1;
    *ip = 10;
    printf("Value of x: %d\n", x);
    printf("Value of y: %d\n", y);
    printf("\n");

    return 0;
}