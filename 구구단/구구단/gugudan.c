#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 void gugudan() {

	srand(time(NULL));
	
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		a[i] = (rand() % 9)+1;
	}
	int b[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		b[i] = (rand() % 9)+1;
	}
	int c[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		printf("\n%d: %d*%d=? ", i + 1, a[i], b[i]);
	}
	int x = 9;
	int y = 4;
	int d[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		gotoxy(x, y);
		c[i] = a[i] * b[i];
		scanf_s("%d", &d[i]);
		y++;
	}
	for (int i = 0; i < 10; i++) {
		if (c[i] == d[i]) {
			gotoxy(x +4, y-10);
			printf("O");
		}

		else {
			gotoxy(x + 4, y-10);
			printf("X Á¤´ä : %d", c[i]);
		}
		y++;
	}
	
 }