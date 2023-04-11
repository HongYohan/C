#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void init(int* pKey, int* pIsEnc);
void input(char* inputText, int isEnc);
void codec(char* inputText, char* outputText, int key, int isEnc);
void output(char* inputText, char* outputText);
int findMost(char* text);

#define LEN 500
#define MAX 26
int main() {
	char inputText[LEN];
	char outputText[LEN] = { 0 };
	int key;
	int isEnc;
	int most;

	init(&key, &isEnc);
	getchar();						// 남아있는 쓰레기를 정리한다. 버퍼를 비운다.

	input(inputText, isEnc);
	codec(inputText, outputText, key, isEnc);
	output(inputText, outputText);

	most = findMost(outputText);

	system("pause");
	return 0;
}

void init(int *pKey, int*pIsEnc) {
	printf("암호화를 하시겠습니까 아니면 복호화를 하시겠습니까?\n");
	do {
		printf("(0: 암호화, 1: 복호화) >> ");
		scanf_s("%d", pIsEnc);			//scanf는 \n 앞에까지 읽는다.
	} while (*pIsEnc < 0 || *pIsEnc > 1);

	printf("몇 칸 이동시키시겠습니까? ");
	scanf_s("%d", pKey);				// 같은 일을 반복	==> 3이랑 엔터	3	==> \n가 남아있어서
	*pKey %= MAX;
}

void input(char* inputText, int isEnc) {
	printf("%s호화할 %s문을 입력하세요 >> ", isEnc ? "복" : "암", !isEnc ? "평" : "암호");
	gets_s(inputText, LEN);				// \n까지 읽어온다
}

void codec(char* inputText, char* outputText, int key, int isEnc) {
	key *= pow(-1.0, isEnc);
	//	printf("%d ", key);

	for (unsigned int i = 0; i < strlen(inputText); i++) {
		if (inputText[i] >= 'a' && inputText[i] <= 'z') {
			char temp = inputText[i] - 'a';						// 0-25의 값으로 표현이 됩니다.
			// char가 표현할 수 있는 숫자의 최대 크기 -2^7 ~ 2^7-1
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
}

void output(char* inputText, char* outputText) {
	printf("입력 << %s\n", inputText);
	printf("출력 << %s\n", outputText);
}

int findMost(char* text) {
	int count[MAX] = { 0 };
	int mostId = 0;

	for (unsigned int i = 0; i < strlen(text); i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			count[text[i] - 'a']++;
		} else if (text[i] >= 'A' && text[i] <= 'Z') {
			count[text[i] - 'A']++;
		}
	}

	for (int i = 1; i < MAX; i++) {
		if (count[mostId] < count[i]) {
			mostId = i;
		}
	}

	printf("최다 발견 문자: %c \n", 'a' + mostId);
	return mostId;
}