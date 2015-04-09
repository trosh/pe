#include <stdio.h>

/* PROJECT EULER PROBLEM NUMBER 76
 * ===============================
 * It is possible to write five as a sum in exactly
 * six different ways:
 *     4 + 1
 *     3 + 2
 *     3 + 1 + 1
 *     2 + 2 + 1
 *     2 + 1 + 1 + 1
 *     1 + 1 + 1 + 1 + 1
 * How many different ways can one hundred be written
 * as a sum of at least two positive integers?
 */

#define VAL 100

int main() {
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
