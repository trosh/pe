#include <stdio.h> // printf()
#include <stdlib.h> // malloc()
#include <unistd.h> // sleep()

static char *primes; 

static char *primesieve(long long int up) {
	long long int n, i, pos;
	primes = malloc(up>>4);
	primes[0] = 4;
	for (n=3; n<up; n+=2) {
		pos = ((n-3)>>1)+3;
		if (!(primes[pos>>3]&(1<<(pos%8))))
			for (i=3*n; i<up; i+=(n<<1)) {
				pos = ((i-3)>>1)+3;
				primes[pos>>3]|=(1<<(pos%8)); } } }

static char isprime(long long int n) {
	// lets hope n < len(primes)
	long long int pos;
	if (n==2) return 1;
	if (!(n%2)) return 0;
	pos = ((n-3)>>1)+3;
	return !(primes[pos>>3]&(1<<(pos%8))); }

int main(int argc, char *argv[]) {
	long long int i;
	int j;
	primesieve(2e7);
	if (argc != 3)
		for (j=20; j<80; j++) {
			for (i=2; i<1800; i++) {
				if (isprime(i))
					printf("\033[47m  \033[0m");
				else if (i%2)
					printf("  ");
				if (!(i%j))
					printf("\n"); }
			printf("\n%d\n", j);
			sleep(1); }
	else {
		int n = 0, m = 0;
		for (i=0 ;; i++) {
			j = argv[1][i];
			if (j=='\0') break;
			j -= '0';
			if (j<0 || j>9) return 1;
			n *= 10;
			n += j; }
		for (i=0 ;; i++) {
			j = argv[2][i];
			if (j=='\0') break;
			j -= '0';
			if (j<0 || j>9) return 1;
			m *= 10;
			m += j; }
		for (i=2 ;; i++) {
			if (isprime(i))
				printf("\033[%d;%dH\033[47m  \033[0m", i%n, i%m);
			//else if (i%2)
			//	printf("  ");
			//if (!(i%n))
			//	printf("\n");
			if (!(i%(n*m))) {
				sleep(1);
				printf("\033[2J"); } } }
	return 0; }
