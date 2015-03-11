#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main() {
	int primes[MAX/4];
	int i, j, c, sum, biggestsum, longest;
	char sieve[MAX] = {0};
	c = 0;
	for (i=2; i<MAX; i++) {
		if (sieve[i]) continue;
		primes[c++] = i;
		for (j=2*i; j<MAX; j+=i)
			sieve[j] = 1;
	}
	longest = 0;
#pragma omp parallel for private(j,sum)
	for (i=0; i<c; i++) {
		sum = 0;
		for (j=i; j<c; j++) {
			sum += primes[j];
			if (sum > MAX) break;
			if (sieve[sum] == 0) {
#pragma omp critical
				{
					if (j-i+1 > longest) {
						longest = j-i+1;
						biggestsum = sum;
					}
				}
			}
		}
	}
	printf("sum of %d primes -> %d\n", longest, biggestsum);
	return 0;
}
