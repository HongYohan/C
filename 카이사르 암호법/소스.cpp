#include <stdio.h>
#include <string.h>


int main() {
	int key_type, cnt;
	printf("Ű Ÿ�� ����(1:��ȣȭ,2:��ȣȭ): ");
	scanf_s("%d", &key_type);
	char text[100] ="";

	// ĭ ��
	printf("�̵���ų ĭ �� �Է� : ");
	scanf_s("%d", &cnt);

	// �Է� ����
	printf("��ȣȭ ��ų ���� �Է� : ");
	scanf_s(" %[^\n]", text, 100);

	//��ȣȭ
	if (key_type == 1) {
		for (int i = 0; i < strlen(text); i++) {
			if (text[i] >= 'A' && text[i] <= 'Z') {
				if (text[i] + cnt > 90) {
					text[i] = text[i] - 26;
				}
				text[i] = text[i] - 'A';
				text[i] = (text[i] + cnt) % 65;
				text[i] = text[i] + 'A';
			}

			else if (text[i] >= 'a' && text[i] <= 'z') {
				if (text[i] + cnt > 122) {
					text[i] = text[i] - 26;
				}
				text[i] = text[i] - 'a';
				text[i] = (text[i] + cnt) % 97;
				text[i] = text[i]+'a';
			}

			else if (text[i] == ' ') {
				text[i] = text[i];
			}
		}
		printf("%s", text);
	}
	else {
		for (int i = 0; i < strlen(text); i++) {
			if (text[i] >= 'A' && text[i] <= 'Z') {
				if (text[i] - cnt < 65) {
					text[i] = text[i] + 26;
				}
				text[i] = text[i] - 'A';
				text[i] = (text[i] - cnt) % 65;
				text[i] = text[i] + 'A';
			}

			else if (text[i] >= 'a' && text[i] <= 'z') {
				if (text[i] - cnt < 97) {
					text[i] = text[i] + 26;
				}
				text[i] = text[i] - 'a';
				text[i] = (text[i] - cnt) % 97;
				text[i] = text[i]+'a';
			}

			else if (text[i] == ' ') {
				text[i] = text[i];
			}
		}
		printf("%s", text);
	}
}