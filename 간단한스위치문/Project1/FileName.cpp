#include <stdio.h>

void main()
{
	int score;
	printf("���� �Է� : ");
	scanf_s("%d", &score);

	switch (score / 10)
	{
	case 10:
	case 9:
		printf("���л�");
		break;
	case 8:
	case 7:
	case 6:
		printf("���");
		break;
	default:
		printf("�����");
		break;
	}
}