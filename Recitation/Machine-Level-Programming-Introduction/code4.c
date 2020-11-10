
long set(long* src, long dest, long i) {
    // %rdi = src
    // %rsi = dest
    // %rdx = i
    *src = dest;
    *(src + 1) = (dest + 1);
    *(src + 2) = (dest + 2);
    *(src + i) = (dest + i);
}