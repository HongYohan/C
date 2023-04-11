#include <stdio.h>

#define		TEN		10
int main() {
	int input;
	int dig = 0, sumDig[2] = { 0, 0 };
	int quot, remain;
	int isMult11;
	
	printf("11의 배수인지 알고 싶은 정수를 입력하세요 >> ");
	scanf_s("%d", &input);
		
	quot = input;
	do {
		remain = quot % TEN;
		quot /= TEN;

		sumDig[dig] += remain;
		dig = !dig;
	} while (quot != 0);
	isMult11 = (sumDig[0] - sumDig[1]) % 11 == 0;
	
	printf("입력하신 %d은 11의 배수%s니다.\n", input, (isMult11?"입":"가 아닙"));

	system("pause");
	return 0;
}