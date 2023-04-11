#include <stdio.h>
#include <stdlib.h>

// ������ ����
typedef enum _mon { 
	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC 
} mon;

int main() {
	int YYYY;
	mon MM;
	int isLeap;
	int day;

	printf("������ �Է��ϼ��� (����, ���) >> ");
	scanf_s("%d", &YYYY);

	printf("���� �Է��ϼ��� ");
	do {
		printf("(����: 1~12) >> ");
		scanf_s("%d", &MM);
	} while (MM < 1 || MM > 12);

	isLeap = ((YYYY % 4 == 0) && (YYYY % 100 != 0)) || (YYYY % 400 == 0);

	switch (MM) {
	case FEB:
		day = 28 + isLeap;
		break;
	case APR:
	case JUN:
	case SEP:
	case NOV:
		day = 30;
		break;
	default:
		day = 31;
		break;
	}

	printf("%d�� %d���� �ϼ�: %d\n", YYYY, MM, day);

	system("pause");
	return 0;
}