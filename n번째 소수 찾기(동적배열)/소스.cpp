#include <stdio.h>
#include <stdlib.h>

#define MAX	1000
int main() {
	int k = 2;
	int num;
	//int prime[MAX] = { 0 };
	int* prime = (int*)calloc(MAX, sizeof(int)); //calloc�� �׻� 0���� �ʱ�ȭ��
	int* pNext = prime;

	printf("�� ��° �Ҽ��� ã�����? ");
	do {
		printf("(0���� ū �ڿ���) >> ");
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

	printf("%d��° �Ҽ��� %d�Դϴ�.\n", num, *(pNext - 1));

	system("pause");
	return 0;
}