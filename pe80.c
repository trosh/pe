#include <stdio.h>

int main() {
	char d[101]={0,1,4,1,4,2,1}, s[101], i=6, j, k, a, b;
	// ASSUME D[0] == 0
	s[i] = 0;
	for (j=i; j>0; j--) {
		a = s[j];
		for (k=i; k>0; k--) {
			b = a*s[k];
			s[j] += a%10;
			s[j-1] = a/10;
		}
	}
	for (j=0; j<=i; j++)
		putchar(s[j]+'0');
	putchar('\n');
	return 0;
}
