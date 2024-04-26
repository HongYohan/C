#include <stdio.h>

void main()
{
	int score;
	printf("점수 입력 : ");
	scanf_s("%d", &score);

	switch (score / 10)
	{
	case 10:
	case 9:
		printf("장학생");
		break;
	case 8:
	case 7:
	case 6:
		printf("통과");
		break;
	default:
		printf("재수강");
		break;
	}
}