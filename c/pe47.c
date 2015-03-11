#include <stdio.h> // printf()

int factors(int n) {
	int i, cnt=0;
	for (i=2; n!=1; i++)
		if (!(n%i)) {
			cnt++;
			while (!(n%i)) n/=i; }
	return cnt; }

int main(int argc, char *argv[]) {
	int n, i, l;
	for (n=1e3 ;; n++) {
		i = factors(n);
		if (i == 4) l++;
		else { l = 0; continue; }
		if (l == 4) {
			printf("%d\n", n-3);
			return; } }
	return 0; }
