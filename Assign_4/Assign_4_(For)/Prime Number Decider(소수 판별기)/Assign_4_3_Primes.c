#include <stdio.h>

#define TRUE 1
#define FALSE 0
int main() {
	int num, ub;
	int isPrime = TRUE;

	printf("�Ҽ����� �Ǻ��� ���� ������ �Է��ϼ��� ");
	do {
		printf("(2�̻� �ڿ���) >> ");
		scanf_s("%d", &num);
	} while (num < 2);

	ub = num / 2; // �������� ��
	for (int i = 2; i < ub; i++) {
		if (num % i == 0) {
			isPrime = FALSE;	//	bool ��� ����	--> if-else �ۿ� ����
								//					--> 0|1 �� ���, ���� ���·� ��Ģ���꿡 ��Ȱ���� �����ϴ�.
			break;
		}
	}

	printf("�Է��Ͻ� %d�� �Ҽ�%s�ϴ�.\n", num, isPrime ? "��" : "�� �ƴ�");

	system("pause");
	return 0;
}