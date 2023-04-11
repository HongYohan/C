#include <stdio.h>	// scanf, printf를 사용할 수 있게 합니다.

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
	int chgHd, chgQt, chgDm, chgNk, chgPn;

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

	// 출력부
	printf("투입 금액: $%d\n", input);
	printf("음료 가격: $%.2f\n", price);
	printf("\n거스름돈: $%.2f", change);

	printf("\n\tHalf Dollar 개수: %d", chgHd);
	printf("\n\tQuarter 개수: %d", chgQt);
	printf("\n\tDime 개수: %d", chgDm);
	printf("\n\tNickel 개수: %d", chgNk);
	printf("\n\tPenny 개수: %d", chgPn);

	// 종료부
	return 0;
}