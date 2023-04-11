#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define LEN 500
#define MAX_KEY 26
int main() {
	char inputText[LEN];
	char outputText[LEN] = { 0 };
	char* pinputText;
	char* poutputText;
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

	pinputText = inputText;
	poutputText = outputText;

	getchar();					// �����ִ� �����⸦ �����Ѵ�. ���۸� ����.
	printf("%sȣȭ�� %s���� �Է��ϼ��� >> ", isEnc ? "��" : "��", !isEnc ? "��ȣ" : "��");
	gets_s(pinputText, LEN);				// \n���� �о�´�

	key *= pow(-1.0, isEnc);
	//	printf("%d ", key);

	for (int i = 0; i < strlen(pinputText); i++) {
		if (*(pinputText + i) >= 'a' && *(poutputText + i) <= 'z') {
			char temp = *(pinputText + i) - 'a';				// 0-25�� ������ ǥ���� �˴ϴ�.
			// char�� ǥ���� �� �ִ� ������ �ִ� ũ�� -2^7 ~ 2^7-1
// 26�� ���ĺ� ������ �Ѿ�� ����Ʈ�� ������ ��츦 ó���ϱ�����
			temp += key;
			temp %= 26;
			temp += 'a';
			*(outputText + i) = temp;
		}
		else if (*(pinputText + i) >= 'A' && *(pinputText + i) <= 'Z') {
			*(poutputText + i) = (*(pinputText + i) - 'A' + key) % 26 + 'A';
		}
		else {
			*(poutputText + i) = *(pinputText + i);
		}
	}


	printf("�Է� << %s\n", pinputText);
	printf("��� << %s\n", poutputText);
	return 0;
}