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

	printf("��ȣȭ�� �Ͻðڽ��ϱ� �ƴϸ� ��ȣȭ�� �Ͻðڽ��ϱ�?\n");
	do {
		printf("(0: ��ȣȭ, 1: ��ȣȭ) >> ");
		scanf_s("%d", &isEnc);			//scanf�� \n �տ����� �д´�.
	} while (isEnc < 0 || isEnc > 1);

	printf("�� ĭ �̵���Ű�ðڽ��ϱ�? ");
	scanf_s("%d", &key);				// ���� ���� �ݺ�	==> 3�̶� ����	3	==> \n�� �����־
	key %= MAX_KEY;

	getchar();					// �����ִ� �����⸦ �����Ѵ�. ���۸� ����.
	printf("%sȣȭ�� %s���� �Է��ϼ��� >> ", isEnc ? "��" : "��", !isEnc ? "��ȣ" : "��");
	gets_s(inputText, LEN);				// \n���� �о�´�

	key *= pow(-1.0, isEnc);
//	printf("%d ", key);

	for (int i = 0; i < strlen(inputText); i++) {
		if (inputText[i] >= 'a' && inputText[i] <= 'z') {
			char temp = inputText[i] - 'a';				// 0-25�� ������ ǥ���� �˴ϴ�.
														// char�� ǥ���� �� �ִ� ������ �ִ� ũ�� -2^7 ~ 2^7-1
			// 26�� ���ĺ� ������ �Ѿ�� ����Ʈ�� ������ ��츦 ó���ϱ�����
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

	printf("�Է� << %s\n", inputText);
	printf("��� << %s\n", outputText);

	system("pause");
	return 0;
}