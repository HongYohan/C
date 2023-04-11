#include <stdio.h>

#define MAX	1000
int main() {
	int num;
	int prime[MAX];
	int n = 0, k = 2;

	printf("몇 번째 소수를 찾을까요? ");
	do {
		printf("(0보다 큰 자연수) >> ");
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

	printf("%d번째 소수는 %d입니다.\n", num, prime[n - 1]);

	system("pause");
	return 0;
}