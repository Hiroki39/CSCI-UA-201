#include <assert.h>
#include <stdio.h>
#include "util.h"

/*
 To turn off a bit means to set it to zero.
 To turn on a bit means to set it to one.
 To flip a bit means to switch it to 1 if it is 0, and vice versa.

 Write a function bit_wisdom that takes an integer n and..
    1. Turns off all of the bits except for the last 4 (1 2 4 8's bit)
    2. Flips the last two bits (1 and 2's)
    3. And turns on the second to last 2 bits. (4 and 8's. if its already on
 leave it on)
*/

int bit_wisdom(int n) {
    n ^= 0b11;
    n &= 0b1111;
    n |= 0b1100;
    return n;  // change this to return your calcualted value
}

int main() {
    assert(bit_wisdom(0b11111111) == 0b00001100);
    assert(bit_wisdom(0b00000000) == 0b00001111);
    assert(bit_wisdom(0b10101010) == 0b00001101);
    assert(bit_wisdom(0b01010101) == 0b00001110);

    part_completed(11);

    return 0;
}
