#include <stdio.h>

int main() {
	int score, grade;
	char point[3] = "";

	printf("������ �Է��ϼ��� ");
	do {
		printf("(����: 0~100) >> ");
		scanf_s("%d", &score);
	} while (score < 0 || score > 100);

	grade = score / 5;
	switch (grade) {
	case 20:
	case 19:
		point[1] = '+';
	case 18:
		point[0] = 'A';
		break;
	case 17:
		point[1] = '+';
	case 16:
		point[0] = 'B';
		break;
	case 15:
		point[1] = '+';
	case 14:
		point[0] = 'C';
		break;
	case 13:
		point[1] = '+';
	case 12:
		point[0] = 'D';
		break;
	default:
		point[0] = 'F';
		break;
	}

	printf("\n�л��� ������ %s�Դϴ�.\n����� ���� �����̽��ϴ�.\n", point);

	system("pause");
	return 0;
}