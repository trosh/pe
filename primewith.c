#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *sieve;
	int *primes, i, j, c, n, d, D, numfracs;
	if (argc!=2) {
		puts("usage: primewith num");
		return 1;
	}
	n = 0;
	for (i=0; argv[1][i]; i++) {
		c = argv[1][i];
		if (c<'0' || c>'9') {
			puts("bad argument");
			return 1;
		}
		n *= 10;
		n += c-'0';
	}
	sieve = (char*)calloc(n+1, 1);
	primes = (int*)malloc(n);
	c = 0;
	for (i=2; i<=n; i++)
		if (sieve[i]==0) {
			primes[c++] = i;
			for (j=i*2; j<=n; j+=i)
				sieve[j] = 1;
		}
	numfracs = 0;
	for (d=1; d<n; d++) {
		D = d;
		for (j=primes[i=0]; D!=1;)
			if (D%j==0) {
				if (n%j==0)
					goto lbl1;
				D /= j;
			} else
				j = primes[++i];
		numfracs++;
		lbl1:;
	}
	printf("numfracs = %d\n", numfracs);
	free(sieve);
	free(primes);
	return 0;
}
