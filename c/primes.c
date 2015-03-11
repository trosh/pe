#include <stdio.h> // printf()
#include <stdlib.h> // malloc()
#include <time.h> // time_t, clock()

int *primesieve1(long long int up) {
	/* bit array prime sieve represented by
	 * int array. seems to make sense since
	 * extended registers are 4 bytes so is
	 * optimal for bit by bit operation on
	 * a large array in memory. */
	long long int n, i;
	int* primes;
	primes = malloc(up>>3);
	for (n=2; n<up; n++)
		if (!(primes[n>>5]&(1<<(n%32))))
			for (i=2*n; i<up; i+=n)
				primes[i>>5]|=(1<<(i%32));
	return primes; }

void testpi(int *primes, long long int up) {
	long long int i, cnt=0;
	for (i=up>>1; i<up; i++)
		if (!(primes[i>>5]&(1<<(i%32))))
			cnt++; }

char *primesieve2(long long int up) {
	/* bit array prime sieve represented by
	 * char array. slight advantage over int
	 * representation for modulo operations
	 * and probably other similar ops. */
	long long int n, i;
	static char* primes;
	primes = malloc(up>>3);
	for (n=2; n<up; n++)
		if (!(primes[n>>3]&(1<<(n%8))))
			for (i=2*n; i<up; i+=n)
				primes[i>>3]|=(1<<(i%8));
	return primes; }

void testpc(char *primes, long long int up) {
	long long int i, cnt=0;
	for (i=up>>1; i<up; i++)
		if (!(primes[i>>3]&(1<<(i%8))))
			cnt++; }

char *primesieve3(long long int up) {
	/* bit array prime sieve represented by
	 * char array, with only odd numbers
	 * symbolised after 2. big advantage for
	 * memory size and number of values tested.
	 * for each value tested there are 3
	 * extra operations to calculate position
	 * in array, but it is negligible over
	 * the time spent accessing memory for
	 * superfluous values. */
	long long int n, i, pos;
	static char* primes;
	primes = malloc(up>>4);
	primes[0] = 2;
	for (n=3; n<up; n+=2) {
		pos = ((n-3)>>1)+3;
		if (!(primes[pos>>3]&(1<<(pos%8)))) {
			for (i=3*n; i<up; i+=(n<<1)) {
				pos = ((i-3)>>1)+3;
				primes[pos>>3]|=(1<<(pos%8)); } } }
	return primes; }

void testpc2(char *primes, long long int up) {
	/* for random value primality test, slightly
	 * slower in avg than with previous array types
	 * due to extra 3 operations to find position
	 * plus 1 test to discard even values > 2.
	 * slightly surprising since that test should
	 * speed up test for even values > 2 a lot. */
	long long int i, cnt=0, pos;
	for (i=up>>1; i<up; i++) {
		if (i==2) cnt++;
		if (!(i%2)) continue;
		pos = ((i-3)>>1)+3;
		if (!(primes[pos>>3]&(1<<(pos%8))))
			cnt++; } }

int main() {
	long long int up;
	int *p1;
	char *p2, *p3;
	time_t t1, t2, t3, t4, t5, t6, t7, r;
	up = 3e7;
	t1 = clock();
	p1 = primesieve1(up);
	t2 = clock();
	testpi(p1, up);
	t3 = clock();
	p2 = primesieve2(up);
	t4 = clock();
	testpc(p2, up);
	t5 = clock();
	p3 = primesieve3(up);
	t6 = clock();
	testpc2(p3, up);
	t7 = clock();
	r = 1e6;
	free(p1);
	free(p2);
	free(p3);
	printf("p1: %d.%ds\n", (t2-t1)/r, (t2-t1)%r);
	printf("t1: %d.%ds\n", (t3-t2)/r, (t3-t2)%r);
	printf("p2: %d.%ds\n", (t4-t3)/r, (t4-t3)%r);
	printf("t2: %d.%ds\n", (t5-t4)/r, (t5-t4)%r);
	printf("p3: %d.%ds\n", (t6-t5)/r, (t6-t5)%r);
	printf("p3: %d.%ds\n", (t7-t6)/r, (t7-t6)%r);
	return 0; }
