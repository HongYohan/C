#include <stdio.h>
#include "sampleFunction.h" // ��� ���� ȣ��


void main() {
	int a, b;
	printf("�� �� �Է� : ");
	scanf_s("%d %d", &a, &b);

	printf("�� ���� ���� = %d\n",plus(a, b)); // �Լ�ȣ��
	printf("�� ���� ���� = %d\n", minus(a, b)); // �Լ�ȣ��
}