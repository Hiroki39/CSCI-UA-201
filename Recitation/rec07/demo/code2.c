long exchange(long* xp, long y) {
    // %rdi = xp
    // %rsi = y
    long x = *xp;
    *xp = y;
    return x;
}
