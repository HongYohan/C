#include <stdio.h>
#include <stdlib.h>

int* myDiv0(int dividend, int divisor);
// void myDiv1(int divident, int divisor, int* result);
// void myDiv2(int divident, int divisor, int* quotient, int* remainder);

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
		int* result = myDiv0(temp, COIN[i]);

		chg[i] = result[0];
		temp = result[1];

		free(result);
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


int* myDiv0(int dividend, int divisor) {	// a �� b = c ... d
	int* result = (int*)malloc(sizeof(int) * 2);

	result[0] = dividend / divisor;
	result[1] = dividend % divisor;

	return result;
}

/*
void myDiv1(int dividend, int divisor, int* result) {
	*result       = dividend / divisor;
	*(result + 1) = dividend % divisor;
}

void myDiv2(int dividend, int divisor, int* quotient, int* remainder) {
	*quotient  = dividend / divisor;
	*remainder = dividend % divisor;
}
*/