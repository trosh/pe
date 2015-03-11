#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000

char *sieve;
int *primes;

void initprimes() {
	int i, j, np;
	sieve = (char*)calloc(MAX/2+2, 1);
	primes = (int*)malloc(MAX/2);
	primes[0] = 2;
	np = 1;
	for (i=0; i<MAX/2; i++)
		if (sieve[i] == 0) {
			primes[np++] = i*2+3;
			for (j=i*3+3; j<MAX/2; j+=i*2+3)
				sieve[j] = 1;
		}
	puts("\nprime init");
}

char isprime(int n) {
	if (n==2) return 1;
	if (n%2==0) return 0;
	if (n<2) return 0;
	return ! sieve[(n-3)/2];
}

int concat(int a, int b) {
	int i, c=0;
	for (i=0; b; i++) {
		c *= 10;
		c += b%10;
		b /= 10;
	}
	for (i=0; a; i++) {
		c *= 10;
		c += a%10;
		a /= 10;
	}
	for (i=0; c; i++) {
		a *= 10;
		a += c%10;
		c /= 10;
	}
	return a;
}

char isgoodset(int* t, int s) {
	// assume the (t, s-1) is already good
	int i, n;
	for (i=0; i<s-1; i++) {
		n = concat(t[i], t[s-1]);
	 	if (!isprime(n))
			return 0;
		n = concat(t[s-1], t[i]);
		if (!isprime(n))
			return 0;
	}
	return 1;
}

int main() {
	int i, j, a, b, c, d, e, *t, n, sum;
	initprimes();
	t = (int*)malloc(5*sizeof(int));
	for (a=0; a<MAX/4; a++) { t[0] = primes[a];
	for (b=0; b<a; b++) { t[1] = primes[b];
		if (!isgoodset(t, 2)) continue;	
	for (c=0; c<b; c++) { t[2] = primes[c];
		if (!isgoodset(t, 3)) continue;		
	for (d=0; d<c; d++) { t[3] = primes[d];
		if (!isgoodset(t, 4)) continue;	
	for (e=0; e<d; e++) { t[4] = primes[e];
		if (!isgoodset(t, 5)) continue;	
		printf("%d %d %d %d %d\n", t[0], t[1], t[2], t[3], t[4]);
		sum = t[0]+t[1]+t[2]+t[3]+t[4];
		printf("sum=%d\n", sum);
		notprime:;
	} } } } }
	free(sieve);
	return 0;
}
