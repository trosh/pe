#include <stdio.h>

#define UP 10000

int main() {
	int i, j, n, k, d=0, pns[UP*3/2];
	i = UP*3/2;
	//printf("%d\n", i*(3*i-1)/2);
	char flag;
	for (i=1; i<UP*3/2; i++)
		pns[i] = i*(3*i-1)/2;
	for (i=1; i<UP; i++)
		for (j=1; j<i; j++) {
			n = pns[i]+pns[j];
			flag = 0;
			for (k=1; k<UP*3/2; k++) {
				if (pns[k]==n) { flag = 1; break; }
				if (pns[k]>n) break; }
			if (!flag) continue;
			n = pns[i]-pns[j];
			flag = 0;
			for (k=1; k<UP*3/2; k++) {
				if (pns[k]==n) { flag = 1; break; }
				if (pns[k]>n) break; }
			if (flag) printf("%d,%d\n", i, j);
			if (flag && (d==0 || n<d)) d=n; }
	printf("%d\n", d);
}
