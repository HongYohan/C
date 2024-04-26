#include <stdio.h>
#include "Function.h"

void main() {
	int a;
	printf("정수 입력 : ");
	scanf_s("%d", &a);

	printf("결과 = ");
	DecToBin(a);
}