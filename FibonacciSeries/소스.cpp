#include <stdio.h>

int main() {
	int num;
	printf("�� ��° ������ �Ǻ���ġ ���� Ȯ���Ұ��ΰ� : ");
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