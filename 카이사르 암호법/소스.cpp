#include <stdio.h>
#include <string.h>


int main() {
	int key_type, cnt;
	printf("키 타입 설정(1:암호화,2:복호화): ");
	scanf_s("%d", &key_type);
	char text[100] ="";

	// 칸 수
	printf("이동시킬 칸 수 입력 : ");
	scanf_s("%d", &cnt);

	// 입력 문자
	printf("암호화 시킬 문장 입력 : ");
	scanf_s(" %[^\n]", text, 100);

	//암호화
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