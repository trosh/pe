#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main() {
	int primes[MAX/4];
	int i, j, c, k, l, n, o, nd, np, firstprime;
	char sieve[MAX] = {0}, comb[10], digits[10], first;
	c = 0;
	for (i=2; i<MAX; i++) {
		if (sieve[i]) continue;
		primes[c++] = i;
		for (j=2*i; j<MAX; j+=i)
			sieve[j] = 1;
	}
	for (o=0; o<c; o++) {
		k = n = primes[o];
		for (nd=0; k; nd++) {
			digits[nd] = k%10;
			k /= 10;
		}
		for (i=0; i<(1<<nd); i++) { // INDEX OF CURRENT COMBINATION
			for (j=0; j<nd; j++)
				comb[j] = i%(2<<j) < (1<<j);
			np = 0;
			first = 1;
			for (j=0; j<10; j++) {
				k = 0;
				for (l=nd-1; l>=0; l--) {
					k *= 10;
					if (comb[l]) k += j;
					else         k += digits[l];
				}
				if (j==0 && comb[nd-1]) continue;
				if (k>1 && sieve[k] == 0) {
					np++;
					if (first) firstprime = k;
					first = 0;
				}
			}
			if (np == 8) {
				printf("%d\n", firstprime);
				return 0;
			}
		}
	}
	return 0;
}
