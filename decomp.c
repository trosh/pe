#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *sieve;
	int *primes, i, j, c, n;
	if (argc!=2) {
		puts("usage: decomp num");
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
	for (j=primes[i=0]; n!=1&&i<=c;) {
		if (n%j) {
			j=primes[++i];
			continue;
		}
		n /= j;
		printf("%d ", j);
	}
	putchar('\n');
	free(sieve);
	free(primes);
	return 0;
}
