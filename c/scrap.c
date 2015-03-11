#include <stdio.h>

int main() {
	char a = 49;
	int b = (int)(a-48);
	printf("%d\n", b+1);
	double c = 1e5;
	c *= 1e5;
	printf("%d\n", c);
	int d = 4;
	printf("%d %d\n", d>>2, d);
	printf("%d\n", 0||12);
	return 0;
}
