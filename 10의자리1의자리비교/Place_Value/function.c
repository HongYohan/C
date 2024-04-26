#include <stdio.h>


void place_value(int i) {
	int a = i / 10;
	int b = i % 10;

	if (a == b) {
		printf("10의 자리와 1의 자리가 같습니다.\n");
	}
	else {
		printf("10의 자리와 1의 자리가 다릅니다.\n");
	}
}