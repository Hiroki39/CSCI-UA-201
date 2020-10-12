#include <stdio.h>
#include <string.h>

void print_in_binary(char s)
{
    static char b[17];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((s & z) == z) ? "1" : "0");
    }

    printf("%d in binary is %s\n", s, b);
}

void part_completed(int part)
{
    printf("Tests for part%3d passed!\n", part);
}
