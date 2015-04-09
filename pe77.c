#include <stdio.h>

/*
 * It is possible to write ten as the sum of primes in exactly
 * five different ways:
 *     7 + 3
 *     5 + 5
 *     5 + 3 + 2
 *     3 + 3 + 2 + 2
 *     2 + 2 + 2 + 2 + 2
 * What is the first value which can be written
 * as the sum of primes in over five thousand different ways?
 */

#define VAL 5

int main() {
	// THIS IS PE76. NEEDS MUCH CHANGE FROM WITHIN.
	int m[1000], i, j, s, cnt;
	i = 0;
	m[0] = VAL;
	cnt = 0;
	while (m[0]>1) {
		if (m[i]==1) {
			i--;
		} else {
			s = 0;
			for (j=0; j<=i; j++)
				s += m[j];
			s--;
			m[i]--;
			for (j=i+1 ;; j++)
				if (VAL-s <= m[j-1]) {
					m[j] = VAL-s;
					break;
				} else {
					m[j] = m[j-1];
					s += m[j];
				}
			i = j;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
