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
	getchar();						// �����ִ� �����⸦ �����Ѵ�. ���۸� ����.

	input(inputText, isEnc);
	codec(inputText, outputText, key, isEnc);
	output(inputText, outputText);

	most = findMost(outputText);

	system("pause");
	return 0;
}

void init(int *pKey, int*pIsEnc) {
	printf("��ȣȭ�� �Ͻðڽ��ϱ� �ƴϸ� ��ȣȭ�� �Ͻðڽ��ϱ�?\n");
	do {
		printf("(0: ��ȣȭ, 1: ��ȣȭ) >> ");
		scanf_s("%d", pIsEnc);			//scanf�� \n �տ����� �д´�.
	} while (*pIsEnc < 0 || *pIsEnc > 1);

	printf("�� ĭ �̵���Ű�ðڽ��ϱ�? ");
	scanf_s("%d", pKey);				// ���� ���� �ݺ�	==> 3�̶� ����	3	==> \n�� �����־
	*pKey %= MAX;
}

void input(char* inputText, int isEnc) {
	printf("%sȣȭ�� %s���� �Է��ϼ��� >> ", isEnc ? "��" : "��", !isEnc ? "��" : "��ȣ");
	gets_s(inputText, LEN);				// \n���� �о�´�
}

void codec(char* inputText, char* outputText, int key, int isEnc) {
	key *= pow(-1.0, isEnc);
	//	printf("%d ", key);

	for (unsigned int i = 0; i < strlen(inputText); i++) {
		if (inputText[i] >= 'a' && inputText[i] <= 'z') {
			char temp = inputText[i] - 'a';						// 0-25�� ������ ǥ���� �˴ϴ�.
			// char�� ǥ���� �� �ִ� ������ �ִ� ũ�� -2^7 ~ 2^7-1
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
	printf("�Է� << %s\n", inputText);
	printf("��� << %s\n", outputText);
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

	printf("�ִ� �߰� ����: %c \n", 'a' + mostId);
	return mostId;
}