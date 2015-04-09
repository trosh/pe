#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000000

char isperm(int a, int b) {
	char ad[7], bd[7];
	int and, bnd, i, j, la, lb;
	for (and=0; a; and++) {
		ad[and] = a%10;
		a /= 10;
	}
	for (bnd=0; b; bnd++) {
		bd[bnd] = b%10;
		b /= 10;
	}
	if (and != bnd) return 0;
	/* SORT AD & BD & CHECK */
	for (i=0; i<and; i++) {
		la = i;
		lb = i;
		for (j=i+1; j<and; j++) {
			if (ad[j]>ad[la]) la = j;
			if (bd[j]>bd[lb]) lb = j;
		}
		if (la != i) {
			j = ad[la];
			ad[la] = ad[i];
			ad[i] = j;
		}
		if (lb != i) {
			j = bd[lb];
			bd[lb] = bd[i];
			bd[i] = j;
		}
		if (ad[i] != bd[i]) return 0;
	}
	return 1;
}

int main() {
	float ratio;
	char *sieve;
	int *primes, phi, i, j, c, d,
	    bestd, p1, p2;
	sieve = (char*)calloc(MAX, 1);
	primes = (int*)malloc(MAX*sizeof(int)/sqrt(2));
	c = 0;
	for (i=2; i<MAX; i++)
		if (sieve[i]==0) {
			primes[c++] = i;
			for (j=i*2; j<MAX; j+=i)
				sieve[j] = 1;
		}
	puts("gen'd primes");
	ratio = MAX;
	bestd = 0;
	for (p1=0; p1<c; p1++)
	for (p2=p1; primes[p2]<MAX/primes[p1]; p2++) {
		d = primes[p1]*primes[p2];
		phi = (primes[p1]-1)*(primes[p2]-1);
		if (isperm(d, phi))
			if (1.*d/phi < ratio) {
				ratio = 1.*d/phi;
				bestd = d;
				printf("%d %d\n", d, phi);
			}
	}
	printf("bestp = %d\n", bestd);
	free(sieve);
	free(primes);
	return 0;
}
