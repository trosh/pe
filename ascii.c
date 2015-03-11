#include <stdio.h>

int main() {
	char i;
	for (i=20; i<127; i++)
		printf("%d-%c  ", i, i);
	printf("\n%d-space\n", ' ');
	printf("65 XOR 42 = %d\n", 65 ^ 42);
	return 0;
}
