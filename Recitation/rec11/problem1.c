long loop(long x, long n) {  // x in %rdi
    long result = 0;         // result in %rax
    long mask;               // mask in %rdx

    for (mask = 1; mask & mask; mask <<= n) {
        result |= (x & mask);
    }
    return result;
}