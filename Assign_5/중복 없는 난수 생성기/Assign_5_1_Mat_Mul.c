#include <stdio.h>

#define N_MAT	2
#define N_DIM	2
#define MAX_ROW	10
#define MAX_COL 10

int main() {
	float mat[N_MAT][MAX_ROW][MAX_COL];
	int size[N_MAT][N_DIM];
	float res[MAX_ROW][MAX_COL] = { 0.0 };

	do {
		for (int i = 0; i < N_MAT; i++) {
			printf("%d번째 행렬의 크기를 입력하세요 (구분: 스페이스) >> ", i + 1);
			scanf_s("%d %d", &size[i][0], &size[i][1]);
		}
		printf("\n");
	} while (size[0][1] != size[1][0]);

	for (int i = 0; i < N_MAT; i++) {
		printf("%d번째 행렬의 원소를 입력하세요 (%d행%d열) >> ", i, size[i][0], size[i][1]);
		for (int j = 0; j < size[i][0]; j++) {
			for (int k = 0; k < size[i][1]; k++) {
				scanf_s("%f", &mat[i][j][k]);
			}
		}
	}
	printf("\n");

	for (int i = 0; i < size[0][0]; i++) {
		for (int j = 0; j < size[1][1]; j++) {
			for (int k = 0; k < size[0][1]; k++) {
				res[i][j] += mat[0][i][k] * mat[1][k][j];
			}
		}
	}

	for (int i = 0; i < N_MAT; i++) {
		printf("%d번째 행렬\n", i + 1);
		for (int j = 0; j < size[i][0]; j++) {
			for (int k = 0; k < size[i][1]; k++) {
				printf("%.2f ", mat[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("결과 행렬\n");
	for (int i = 0; i < size[0][0]; i++) {
		for (int j = 0; j < size[1][1]; j++) {
			printf("%.2f ", res[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}