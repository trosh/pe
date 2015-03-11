#include <stdio.h>

char ispal(int n, char b) {
	/* shits only ok since n < 1e6 */
	int m = n;
	char a[20], i=0, j;
	while (n > 0) {
		a[i] = n%b;
		n /= b;
		i += 1;
	}
	for (j=0; j<i/2; j++)
		if (a[j] != a[i-j-1])
			return 0;
	return 1;
}

int main() {
	int sum = 0, i;
	for (i=1; i<1e6; i+=2)
		if (ispal(i, 10) && ispal(i, 2))
			sum += i;
	printf("%d\n", sum);
	return 0;
}
