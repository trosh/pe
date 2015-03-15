#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main() {
	struct timespec tp1, tp2;
	signed long int nd, j, cnt, i;
	mpz_t low, upp, n;
	clock_gettime(CLOCK_REALTIME, &tp1);
	mpz_init_set_si(low, 1);
	mpz_init_set_si(upp, 10);
	mpz_init(n);
	cnt = 0;
	for (nd=1; nd<24; nd++) {
		for (i=0 ;; i++) {
			mpz_set_si(n, i);
			for (j=1; j<nd; j++)
				mpz_mul_si(n, n, i);
			if (mpz_cmp(n, low) <  0) continue;
			if (mpz_cmp(n, upp) >= 0) break;
			//printf("%ld %d %ld\n", i, nd, n);
			cnt++;
		}
		mpz_mul_si(low, low, 10);
		mpz_mul_si(upp, upp, 10);
	}
	printf("cnt = %d\n", cnt);
	clock_gettime(CLOCK_REALTIME_COARSE, &tp2);
	printf("time: %lgs\n", (1.*tp1.tv_nsec-tp2.tv_nsec)/1e9);
	return 0;
}
