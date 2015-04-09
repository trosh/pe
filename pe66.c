#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int D, rt, i, j, maxD, termscap, termssize;
	long long num, den, tmp, out, fac, x, maxx, y, *terms;
	rt = 2;
	maxD = 1;
	maxx = 0;
	termscap = 256;
	terms = (long long*)malloc(termscap*sizeof(long long));
	for (D=2; D<1001; D++) {
		if (D == rt*rt) {
			rt++;
			continue;
		}
		printf("D=%d ", D);
		fflush(stdout);
		num = 1;
		den = 1-rt;
		terms[0] = rt-1;
		termssize = 1;
		for (i=0 ;; i++) {
			fac = num;
			num = -den;
			den = D-den*den;
			den /= fac;
			out = 0;
			while (num-den > -rt) {
				out++;
				num -= den;
			}
			if (termssize == termscap)
				terms = (long long*)realloc(terms,
						(termscap*=2)*sizeof(long long));
			terms[termssize++] = out;
			tmp = den;
			den = num;
			num = tmp;
			x = 1;
			y = out;
			for (j=i; j>=0; j--) {
				x += y*terms[i];
				tmp = x;
				x   = y;
				y   = tmp;
			}
			printf("%lld..", y);
			fflush(stdout);
			if (y*y-D*x*x == 1) {
				if (x > maxx) {
					maxD = D;
					maxx = x;
				}
				break;
			}
		}
		putchar('\n');
	}
	printf("maxD=%d maxx=%lld\n", maxD, maxx);
	free(terms);
	return 0;
}
