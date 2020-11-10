#include <stdio.h>

void swap (long *xp, long *yp) {
	long t0 = *xp;
	long t1 = *yp;
	*xp = t1;
	*yp = t0;
}


int main() {

	long x = 5;
	long y = 10;
	printf("x is %ld and y is %ld\n", x, y);
	swap(&x, &y);
	printf("now x is %ld and y is %ld\n", x, y);
	return 0;
}
