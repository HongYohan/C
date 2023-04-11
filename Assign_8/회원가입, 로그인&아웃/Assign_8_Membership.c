#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN	8

void printMenu();
int out();
void member();
void login();

int mode = 0;		// 0: 종료, 회원가입, 로그인
					// 1: 로그아웃, 회원정보 출력
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
		printf("0. 종료\n1: 회원가입\n2: 로그인\n");
	} else {
		printf("0. 로그아웃\n1: 정보 출력\n");
	}
	printf("==============================\n");
	printf("수행할 작업을 선택하세요 >> ");
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

		printf("지금부터 회원 가입을 시작합니다.\n");
		printf("제시되는 항목을 꼼꼼히 확인하고 입력해 주세요.\n");

		printf("ID를 입력하세요 >> ");
		scanf_s("%s", id, MAX_LEN + 1);

		// 중복 검사
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

				printf("중복되는 ID가 있습니다! 다른 ID로 다시 시도해 주세요!\n");
				return;
			}
		}
		fclose(rfp);

		printf("비밀번호를 입력하세요\n");
		printf("단, 개인정보 보호를 위하여 화면에는 출력되지 않습니다.\n");
		printf("(고정 8자리) >> ");
		for (int i = 0; i < MAX_LEN; i++) {
			pw[i] = _getch();
		}

		printf("한번 더 입력하세요.\n");
		printf("(고정 8자리) >> ");
		for (int i = 0; i < MAX_LEN; i++) {
			conf[i] = _getch();
		}

		if (strcmp(pw, conf) != 0) {
			printf("비밀번호가 일치하지 않습니다.! \n처음 부터 다시 진행해 주세요!!\n");
			return;
		}

		printf("이름을 입력하세요\n");
		printf("(최대 영문 8자리) >> ");
		scanf_s("%s", name, MAX_LEN + 1);

		printf("생년월일을 입력하세요\n");
		printf("(숫자 8자리 형식: YYYYMMDD) >> ");
		scanf_s("%s", dob, MAX_LEN + 1);

		printf("%s, %s, %s, %s\n", id, pw, name, dob);


		FILE* afp;
		fopen_s(&afp, "member.txt", "a");
		fprintf(afp, "%s, %s, %s, %s\n", id, pw, name, dob);
		fclose(afp);
	} else {
		printf("ID: %s\n이름: %s\n생년월일: %s\n", id, name, dob);
		printf("==============================\n");
	}
}

void login() {
	if (!mode) {
		char conf[MAX_LEN + 1] = { 0 };
		
		char *pToken, *pContext;
		char deli[3] = ", ";

		printf("지금부터 로그인을 시작합니다.\n");
		printf("제시되는 항목을 꼼꼼히 확인하고 입력해 주세요.\n");

		printf("ID를 입력하세요 >> ");
		scanf_s("%s", id, MAX_LEN + 1);

		// 중복 검사
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
			printf("일치하는 ID가 없습니다. 확인 후 다시 시도해주세요!\n");
			fclose(rfp);
			return;
		}
//		fclose(rfp);

		printf("비밀번호를 입력하세요\n");
		printf("(고정 8자리) >> ");
		for (int i = 0; i < MAX_LEN; i++) {
			pw[i] = _getche();
			if (i > 0) {
				printf("\b\b*%c", pw[i]);		// masquerade: 가장하다.	==> masking
			}
		}
		printf("\b*\n");

		pToken = strtok_s(NULL, deli, &pContext);
		if (strcmp(pw, pToken) != 0) {
			printf("비밀번호가 일치하지 않습니다.! \n처음 부터 다시 진행해 주세요!!\n");
			return;
		}

		pToken = strtok_s(NULL, deli, &pContext);
		strcpy_s(name, MAX_LEN, pToken);

		pToken = strtok_s(NULL, deli, &pContext);
		strncpy_s(dob, MAX_LEN + 1, pToken, MAX_LEN);

	}

	mode = 1;
}