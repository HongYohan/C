#include <stdio.h>
#include <stdlib.h>

#define MAX	1000
int main() {
	int k = 2;
	int num;
	//int prime[MAX] = { 0 };
	int* prime = (int*)calloc(MAX, sizeof(int)); //calloc은 항상 0으로 초기화됨
	int* pNext = prime;

	printf("몇 번째 소수를 찾을까요? ");
	do {
		printf("(0보다 큰 자연수) >> ");
		scanf_s("%d", &num);
	} while (num < 1);

	while (prime + num != pNext) {
		int i;
		for (i = 0; *(prime + i) != 0; i++) {
			if (k % *(prime + i) == 0) {
				break;
			}
		}

		if (prime + i == pNext) {
			*pNext++ = k;
		}

		k++;
	}

	printf("%d번째 소수는 %d입니다.\n", num, *(pNext - 1));

	system("pause");
	return 0;
}