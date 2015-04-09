#include <stdio.h>

int main() {
	int i, j, n, c, cc, s, prev[60],
		fact[10]={1,1,2,6,24,120,720,5040,40320,362880};
	cc = 0;
	for (i=1; i<1000000; i++) {
		j = i;
		c = 1;
		while (c<=60) {
			s = 0;
			while (j) {
				n = j%10;
				s += fact[n];
				j /= 10;
			}
			for (n=0; n<c; n++)
				if (prev[n] == s)
					goto lbl1;
			prev[c++] = j = s;
		}
		lbl1:;
		if (c == 60)
			cc++;
	}
	printf("%d\n", cc);
	return 0;
}
