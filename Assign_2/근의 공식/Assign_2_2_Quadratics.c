#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	double D;

	double mean, diff;

	printf("2차 방정식의 세 계수를 입력하세요 (입력 형식: 정수, 구분자: 스페이스) >> ");
	scanf_s("%d %d %d", &a, &b, &c);

	mean = -b / 2.0 / a;

	D = pow(b, 2.0) - 4 * a * c;
	diff = D < 0 ? -D : D;
	diff = sqrt(diff) / 2.0 / a;

	printf("입력하신 2차 방정식의 근은 %.2f±%.2f%c입니다.\n", mean, diff, (D < 0 ? 'i' : ' '));

	return 0;
}