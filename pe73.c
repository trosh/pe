#include <stdio.h>
#include <strings.h>
#include <time.h>

int main() {
	char sieve[12000]={0};
	int d, n, j, aa, bb, t, c;
	struct timespec tp1, tp2;
	clock_gettime(CLOCK_REALTIME, &tp1);
	c = 0;
	for (d=2; d<=12000; d++) {
		bzero(sieve, d-1);
		for (n=1; n*2<d; n++) {
			if (sieve[n]) continue;
			aa = n;
			bb = d;
			while ((t=bb%aa)) {
				bb = aa;
				aa = t;
			}
			if (aa-1)
				for (j=2*n; j*2<d; j+=n)
					sieve[j]=1;
			if (n*3>d) c++;
		}
	}
	printf("%d\n", c);
	clock_gettime(CLOCK_REALTIME, &tp2);
	printf("time: %lgs\n",
		1.*tp2.tv_sec-tp1.tv_sec
		+(tp2.tv_nsec-tp1.tv_nsec)/1e9);
	return 0;
}
