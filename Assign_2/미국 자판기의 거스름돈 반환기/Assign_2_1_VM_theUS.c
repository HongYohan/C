#include <stdio.h>	// scanf, printf�� ����� �� �ְ� �մϴ�.

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
	int chgHd, chgQt, chgDm, chgNk, chgPn;

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

	chgHd = temp / HALF;
	temp %= HALF;

	chgQt = temp / QUARTER;
	temp %= QUARTER;

	chgDm = temp / DIME;
	temp %= DIME;

	chgNk = temp / NICKEL;
	temp %= NICKEL;

	chgPn = temp / PENNY;
	temp %= PENNY;

	// ��º�
	printf("���� �ݾ�: $%d\n", input);
	printf("���� ����: $%.2f\n", price);
	printf("\n�Ž�����: $%.2f", change);

	printf("\n\tHalf Dollar ����: %d", chgHd);
	printf("\n\tQuarter ����: %d", chgQt);
	printf("\n\tDime ����: %d", chgDm);
	printf("\n\tNickel ����: %d", chgNk);
	printf("\n\tPenny ����: %d", chgPn);

	// �����
	return 0;
}