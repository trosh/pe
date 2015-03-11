#include <stdio.h> // printf()
#include <stdlib.h> // malloc()
#include <time.h> // time_t, clock()

static char* primes;

char isprime(unsigned int n) {
	int pos = (n-3)>>1+3;
	return !(primes[pos>>3]&1<<pos%8); }

int main() {
	time_t t = clock();
	unsigned int up=1e4, i, j, k, l, m, n[up], o, p, q;
	primes = malloc(up>>4);
	primes[0] = 4;
	for (i=3; i<up; i+=2) {
		k = (i-3)>>1+3;
		if (primes[k>>3]&1<<k%8) continue;
		for (l=i; l; l/=10) {
			q = 1;
			for (p=(o=l%10); p; p--) q*=10;
			n[i] += q; }
		for (j=k<<1; j<up; j+=k) {
			primes[j>>3]|=1<<j%8; } }
	for (i=up/10+1; i<up; i+=2) {
		if (!isprime(i)) continue;
		printf("%d\t", i);
		for (j=2; i+j<<1<up; j+=2) {
			if (!isprime(i+j)
			 || !isprime(i+j<<1)
			 || n[i] != n[i+j]
			 || n[i] != n[i+j<<1]) continue;
			printf("%d %d %d %d\n", i, i+j, i+j<<1, j); } }
	printf("%d\n", clock()-t);
	return 0; }
