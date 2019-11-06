#include <stdio.h>
#include <math.h>

//	calculate y_n = int_0^1 (x^n / (x + 5)) dx
//	y_n + 5 y_{n-1} = 1 / n
//	y_0 = ln(x + 5) | _0^1 = ln(6) - ln(5)

//	Algorithm 1
//	Rounding error of y0 is multiplied by -5 to calculate y1, so y1 is affected
//	by error -5 epsilon, y2 by -5^2 epsilon, etc.
//	So this approach is numerically unstable (small initial errors cause large
//	errors in results

//	Algorithm 2
//	y_{n-1} = 1 / (5n) - 1 / 5 y_n
//	y_19 = 1 / (5 * 20) - 1 / 5 y_20 for n = 20
//	Assuming y_19 = y_20 we get:
//	y_19 = 1 / (5 * 20) - 1 / 5 y_19
//	6 y_19 = 1 / 20 => y_19 = 1 / 120 and we go backwards to y_0
//	In this approach we divide the error by 5 instead of multiplying


typedef double real;

int main(int argv, char* argc[]) {
	int nmax = 20;

	//	Algorithm 1
	printf("\nAlgorithm 1: \n\n");
	real y = log(6./5.);
	printf("%5d %25.15e\n", 0, y);
	for(int n = 1; n < nmax; ++n) {
		y = 1./n - 5.*y;
		printf("%5d %25.15e\n", n, y);
	}

	//	Algorithm 2
	printf("\nAlgorithm 2: \n\n");
	y = 1. / (6. * nmax);
	printf("%5d %25.15e\n", nmax-1, y);
	for(int n = nmax-1; n > 0; --n) {
		y = 0.2/n - 0.2*y;
		printf("%5d %25.15e\n", n-1, y);
	}
	return 0;
}
