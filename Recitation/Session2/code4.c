#include <stdio.h>

int main() {
    int a[5] = {0,1,2,3,4};
    a[2]++;
    printf("%d\n", a[1000001]);
    return 0;
}