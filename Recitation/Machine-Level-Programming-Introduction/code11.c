// %rdi=n
long fibonacci(long n) {
    if(n<=2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}


// 10
// | \
// 9   8
// | \ | \
// 8 7 7  6
// | ......