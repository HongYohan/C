#include <stdio.h>


void place_value(int i) {
	int a = i / 10;
	int b = i % 10;

	if (a == b) {
		printf("10�� �ڸ��� 1�� �ڸ��� �����ϴ�.\n");
	}
	else {
		printf("10�� �ڸ��� 1�� �ڸ��� �ٸ��ϴ�.\n");
	}
}