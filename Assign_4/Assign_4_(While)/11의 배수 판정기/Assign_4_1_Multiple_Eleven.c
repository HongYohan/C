#include <stdio.h>

#define		TEN		10
int main() {
	int input;
	int dig = 0, sumDig[2] = { 0, 0 };
	int quot, remain;
	int isMult11;
	
	printf("11�� ������� �˰� ���� ������ �Է��ϼ��� >> ");
	scanf_s("%d", &input);
		
	quot = input;
	do {
		remain = quot % TEN;
		quot /= TEN;

		sumDig[dig] += remain;
		dig = !dig;
	} while (quot != 0);
	isMult11 = (sumDig[0] - sumDig[1]) % 11 == 0;
	
	printf("�Է��Ͻ� %d�� 11�� ���%s�ϴ�.\n", input, (isMult11?"��":"�� �ƴ�"));

	system("pause");
	return 0;
}