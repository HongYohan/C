#include <stdio.h>

int main() {
	int score, grade;
	char point[3] = "";

	printf("성적을 입력하세요 ");
	do {
		printf("(범위: 0~100) >> ");
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

	printf("\n학생의 학점은 %s입니다.\n대단히 수고 많으셨습니다.\n", point);

	system("pause");
	return 0;
}