#include <stdio.h>

#define TRUE 1
#define FALSE 0
int main() {
	int num, ub;
	int isPrime = TRUE;

	printf("소수인지 판별할 양의 정수를 입력하세요 ");
	do {
		printf("(2이상 자연수) >> ");
		scanf_s("%d", &num);
	} while (num < 2);

	ub = num / 2; // 나뉘지는 값
	for (int i = 2; i < ub; i++) {
		if (num % i == 0) {
			isPrime = FALSE;	//	bool 사용 금지	--> if-else 밖에 없다
								//					--> 0|1 의 경우, 정수 형태로 사칙연산에 재활용이 가능하다.
			break;
		}
	}

	printf("입력하신 %d는 소수%s니다.\n", num, isPrime ? "입" : "가 아닙");

	system("pause");
	return 0;
}