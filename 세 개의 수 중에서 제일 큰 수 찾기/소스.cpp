#include <stdio.h>

int main() {
	int num1,num2,num3;
	printf("숫자를 입력하시오 : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("입력받은 3개의 숫자(%d,%d,%d)중 ",num1,num2,num3);

	// num1과 num2,num3의 크기 비교
	if (num1 > num2 && num1 > num3) {
		printf("가장 큰 숫자는 %d", num1);
	}
	else if (num2 > num1 && num2 > num3) {
		printf("가장 큰 숫자는 %d", num2);
	}
	else {
		printf("가장 큰 숫자는 %d", num3);
	}
}