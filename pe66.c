#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
	int D, rt, maxD, cnt;
	long long x, sqx, maxx, y;
	float xapprox;
	rt = 2;
	maxD = 1;
	maxx = 0;
	for (D=2; D<1001; D++) {
		if (D == rt*rt) {
			rt++;
			continue;
		}
		cnt = 0;
		for (y=2 ;; y++) {
			cnt++;
			if (cnt%500000 == 0) {
				printf("%ld..", y);
				fflush(stdout);
			}
			sqx = 1+y*y*D;
			xapprox = sqx;
			xapprox = sqrt(xapprox)-1;
			for (x=xapprox ;; x++) {
				if (x*x > sqx) goto notfound;
				if (x*x == sqx) break;
			}
			if (x>maxx) {
				maxx = x;
				maxD = D;
			}
			break;
			notfound:;
		}
		printf("D=%ld x=%ld\n", D, x);
	}
	printf("maxD=%ld maxx=%ld\n", maxD, maxx);
	return 0;
}
