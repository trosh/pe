#include <stdio.h>

int main() {
	FILE *f;
	char p[150], digits[100], ds, a, b, c;
	int i;
	f = fopen("pe79_keylog.txt", "r");
	for (i=0; i<150; i+=3) {
		fread(p+i, 3, 1, f);
		fseek(f, 1, SEEK_CUR);
	}
	fclose(f);
	digits[0] = '0';
	for (ds=0; ds<100; ) {
		for (i=0; i<=ds&&digits[i]=='9'; i++) {
			digits[i] = '0';
			if (i==ds) {
				digits[++ds] = '1';
				goto lbl0;
			}
		}
		digits[i]++;
		if (i) continue;
		lbl0:;
		for (a=0; a<150; a+=3) {
			c = 0;
			for (b=ds; b>=0; b--)
				if (p[a+c] == digits[b])
					if ((c++)==2)
						goto lbl1;
			goto lbl2;
			lbl1:;
		}
		for (i=ds; i>=0; i--)
			putchar(digits[i]);
		putchar('\n');
		return 0;
		lbl2:;
		if (a>50) {
			for (i=ds; i>=0; i--)
				putchar(digits[i]);
			printf(" %c%c%c\n", p[a], p[a+1], p[a+2]);
		}
	}
	return 1;
}
