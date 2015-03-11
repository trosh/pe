#include <stdio.h>

inline long long ispal(long long n) {
	char digits[20];
	int i, j;
	for (i=0; n; i++) {
		digits[i] = n % 10;
		n /= 10;
	}
	i--;
	for (j=i; j>=0; j--)
		if (digits[j]!=digits[i-j])
			return 0;
	return 1;
}

inline long long rev(long long n) {
	long long m = 0;
	while (n) {
		m *= 10;
		m += n%10;
		n /= 10;
	}
	return m;
}

int main() {
	int itercnt, lychrelcnt;
	long long i, j;
	for (i=0; i<10000; i++) {
		j = i+rev(i);
		printf("%ld + %ld\n", i, rev(i));
		for (itercnt=1; itercnt<50; itercnt++) {
			if (ispal(j))
				goto lbl0;
			j += rev(j);
			printf("%ld + %ld\n", j, rev(j));
		}
		lychrelcnt++;
		lbl0:;
		puts("#######");
	}
	printf("Lychrel numbers < 10000 count: %d\n", lychrelcnt);
	return 0;
}
