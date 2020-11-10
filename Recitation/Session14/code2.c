long who(long x, long y) {
    return x-y;
}

long yoo(long x, long y) {
    long a = who(x+5, y*7);
    x = x*a + y;
    return x*y;
}