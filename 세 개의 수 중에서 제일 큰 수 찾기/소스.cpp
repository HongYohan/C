#include <stdio.h>

int main() {
	int num1,num2,num3;
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("�Է¹��� 3���� ����(%d,%d,%d)�� ",num1,num2,num3);

	// num1�� num2,num3�� ũ�� ��
	if (num1 > num2 && num1 > num3) {
		printf("���� ū ���ڴ� %d", num1);
	}
	else if (num2 > num1 && num2 > num3) {
		printf("���� ū ���ڴ� %d", num2);
	}
	else {
		printf("���� ū ���ڴ� %d", num3);
	}
}