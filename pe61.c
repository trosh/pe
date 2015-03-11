#include <stdio.h>
#include <stdlib.h>

int *polys[6], caps[6], sizes[6];

void inipolys() {
	int d, i, n;
	for (d=0; d<6; d++) {
		caps[d] = 128;
		sizes[d] = 0;
		polys[d] = (int*)malloc(caps[d]*sizeof(int));
		for (i=1 ;; i++) {
			n = (i*i*(d+1)-i*(d-1))/2;
			if (n>=10000) break;
			if (n>1000) {
				if (sizes[d]==caps[d])
					polys[d] = (int*)
						realloc(polys[d], (caps[d]*=2)*sizeof(int));
				polys[d][sizes[d]++] = n;
			}
		}
	}
}

int main() {
	char a, b, c, d, e, f, i, j, D;
	int t[6], popd[6], popdsav[6][6];
	inipolys();
	for (a=10; a<sizes[0]; a++) {
		t[0] = polys[0][a];
	for (b=10; b<sizes[1]; b++) {
		t[1] = polys[1][b];
		if (t[1]==t[0]) continue;
	for (c=10; c<sizes[2]; c++) {
		t[2] = polys[2][c];
		if (t[2]==t[0] || t[2]==t[1]) continue;
	for (d=10; d<100; d++) {
		t[2] = 100*c+d;
		if (!isapoly(t[2])) continue;
	for (e=10; e<100; e++) {
		t[3] = 100*d+e;
		if (t[3]==t[0] || t[3]==t[1]
		 || t[3]==t[2]) continue;
		if (!isapoly(t[3])) continue;
	for (f=10; f<100; f++) {
		t[4] = 100*e+f;
		t[5] = 100*f+a;
		if (!isapoly(t[4])) continue;
		if (!isapoly(t[5])) continue;
		printf("%d %d %d %d %d %d\n",
				t[0], t[1], t[2], t[3], t[4], t[5]);
		if (t[4]==t[0] || t[4]==t[1]
		 || t[4]==t[2] || t[4]==t[3]
		 || t[5]==t[0] || t[5]==t[1]
		 || t[5]==t[2] || t[5]==t[3]
		 || t[5]==t[4]) continue;
		for (j=0; j<6; j++)
		// XXX XXX XXX XXX
		// TODO FLIP ALGO AROUND
		// XXX XXX XXX XXX
			popd[j] = 1;
		for (D=0; D<6; D++) {
			for (i=0; i<sizes[D]; i++)
				for (j=0; j<6; j++)
					if (popd[j] && t[j]==polys[D][i]) {
						popd[j] = 0;
						goto foundpoly;
					}
			goto badset;
			foundpoly:;
		}
		printf("good set : %d %d %d %d %d %d\n",
				t[0], t[1], t[2], t[3], t[4], t[5]);
		goto stop;
		badset:;
	} } } } }
	stop:;
	for (i=0; i<6; i++)
		free(polys[i]);
	return 0;
}
