#include <stdio.h>

#define MAX	1000
int main() {
	int num;
	int prime[MAX];
	int n = 0, k = 2;

	printf("�� ��° �Ҽ��� ã�����? ");
	do {
		printf("(0���� ū �ڿ���) >> ");
		scanf_s("%d", &num);
	} while (num < 1);

	while (n != num) {
		int i;
		for (i = 0; i < n; i++) {
			if (k % prime[i] == 0) {
				break;
			}
		}

		if (i == n) {
			prime[n++] = k;
		}

		k++;
	}

	printf("%d��° �Ҽ��� %d�Դϴ�.\n", num, prime[n - 1]);

	system("pause");
	return 0;
}