#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int main() {
	uint64_t *squares, cf;
	uint32_t *l, i, lcnt, a, b, c;
	float cc;
	squares = (uint64_t*)calloc(800000, 8);
	l = (uint32_t*)calloc(1500001, 4);
	for (i=1; i*i<800000; i++)
		squares[i] = i*i;
	for (a=1; a<1500000; a++) {
		if (a%10000==0) {
			printf("%d..", a);
			fflush(stdout);
		}
		for (b=1; b<=a; b++) {
			cc = cf = a*a+b*b;;
			cc = sqrt(cc);
			if (cc>=800000) {
				printf("\n%g\n", cc);
				return 1;
			}
			c = cc;
			if (a+b+c>1500000) break;
			if (squares[c]==cf)
				l[a+b+c]++;
			else if (squares[++c]==cf)
				l[a+b+c]++;
		}
	}
	free(squares);
	putchar('\n');
	lcnt = 0;
	for (i=0; i<=1500000; i++) {
		if (l[i]==1)
			lcnt++;
		if (i<50 && l[i])
			printf("%d %d\n", i, l[i]);
	}
	printf("l[20]=%d\n", l[20]);
	printf("%d\n", lcnt);
	free(l);
	return 0;
}
