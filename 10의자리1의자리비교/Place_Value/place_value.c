#include <stdio.h>
#include "all.h"

void main() {
	int x;
	for (;;) {
		printf("2자리 정수 입력(10~99, 종료 : 0) >> ");
		scanf_s("%d", &x);
		if (x == 0) {
			break;
		}

		if (x < 10||x>=100) {
			printf("10~99 사이의 정수만 입력하세요.\n");
		}
		else {
			place_value(x);
		}
	}
}