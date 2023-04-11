#include <stdio.h>

int main() {
	//num1에다가 정수 선언
	int num1;
	printf("투입한 금액(원):"); //숫자를 입력받음
	scanf_s("%d", &num1); //입력받은 숫자를 정수라는 num1변수에 입력

	printf("음료의 가격은 600원 입니다.\n"); 

	int price1;
	price1 = 600; //price1에 음료 가격 선언

	printf("거스름 돈 : %d원", num1 - price1); //거스름돈을 표시
	return 0;
}