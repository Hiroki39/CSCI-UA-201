// gcc -Og -S code4.c
long plus(long x, long y) {
    return x+y;
}

void sumstore(long x, long y, long* dest) {
    long t = plus(x,y);
    *dest = t;
}