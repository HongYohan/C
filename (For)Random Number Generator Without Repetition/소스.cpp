#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int a;
	printf("생성할 난수의 수 : ");
	scanf_s("%d", &a);

	int result=1,cnt=1;
	int b[100];
	srand(time(NULL));
	for (int i = 0; ; i++) {
		int random = (rand() % 45) + 1;
		b[i] = random;
		for (int j = 0; j < i; j++) {
			if (b[j] == b[i]) {
				cnt = cnt - 1;
				i = i - 1;
			}
		}
		if (cnt == a) {
			for (int k = 0; k <= i; k++) {
				printf("%d\n", b[k]);
			}
			printf("반복 횟수 : %d", result);
			break;
		}
		result += 1;
		cnt = cnt + 1;	
	}	
}