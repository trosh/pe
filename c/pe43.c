#include <stdio.h>

void perm(int set[10], int rest[10],
          int setl,    int restl,
          int primes[7], long long int *sum) {
	int i, j, k, rest2[10];
	long long int n = 0;
	if (setl==4) if (set[3]%2!=0) return;
	if (restl==0) { // set full
		// check if substringdivshit
		k = set[1]*10+set[2];
		for (i=0; i<7; i++) {
			k = (k%100)*10+set[i+3];
			if (k%primes[i]!=0) return; }
		int cnt = 0;
		for (i=0; i<9; i++)
			n = n*10+set[i];
		*sum += n; }
	for (i=0; i<restl; i++) {
		// append set
		set[setl] = rest[i];
		// fill rest2
		for (k=j=0; j<restl; j++)
			if (i!=j)
				rest2[k++] = rest[j];
		// recursion
		perm(set, rest2, setl+1, restl-1, primes, sum); } }

int main() {
	int n, i, j, primes[7], set[10], rest[10], flag;
	long long int sum = 0;
	// build primes
	for (n=(i=0)+2; i<7; n++) {
		flag = 1;
		for (j=2; j<=n/2; j++)
			if (n%j==0) {
				flag = 0;
				break; }
		if (flag) {
			primes[i] = n;
			i++; } }
	for (i=0; i<10; i++)
		rest[i] = i;
	perm(set, rest, 0, 10, primes, &sum);
	printf("%d\n", sum);
	return 0; }
