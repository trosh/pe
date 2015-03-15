#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned long long n, i, j, cubsz;
	char *cubes, *currcub, *currcub2,
		nd, mnd, *nds, k, l, cnt, temp;
	cubsz = (1<<14);
	mnd = 15; // MAX NUM DIGITS
	cubes = (char*)malloc(cubsz*mnd);
	nds = (char*)malloc(cubsz);
	currcub = cubes;
	for (i=0; i<cubsz; i++) {
		n = i*i*i;
		currcub += mnd;
		for (nd=0; n; nd++) {
			currcub[nd] = n%10;
			n /= 10;
		}
		nds[i] = nd;
		// BADSORT
		for (k=0; k<nd; k++) {
			cnt = k;
			for (l=k+1; l<nd; l++)
				if (currcub[l] < currcub[cnt])
					cnt = l;
			if (cnt != k) {
				temp         = currcub[k];
				currcub[k]   = currcub[cnt];
				currcub[cnt] = temp;
			}
		}
	}
	for (i=0; i<cubsz; i++) {
		cnt = 1;
		nd = nds[i];
		currcub = cubes+mnd*i;
		for (j=i+1; j<cubsz; j++) {
			if (nd != nds[j])
				break;
			currcub2 = cubes+mnd*j;
			for (k=0; k<nd; k++)
				if (currcub[k] != currcub2[k])
					goto notfound;
			cnt++;
			if (cnt==5) {
				printf("%ld\n", i*i*i);
				goto stop;
			}
			notfound:;
		}
	}
	stop:;
	free(nds);
	free(cubes);
	return 0;
}
