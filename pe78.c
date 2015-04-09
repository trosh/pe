#include <stdio.h>

/* PROJECT EULER PROBLEM NUMBER 78
 * ===============================
 * Let p(n) represent the number of different ways in which
 * n coins can be separated into piles.
 * For example, five coins can separated into piles in exactly
 * seven different ways, so p(5)=7.
 * OOOOO
 * OOOO   O
 * OOO   OO
 * OOO   O   O
 * OO   OO   O
 * OO   O   O   O
 * O   O   O   O   O
 * Find the least value of n for which p(n) is divisible
 * by one million.
 */

#define VAL 5

int main() {
	// THIS IS PE76. NEEDS MUCH CHANGE FROM WITHIN.
	// NEEDS TO LOOP OVER VALUES !!!!! CX++++ OMG.
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
