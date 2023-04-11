#include <stdio.h>	// scanf, printf�� ����� �� �ְ� �մϴ�.

#define N_TYPE	5
#define HALF	50
#define QUARTER	25
#define DIME	10
#define NICKEL	 5
#define PENNY	 1

int main() {
	// ���� �����
	// �Է��� ���� ����
	int input;
	float price;
	float change;

	// �Ž����� ���ϱ� ���ؼ� �������� �������� �߰��� ����ؾ��մϴ�.
	int temp;
	int COIN[N_TYPE] = { HALF, QUARTER, DIME, NICKEL, PENNY };
	char* NAME_COIN[N_TYPE] = { "HALF", "QUARTER", "DIME", "NICKEL", "PENNY" };
	int chg[N_TYPE];

	// ����� �Էº�
	printf("������ �ݾ��� ��? (����: �޷�) >> ");
	scanf_s("%d", &input);
	printf("���� ������ ��? (����: �޷�) ");
	do {
		printf("(����: $%d) >> ", input);
		scanf_s("%f", &price);
	} while (input < price);

	// �����
	change = input - price;
	temp = change * 100;
	for (int i = 0; i < N_TYPE; i++) {
		chg[i] = temp / COIN[i];
		temp %= COIN[i];
	}

	// ��º�
	printf("���� �ݾ�: $%d\n", input);
	printf("���� ����: $%.2f\n", price);
	printf("\n�Ž�����: $%.2f", change);
	for (int i = 0; i < N_TYPE; i++) {
		printf("\n\t %s ����: %d", NAME_COIN[i], chg[i]);
	}
	printf("\n");

	// �����
	system("pause");
	return 0;
}