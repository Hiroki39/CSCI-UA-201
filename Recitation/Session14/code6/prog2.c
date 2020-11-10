long who(long x, long y, long *a) {
    return x-y+ (*a);
}

long yoo(long x, long y) {//rdi, rsi
    long arr[4];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    long a = who(x+5, y*7, arr);
    x = x*a + y;
    return x*y;
}