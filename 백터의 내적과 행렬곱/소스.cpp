#include <stdio.h>

int main() {
	int cnt = 0;
	while (1){
		if (cnt == 2) {
			break;
		}
		int a, b;
		printf("\nX ����� ũ�� : ");
		scanf_s("%d %d", &a, &b);
		int c, d;
		printf("Y ����� ũ�� : ");
		scanf_s("%d %d", &c, &d);

		int x[100][100], y[100][100];
		printf("x�� �� �Է� :");
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				scanf_s("%d", &x[i][j]);
			}
		}
		printf("y�� �� �Է� :");
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				scanf_s("%d", &y[i][j]);
			}
		}
		printf("\nx ���� ���\n");
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				printf("%d ", x[i][j]);
			}
			printf("\n");
		}
		printf("\ny ���� ���\n");
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				printf("%d ", y[i][j]);
			}
			printf("\n");
		}

		printf("\n��� �� :\n");
		int number;
		for (int i = 0; i < a ; i++) {
			for (int j = 0; j < d; j++) {
				number = 0;
				for (int k = 0; k < b; k++) {
					number += (x[i][k] * y[k][j]);
				}
				printf("%d ", number);
			}
			printf("\n");
		}
		cnt += 1;
	}
}