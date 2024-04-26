#include <stdio.h>
#include "sampleFunction.h" // 헤더 파일 호출


void main() {
	int a, b;
	printf("두 수 입력 : ");
	scanf_s("%d %d", &a, &b);

	printf("두 수의 덧셈 = %d\n",plus(a, b)); // 함수호출
	printf("두 수의 뺄셈 = %d\n", minus(a, b)); // 함수호출
}