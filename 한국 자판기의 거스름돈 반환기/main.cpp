#include <stdio.h>

int main() {
	//num1���ٰ� ���� ����
	int num1;
	printf("������ �ݾ�(��):"); //���ڸ� �Է¹���
	scanf_s("%d", &num1); //�Է¹��� ���ڸ� ������� num1������ �Է�

	printf("������ ������ 600�� �Դϴ�.\n"); 

	int price1;
	price1 = 600; //price1�� ���� ���� ����

	printf("�Ž��� �� : %d��", num1 - price1); //�Ž������� ǥ��
	return 0;
}