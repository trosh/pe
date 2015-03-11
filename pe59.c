#include <stdio.h>
#include <stdlib.h>

int main() {
	char *cipher, *cip, c, a, i, j, k, key[3];
	int csize, ccap, l, badcnt, sum;
	FILE *f;
	f = fopen("pe59_cipher.txt", "r");
	if (f == NULL) {
		puts("cannot open pe59_cipher.txt");
		return 1;
	}
	csize = 0;
	ccap = 128;
	cipher = (char*)malloc(ccap);
	a = 0;
	while (1) {
		c = fgetc(f);
		if (c == ',') {
			if (csize == ccap)
				cipher = (char*)realloc(cipher, ccap*=2);
			cipher[csize++] = a;
			a = 0;
			continue;
		}
		if (c == EOF) {
			if (csize == ccap)
				cipher = (char*)realloc(cipher, ccap*=2);
			cipher[csize++] = a;
			break;
		}
		if (c==10) continue;
		a *= 10;
		a += c-'0';
	}
	printf("csize=%d\n", csize);
	cip = (char*)malloc(csize+1);
	cip[csize] = 0;
	for (key[0]='a'; key[0]<='z'; key[0]++)
	for (key[1]='a'; key[1]<='z'; key[1]++)
	for (key[2]='a'; key[2]<='z'; key[2]++) {
		badcnt = 0;
		sum = 0;
		for (l=0; l<csize; l++) {
			c = cipher[l] ^ key[l%3];
			cip[l] = c;
			if ((c < 'a' || c > 'z')
			 && (c < 'A' || c > 'Z')
			 && (c < '0' || c > '9')
			 && c != ' ' && c != '.'
			 && c != ',' && c != '-'
			 && c != '(' && c != ')'
			 && c != '!' && c != '?') {
				badcnt++;
				if (badcnt > 15)
					goto bad;
			}
			sum += c;
		}
		puts(cip);
		printf("sum = %d\n", sum);
		bad:;
	}
	return 0;
}
