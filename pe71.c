#include <stdio.h>

int main() {
	char sieve[1000000]={0};
	int primes[400000];
	int i, j, c;
	long long n, d, bn, bd;
	c = 0;
	for (i=2; i<1000000; i++)
		if (sieve[i]==0) {
			primes[c++] = i;
			for (j=i*2; j<1000000; j+=i)
				sieve[j] = 1;
		}
	bn = 0;
	bd = 1;
	for (d=2; d<=1000000; d++) {
		n = 3*d/7;
		if (n*7 == d*3) continue;
		if (n*bd > bn*d) {
			bn = n;
			bd = d;
		}
	}
	j = 2;
	for (i=0; j<=bn&&j<=bd&&i<c; j=primes[++i])
		if (bn % j == 0
		 && bd % j == 0) {
			bn /= j;
			bd /= j;
			i = 0;
			j = 2;
		}
	printf("best reduced numerator : %d\n", bn);
	return 0;
}
