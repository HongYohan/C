#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	double D;

	double mean, diff;

	printf("2�� �������� �� ����� �Է��ϼ��� (�Է� ����: ����, ������: �����̽�) >> ");
	scanf_s("%d %d %d", &a, &b, &c);

	mean = -b / 2.0 / a;

	D = pow(b, 2.0) - 4 * a * c;
	diff = D < 0 ? -D : D;
	diff = sqrt(diff) / 2.0 / a;

	printf("�Է��Ͻ� 2�� �������� ���� %.2f��%.2f%c�Դϴ�.\n", mean, diff, (D < 0 ? 'i' : ' '));

	return 0;
}