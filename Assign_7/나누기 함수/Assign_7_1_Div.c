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
	// 변수 선언부
	// 입력을 위한 변수
	int input;
	float price;
	float change;

	// 거슴돈을 구하기 위해서 여러가지 변수들을 추가로 사용해야합니다.
	int temp;
	int COIN[N_TYPE] = { HALF, QUARTER, DIME, NICKEL, PENNY };
	char* NAME_COIN[N_TYPE] = { "HALF", "QUARTER", "DIME", "NICKEL", "PENNY" };
	int chg[N_TYPE];

	// 사용자 입력부
	printf("투입할 금액은 얼마? (단위: 달러) >> ");
	scanf_s("%d", &input);
	printf("음료 가격은 얼마? (단위: 달러) ");
	do {
		printf("(투입: $%d) >> ", input);
		scanf_s("%f", &price);
	} while (input < price);

	// 연산부
	change = input - price;
	temp = change * 100;
	for (int i = 0; i < N_TYPE; i++) {
		int* result = myDiv0(temp, COIN[i]);

		chg[i] = result[0];
		temp = result[1];

		free(result);
	}

	// 출력부
	printf("투입 금액: $%d\n", input);
	printf("음료 가격: $%.2f\n", price);
	printf("\n거스름돈: $%.2f", change);
	for (int i = 0; i < N_TYPE; i++) {
		printf("\n\t %s 개수: %d", NAME_COIN[i], chg[i]);
	}
	printf("\n");

	// 종료부
	system("pause");
	return 0;
}


int* myDiv0(int dividend, int divisor) {	// a ÷ b = c ... d
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