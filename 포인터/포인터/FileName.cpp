#include <stdio.h>

#define SIZE 5

int main() {
	int x[SIZE];
	int* px = x;
	for (int i = 0; i < SIZE; i++) {
		printf("%d��° �� �Է�: ", (i+1));
		scanf_s("%d", &(*(px+i))); // ���ٹ��� ���� ����
	}

	int a = *(px + 0);
	for (int i = 0; i < SIZE; i++) {
		if (a <= *(px + i)) {
			a = *(px + i);
		}
	}

	int b = *(px + 0);
	for (int i = 0; i < SIZE; i++) {
		if (b > *(px + i)) {
			b = *(px + i);
		}
	}

	printf("%d", (a + b));

	return 0;
}