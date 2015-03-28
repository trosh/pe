#include <stdio.h>

int main() {
	char sieve[1000000]={0}, firstfind;
	int primes[400000], dec, i, j, c, n, d;
	long long numfracs;
	c = 0;
	for (i=2; i<1000000; i++)
		if (sieve[i]==0) {
			primes[c++] = i;
			for (j=i*2; j<1000000; j+=i)
				sieve[j] = 1;
		}
	numfracs = 0;
	for (d=2; d<=1000000; d++) {
		for (n=1; n<d; n++) {
			for (j=primes[i=0]; j<=n; j=primes[++i])
				if (n%j==0 && d%j==0)
					goto lbl1;
			numfracs++;
			lbl1:;
		}
		if (d%1000==0) {
			printf("%d..", d);
			fflush(stdout);
		}
	}
	printf("numfracs=%d\n", numfracs);
	return 0;
	for (d=2; d<=8; d++) {
		numfracs += d - 1;
		if (sieve[d]==0) continue;
		n = d;
		firstfind = 1;
		for (j=primes[i=0]; n!=1&&i<c;) {
			if (n%j) {
				j=primes[++i];
				continue;
			}
			n /= j;
			numfracs -= j-1;
		}
		printf("%d -> %ld\n", d, numfracs);
		if (d%10000==0) {
			printf("%d..", d);
			fflush(stdout);
		}
	}
	printf("\nnumfracs = %ld\n", numfracs);
	return 0;
}
