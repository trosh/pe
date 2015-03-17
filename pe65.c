#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#define CONV 100

int main() {
	struct timespec tp1, tp2;
	int i, k, sum;
	unsigned long terms[CONV];
	mpz_t num, den, tmp, mod;
	clock_gettime(CLOCK_REALTIME, &tp1);
	mpz_init(num);
	mpz_init(den);
	mpz_init(mod);
	mpz_init(tmp);
	///////////////
	k = 0;
	terms[0] = 2;
	for (i=1; i<CONV; i++)
		terms[i] = i%3==2 ? k+=2 : 1;
	mpz_set_ui(num, 1);
	mpz_set_ui(den, terms[CONV-1]);
	for (i=CONV-2; i>=0; i--) {
		mpz_addmul_ui(num, den, terms[i]);
		mpz_set(tmp, num);
		mpz_set(num, den);
		mpz_set(den, tmp);
	}
	mpz_set(num, den); // JUST FOR CLARITY
	sum = 0;
	while (mpz_cmp_ui(num, 0)>0) {
		mpz_tdiv_qr_ui(num, mod, num, 10);
		sum += mpz_get_ui(mod);
	}
	printf("sum = %d\n", sum);
	mpz_clear(num);
	mpz_clear(den);
	mpz_clear(mod);
	///////////////
	clock_gettime(CLOCK_REALTIME, &tp2);
	printf("time: %gs\n",
		tp2.tv_sec-tp1.tv_sec+(tp2.tv_nsec-tp1.tv_nsec)/1e9);
	return 0;
}
