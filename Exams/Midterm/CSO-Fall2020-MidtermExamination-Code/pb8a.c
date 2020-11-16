#include <stdio.h>

void decode1(long* xp, long* yp, long* zp) {
    long temp1 = *xp;
    long temp2 = *yp;
    long temp3 = *zp;
    *zp = temp1;
    *xp = temp2;
    *yp = temp3;
}