#include <stdio.h>
#include <stdlib.h>

char isperm(int a, int b) {
	char ad[7], bd[7];
	int and, bnd, i, j, la, lb;
	for (and=0; a; and++) {
		ad[and] = a%10;
		a /= 10;
	}
	for (bnd=0; b; bnd++) {
		bd[bnd] = b%10;
		b /= 10;
	}
	if (and != bnd) return 0;
	/* SORT AD & BD & CHECK */
	for (i=0; i<and; i++) {
		la = i;
		lb = i;
		for (j=i+1; j<and; j++) {
			if (ad[j]>ad[la]) la = j;
			if (bd[j]>bd[lb]) lb = j;
		}
		if (la != i) {
			j = ad[la];
			ad[la] = ad[i];
			ad[i] = j;
		}
		if (lb != i) {
			j = bd[lb];
			bd[lb] = bd[i];
			bd[i] = j;
		}
		if (ad[i] != bd[i]) return 0;
	}
	return 1;
}

int main() {
	int p, t, r, s, bestp;
	float ratio = -1;
	char *q;
	for (p=2; p<1e7; p++) {
		t = 1;
		q = (char*)calloc(p, 1);
		for (r=2; r<p; r++) {
			if (q[r]) continue;
			if (p%r) t++;
			else for (s=2*r; s<p; s+=r) q[s] = 1;
		}
		free(q);
		if (isperm(p, t)) {
			if (ratio == -1)    ratio = 1.*p/t;
			if (1.*p/t < ratio) {
				ratio = 1.*p/t;
				bestp = p;
				printf("%d %d\n", p, t);
			}
		}
	}
	printf("bestp = %d\n", bestp);
	return 0;
}
