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



----
fib(5) = "fib(4)" + fib(3)
------
----
fib(4) = "fib(3)" + fib(2)
----
fib(3) = "fib(2)" + fib(1)
----
fib(2) -> return 1
----





fib(1) -> return 1
----

