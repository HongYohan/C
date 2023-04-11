#include <stdio.h>
/*
struct mix {
	int score_eng;
	char name[3];
	int score_kor;
	float avg;
}s;

int main() {
	s.score_eng = 90;
	printf("%d", s.score_eng);
}

int main() {
	struct mix* p;
	p = &s;
	p->score_eng = 90;
	printf("%d", p->score_eng);
}

union student {
	int tot;
	char grade;
};

int main() {
	union student a;
	a.tot = 300;
	printf("%d", a.tot);
}*/

enum week 
{
	sun, mon, tue, wed,
	thu,fri,sat
};

int main() {
	enum week ww;
	ww = sat;
	printf("%d", ww);
}