#include <stdio.h>

int tonumber(char a) {
	if (a<48||a>57) return -1;
	return (int)(a-48);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("need problem number\n");
		return 1;
	}
	switch (tonumber(argv[1][0])) {
		case -1:
			printf("NaN\n");
			break;
		case 1:
			printf("prout\n");
			break;
		case 2:
			int a=1, b=2, c, sum=2;
			while (1) {
				c = a+b;
				if (c>4e6)
					break;
				if (c%2==0)
					sum += c;
				a = b;
				b = c;
			}
			printf("%d\n", sum);
			break;
	}
	return 0;
}
