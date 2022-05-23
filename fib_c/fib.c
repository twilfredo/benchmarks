#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/* Compute fib of n, Fn = Fn-1 + Fn+2 */
unsigned long 
fib(unsigned long n)
{
	if (n <= 1)
		return n;

	return (fib(n-1) + fib(n-2));
}

/* Compute fib on N and measure the computational delay 
 * Proportional to single core performance ??
 */
int
main(void) 
{
	/* Calculate the fib of Fn */
	int n = 40;
	struct timespec ts, ts2;

	if(clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
		fprintf(stderr, "Clock err\n");
		return -1;
	}

	fprintf(stdout, "Fib of N:%d is %d\n\r", n,fib(n));

	if(clock_gettime(CLOCK_MONOTONIC, &ts2) != 0) {
		fprintf(stderr, "Clock err\n");
		return -1;
	}

	fprintf(stdout, "Math Diff: %f\n\r", (ts2.tv_nsec - ts.tv_nsec) / 1000000.00 );
	return 0;
}
