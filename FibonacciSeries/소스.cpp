#include <stdio.h>

int main() {
	int num;
	printf("몇 번째 까지의 피보나치 수를 확인할것인가 : ");
	scanf_s("%d", &num);
	
	int result = 1;
	int result1 = 1;
	int final = 0;

	for (int i = 1; i <= num; i++) {
		printf("%d\n", result);
		final=result+result1;
		result = result1;
		result1 = final;
	}
}