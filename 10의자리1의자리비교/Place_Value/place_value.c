#include <stdio.h>
#include "all.h"

void main() {
	int x;
	for (;;) {
		printf("2�ڸ� ���� �Է�(10~99, ���� : 0) >> ");
		scanf_s("%d", &x);
		if (x == 0) {
			break;
		}

		if (x < 10||x>=100) {
			printf("10~99 ������ ������ �Է��ϼ���.\n");
		}
		else {
			place_value(x);
		}
	}
}