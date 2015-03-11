#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000000

int main() {
	char *sieve;
	int i, j, m, n, prime, diag;
	sieve = (char*)calloc(MAX/2, 1);
	puts("calloc'd");
	m = 0;
	for (i=0; i<MAX/2; i++) {
		if (i==m*m && m < 1000) {
			printf("%d..", i);
			fflush(stdout);
			m++;
		}
		if (sieve[i] == 0)
			for (j=i*3+3; j<MAX/2; j+=i*2+3)
				sieve[j] = 1;
	}
	puts("\nprime init");
	m = 2;
	n = 1;
	prime = 0;
	diag = 1;
	while (n<MAX) {
		for (i=0; i<4; i++) {
			n += m;
			if (n%2 && sieve[(n-3)/2] == 0)
				prime++;
		}
		diag += 4;
		if (10*prime < diag) {
			printf("sidelength: %d\n", m+1);
			goto end;
		}
		m += 2;
	}
	puts("n MAX'd");
end:
	free(sieve);
	return 0;
}
