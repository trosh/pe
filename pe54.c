#include <stdio.h>
#include <stdlib.h>

enum {
	highcard      = 0,
	onepair       = 1,
	twopairs      = 2,
	threeofakind  = 3,
	straight      = 4,
	flush         = 5,
	fullhouse     = 6,
	fourofakind   = 7,
	straightflush = 8,
	royalflush    = 9
};

typedef struct {
	char rank, hi1, hi2, hi3;
} hand;

char convertval(char i) {
	if (i >= '0'
	 && i <= '9') return i-'0';
	switch (i) {
		case 'T': return 10;
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
		case 'A': return 14;
	}
	return 0;
}

char convertsuit(char i) {
	switch (i) {
		case 'H': return 1;
		case 'D': return 2;
		case 'C': return 3;
		case 'S': return 4;
	}
	return 0;
}

hand score(char* p) {
	int i, j, l, t1, t2, numvals, vals[5], countvals[5];
	char suit, isflush;
	hand h;
	/* ORDER BY VALUE */
	for (i=0; i<10; i+=2) {
		l = i;
		for (j=i+2; j<10; j+=2)
			if (p[j] < p[l])
				l = j;
		if (l != i) {
			t1 = p[i  ];
			t2 = p[i+1];
			p[i  ] = p[l  ];
			p[i+1] = p[l+1];
			p[l  ] = t1;
			p[l+1] = t2;
		}
	}
	isflush = 1;
	suit = p[1];
	for (i=3; i<10; i+=2)
		if (p[i] != suit) {
			isflush = 0;
			break;
		}
	for (i=2; i<10; i+=2)
		if (p[i] != p[i-2]+1)
			goto notconsec;
	if (isflush) {
		if (p[0] == 10) {
			h.rank = royalflush;
			h.hi1 = 14;
			return h; /* ROYALFLUSH */
		}
		h.rank = straightflush;
		h.hi1 = p[9];
		return h; /* STRAIGHT FLUSH */
	}
	h.rank = straight;
	h.hi1 = p[9];
	return h; /* STRAIGHT */
	notconsec:;
	numvals = 0;
	vals[0] = 0;
	countvals[0] = 1;
	for (i=2; i<10; i+=2)
		if (p[i]==p[i-2])
			countvals[numvals]++;
		else {
			vals[++numvals] = i;
			countvals[numvals] = 1;
		}
	numvals++;
	for (i=0; i<numvals; i++)
		switch (countvals[i]) {
			case 4:
				h.rank = fourofakind;
				h.hi1 = p[vals[i]];
				h.hi2 = p[i?0:8];
				return h; /* FOUR OF A KIND */
			case 3:
				if (numvals == 2) {
					h.rank = fullhouse;
					h.hi1 = p[vals[i]];
					h.hi2 = p[vals[1-i]];
					return h; /* FULL HOUSE */
				}
				if (isflush) break;
				h.rank = threeofakind;
				h.hi1 = p[vals[i]];
				h.hi2 = 0;
				for (j=0; j<3; j++)
					if (i!=j && p[vals[j]]>h.hi2)
						h.hi2 = p[vals[j]];
				return h; /* THREE OF A KIND */
		}
	if (isflush) {
		h.rank = flush;
		h.hi1 = p[8];
		h.hi2 = p[6];
		h.hi3 = p[4];
		return h; /* FLUSH */
	}
	for (i=0; i<numvals; i++)
		if (countvals[i] == 2) {
			for (j=i+1; j<numvals; j++)
				if (countvals[j] == 2) {
					h.rank = twopairs;
					h.hi1 = p[vals[j]];
					h.hi2 = p[vals[i]];
					h.hi3 = i ? p[0] : j==1 ? p[6] : p[2];
					return h; /* TWO PAIRS */
				}
			h.rank = onepair;
			h.hi1 = p[vals[i]];
			h.hi2 = i==3 ? p[vals[2]] : p[vals[3]];
			return h; /* ONE PAIR */
		}
	h.rank = highcard;
	h.hi1 = p[8];
	h.hi2 = p[6];
	h.hi3 = p[4];
	return h; /* HIGH CARD */
}

int main() {
	FILE *f;
	char s[31], *p1, *p2;
	int i, j, cnt;
	hand h1, h2;
	p1 = (char*)malloc(10);
	p2 = (char*)malloc(10);
	f = fopen("pe54_poker.txt", "r");
	if (f==NULL) {
		puts("can't open pe54_poker.txt");
		return 1;
	}
	s[30] = 0;
	cnt = 0;
	while (fread(s, 1, 30, f)==30) {
		j = 0;
		for (i=0; i<10; i+=2) {
			p1[i]   = convertval( s[j]);
			p1[i+1] = convertsuit(s[j+1]);
			j += 3;
		}
		for (i=0; i<10; i+=2) {
			p2[i]   = convertval( s[j]);
			p2[i+1] = convertsuit(s[j+1]);
			j += 3;
		}
		h1 = score(p1);
		h2 = score(p2);
		if (h1.rank != h2.rank)    {if (h1.rank > h2.rank) cnt++;}
		else if (h1.hi1 != h2.hi1) {if (h1.hi1  > h2.hi1 ) cnt++;}
		else if (h1.hi2 != h2.hi2) {if (h1.hi2  > h2.hi2 ) cnt++;}
		else {
			fputs(s, stdout);
			if (h1.hi3  > h2.hi3 ) {
				puts("P1");
				cnt++;
			} else
				puts("P2");
		}
	}
	printf("PLAYER 1 WINS %d TIMES\n", cnt);
	return 0;
}
