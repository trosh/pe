#include <stdio.h>

int main() {
	char sieve[1000001]={0};
	int primes[400000], i, j, c, n, d, phin, phid;
	long long numfracs;
	c = 0;
	for (i=2; i<=1000000; i++)
		if (sieve[i]==0) {
			primes[c++] = i;
			for (j=i*2; j<=1000000; j+=i)
				sieve[j] = 1;
		}
	puts("\033[32mPRIMES GENERATED\033[0m");
	numfracs = 0;
	for (d=2; d<=1000000; d++) {
		if (sieve[d]==0) {
			numfracs += d-1;
			continue;
		}
		phin = n = d;
		phid = 1;
		for (j=primes[i=0]; n!=1; j=primes[++i]) {
			if (n%j) continue;
			phin *= j-1;
			phid *= j;
			if (phin%phid==0) {
				phin /= phid;
				phid = 1;
			}
			while (n%j==0) n/=j;
		}
		if (d%100000==0) {
			if (d>100000)
				putchar('.');
			printf("%d", d);
			fflush(stdout);
		}
	}
	printf("\nnumfracs = %lld\n", numfracs);
	return 0;
}
