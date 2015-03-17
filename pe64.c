#include <stdio.h>
#include <time.h>

int main() {
	struct timespec tp1, tp2;
	int sq, rt, num, den, out, tmp, fac,
		i, j, savnum, savden, cnt;
	clock_gettime(CLOCK_REALTIME, &tp1);
	rt = 1;
	cnt = 0;
	for (sq=2; sq<10000; sq++) {
		if ((rt+1)*(rt+1) == sq) {
			rt++;
			continue;
		}
		num = 1;
		den = -rt;
		for (i=0 ;; i++) {
			fac = num;
			num = -den;
			den = sq-den*den;
			den /= fac;
			if (i==0) {
				savnum = num;
				savden = den;
			} else if (savnum == num
			        && savden == den) {
				if (i%2) cnt++;
				break;
			}
			out = 0;
			while (num-den >= -rt) {
				out++;
				num -= den;
			}
			tmp = den;
			den = num;
			num = tmp;
		}
	}
	printf("%d continued fractions with odd period "
	       "for N < %d\n", cnt, sq);
	clock_gettime(CLOCK_REALTIME, &tp2);
	printf("time: %gs\n",
		tp2.tv_sec-tp1.tv_sec+(tp2.tv_nsec-tp1.tv_nsec)/1e9);
	return 0;
}
