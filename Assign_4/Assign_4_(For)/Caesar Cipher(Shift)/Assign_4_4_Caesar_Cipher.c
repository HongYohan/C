#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define LEN 500
#define MAX_KEY 26
int main() {
	char inputText[LEN];
	char outputText[LEN] = { 0 };
	int key;
	int isEnc;

	printf("암호화를 하시겠습니까 아니면 복호화를 하시겠습니까?\n");
	do {
		printf("(0: 암호화, 1: 복호화) >> ");
		scanf_s("%d", &isEnc);			//scanf는 \n 앞에까지 읽는다.
	} while (isEnc < 0 || isEnc > 1);

	printf("몇 칸 이동시키시겠습니까? ");
	scanf_s("%d", &key);				// 같은 일을 반복	==> 3이랑 엔터	3	==> \n가 남아있어서
	key %= MAX_KEY;

	getchar();					// 남아있는 쓰레기를 정리한다. 버퍼를 비운다.
	printf("%s호화할 %s문을 입력하세요 >> ", isEnc ? "암" : "복", !isEnc ? "암호" : "평");
	gets_s(inputText, LEN);				// \n까지 읽어온다

	key *= pow(-1.0, isEnc);
//	printf("%d ", key);

	for (int i = 0; i < strlen(inputText); i++) {
		if (inputText[i] >= 'a' && inputText[i] <= 'z') {
			char temp = inputText[i] - 'a';				// 0-25의 값으로 표현이 됩니다.
														// char가 표현할 수 있는 숫자의 최대 크기 -2^7 ~ 2^7-1
			// 26의 알파벳 범위를 넘어가게 쉬프트를 시켰을 경우를 처리하기위해
			temp += key;
			temp %= 26;
			temp += 'a';
			outputText[i] = temp;
		} else if (inputText[i] >= 'A' && inputText[i] <= 'Z') {			
			outputText[i] = (inputText[i] - 'A' + key) % 26 + 'A';
		} else {
			outputText[i] = inputText[i];
		}
	}

	printf("입력 << %s\n", inputText);
	printf("출력 << %s\n", outputText);

	system("pause");
	return 0;
}