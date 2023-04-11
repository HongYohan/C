#include <stdio.h>
#include <string.h>

int main() {
	printf("3과 9 배수 판정기\n");
	char num[10]=""; // 수를 문자열로 받는다
	printf("정수를 입력하시오 :");
	scanf_s("%[^\n]", num,10);
	//printf("%s", num);
	int i = strlen(num);
	//printf("%d", i);
	int cnt = 0;
	int result = 0;
	do {	// 먼저 하고 뒤에 조건 실행
		//-48은 아스키 코드로 숫자 1을 나타내는 것이다
		result=result+(num[cnt]-48);
		cnt++;
	} while (cnt<i);

	if (result % 3 == 0) {	//3,9의 배수 찾기
		printf("3의 배수\n");
		if (result % 9 == 0) {
			printf("9의 배수\n");
		}
	}
	else {
		printf("3과 9의 배수가 아님");
	}
}