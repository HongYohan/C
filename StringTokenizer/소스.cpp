#include <stdio.h>

int main() {
	char str[10]=""; //10개까지 출력이 가능하다
	printf("문장을 입력하시오 :"); 
	scanf("%[^\n]", str); //문장을 변수에 입력하는데 \n까지 입력한다
	char space = ' ';
	int i = 0;
	while (1) {
		printf("%c", str[i]); // %c 에 철자 하나씩 들어간다
		if (str[i] == space) {
			printf("\n"); // 공백이 생기면 \n으로 띄어쓰기를 한다
		}
		else if (str[i] == '\0') {
			break; // \n이면 반복문을 끝낸다.
		}
		i=i+1; // i = 1씩 증가
	}
}