long scale(long x, long y, long z) {
    // %rdi = src
    // %rsi = dest
    // %rdx = i
    long t = x + 4 * y + 12 * z;
    return t;
}
