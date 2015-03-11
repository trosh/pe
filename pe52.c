#include <stdio.h>



int main() {
	int i, j, k, l, m, n, o, nd, pot;
	char digits[10], digits2[10];
	nd = 1;
	pot = 10;
	for (i=1 ;; i++) {
		if (i==pot) {
			nd++;
			pot *= 10;
		}
		j = i;
		for (k=0; j; k++) {
			for (m=0; m<k; m++)
				if (digits[m] > j%10) {
					for (n=k; n>m; n--)
						digits[n] = digits[n-1];
					digits[m] = j%10;
					goto lbl0;
				}
			digits[k] = j%10;
			lbl0: j/=10;
		}
		l = i;
		for (o=2; o<7; o++) {
			l += i;
			j = l;
			for (k=0; j; k++) {
				for (m=0; m<k; m++)
					if (digits2[m] > j%10) {
						for (n=k; n>m; n--)
							digits2[n] = digits2[n-1];
						digits2[m] = j%10;
						goto lbl1;
					}
				digits2[k] = j%10;
				lbl1: j/=10;
			}
			for (k=0; k<nd; k++)
				if (digits[k] != digits2[k]) goto lbl2;
		}
		printf("%d %d\n", i, l);
		return 0;
		lbl2:;
	}
	return 0;
}
