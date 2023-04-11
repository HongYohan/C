#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define LEN 17

void swap(int* pa,int a) {
	int cnt = 0;
	for (int w = 0; w < a; w++) {
		for (int x = cnt; x < a; x++) {
			int c = 0;
			if (*(pa+w) > *(pa + x)) {
				c = *(pa + w);
				*(pa + w) = *(pa + x);
				*(pa + x) = c;
			}
		}
		cnt++;
		printf("%d\n", *(pa + w));
	}

	printf("최소값 : %d", pa[0]);
	for (int i = 0; i < a; i++) {
		if (i == a-1) {
			printf("\n최대값 : %d", pa[i]);
			break;
		}
	}
}

int main() {
	int a;
	printf("생성할 난수의 수 : ");
	scanf_s("%d", &a);

	int* pa = (int*)calloc(a, sizeof(int*));

	int result = 1, cnt = 1;
	srand(time(NULL));
	for (int i = 0; ; i++) {
		int random = (rand() % 45) + 1;
		*(pa+i)= random;
		for (int j = 0; j < i; j++) {
			if (*(pa + j) == *(pa + i)) {
				cnt = cnt - 1;
				i = i - 1;
			}
		}

		if (cnt == a) {
			for (int k = 0; k <= i; k++) {
				printf("%d\n", *(pa + k));
			}
			printf("반복 횟수 : %d\n\n", result);
			break;
		}
		result += 1;
		cnt = cnt + 1;
	}

	swap(pa,a);
	return 0;
}