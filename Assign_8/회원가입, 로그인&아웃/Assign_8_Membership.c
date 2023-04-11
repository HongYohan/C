#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN	8

void printMenu();
int out();
void member();
void login();

int mode = 0;		// 0: ����, ȸ������, �α���
					// 1: �α׾ƿ�, ȸ������ ���
char id[MAX_LEN + 1];
char pw[MAX_LEN + 1] = { 0 };
char name[MAX_LEN + 1];
char dob[MAX_LEN + 1];

int main() {
	int sel;
	int isExit = 0;

	do {
		printMenu();
		scanf_s("%d", &sel);

		switch (sel) {
		case 0:
			isExit = out();
			break;
		case 1:
			member();
			break;
		case 2:
			login();
			break;
		}

	} while (!isExit);

	system("pause");
	return 0;
}

void printMenu() {
	if (!mode) {
		printf("0. ����\n1: ȸ������\n2: �α���\n");
	} else {
		printf("0. �α׾ƿ�\n1: ���� ���\n");
	}
	printf("==============================\n");
	printf("������ �۾��� �����ϼ��� >> ");
} 

int out() {
	int isExit = 0;
	if (!mode) {
		isExit = 1;
	} else {
		mode = 0;
	}

	return isExit;
}

void member() {
	if (!mode) {
		char id[MAX_LEN + 1];
		char pw[MAX_LEN + 1] = { 0 };
		char conf[MAX_LEN + 1] = { 0 };
		char name[MAX_LEN + 1] = { 0 };
		char dob[MAX_LEN + 1] = { 0 };

		printf("���ݺ��� ȸ�� ������ �����մϴ�.\n");
		printf("���õǴ� �׸��� �Ĳ��� Ȯ���ϰ� �Է��� �ּ���.\n");

		printf("ID�� �Է��ϼ��� >> ");
		scanf_s("%s", id, MAX_LEN + 1);

		// �ߺ� �˻�
		FILE* rfp;
		fopen_s(&rfp, "member.txt", "r");
		while (!feof(rfp)) {
			char str[40] = "";
			fgets(str, 40, rfp);

			// printf("%s\n", str);
			char *pId, *pContext;
			char deli[2] = ",";
			pId = strtok_s(str, deli, &pContext);

			if (strcmp(id, pId) == 0) {
				fclose(rfp);

				printf("�ߺ��Ǵ� ID�� �ֽ��ϴ�! �ٸ� ID�� �ٽ� �õ��� �ּ���!\n");
				return;
			}
		}
		fclose(rfp);

		printf("��й�ȣ�� �Է��ϼ���\n");
		printf("��, �������� ��ȣ�� ���Ͽ� ȭ�鿡�� ��µ��� �ʽ��ϴ�.\n");
		printf("(���� 8�ڸ�) >> ");
		for (int i = 0; i < MAX_LEN; i++) {
			pw[i] = _getch();
		}

		printf("�ѹ� �� �Է��ϼ���.\n");
		printf("(���� 8�ڸ�) >> ");
		for (int i = 0; i < MAX_LEN; i++) {
			conf[i] = _getch();
		}

		if (strcmp(pw, conf) != 0) {
			printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�.! \nó�� ���� �ٽ� ������ �ּ���!!\n");
			return;
		}

		printf("�̸��� �Է��ϼ���\n");
		printf("(�ִ� ���� 8�ڸ�) >> ");
		scanf_s("%s", name, MAX_LEN + 1);

		printf("��������� �Է��ϼ���\n");
		printf("(���� 8�ڸ� ����: YYYYMMDD) >> ");
		scanf_s("%s", dob, MAX_LEN + 1);

		printf("%s, %s, %s, %s\n", id, pw, name, dob);


		FILE* afp;
		fopen_s(&afp, "member.txt", "a");
		fprintf(afp, "%s, %s, %s, %s\n", id, pw, name, dob);
		fclose(afp);
	} else {
		printf("ID: %s\n�̸�: %s\n�������: %s\n", id, name, dob);
		printf("==============================\n");
	}
}

void login() {
	if (!mode) {
		char conf[MAX_LEN + 1] = { 0 };
		
		char *pToken, *pContext;
		char deli[3] = ", ";

		printf("���ݺ��� �α����� �����մϴ�.\n");
		printf("���õǴ� �׸��� �Ĳ��� Ȯ���ϰ� �Է��� �ּ���.\n");

		printf("ID�� �Է��ϼ��� >> ");
		scanf_s("%s", id, MAX_LEN + 1);

		// �ߺ� �˻�
		FILE* rfp;
		fopen_s(&rfp, "member.txt", "r");
		while (!feof(rfp)) {
			char str[40] = "";
			fgets(str, 40, rfp);

			// printf("%s\n", str);
			
			pToken = strtok_s(str, deli, &pContext);

			if (strcmp(id, pToken) == 0) {
				break;
			}
		}
		if (feof(rfp)) {
			printf("��ġ�ϴ� ID�� �����ϴ�. Ȯ�� �� �ٽ� �õ����ּ���!\n");
			fclose(rfp);
			return;
		}
//		fclose(rfp);

		printf("��й�ȣ�� �Է��ϼ���\n");
		printf("(���� 8�ڸ�) >> ");
		for (int i = 0; i < MAX_LEN; i++) {
			pw[i] = _getche();
			if (i > 0) {
				printf("\b\b*%c", pw[i]);		// masquerade: �����ϴ�.	==> masking
			}
		}
		printf("\b*\n");

		pToken = strtok_s(NULL, deli, &pContext);
		if (strcmp(pw, pToken) != 0) {
			printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�.! \nó�� ���� �ٽ� ������ �ּ���!!\n");
			return;
		}

		pToken = strtok_s(NULL, deli, &pContext);
		strcpy_s(name, MAX_LEN, pToken);

		pToken = strtok_s(NULL, deli, &pContext);
		strncpy_s(dob, MAX_LEN + 1, pToken, MAX_LEN);

	}

	mode = 1;
}