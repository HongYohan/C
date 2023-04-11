#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>

int option() {
	int opt;
	do {
		printf("기능\n0: 종료\n1: 비밀번호 설정/변경\n2: 비밀번호 검증\n\n");
		scanf_s("%d", &opt);
	} while (opt > 2 || opt < 0);
	return opt;
}
void pass_setf(char* arr) {
	getchar();
	printf("비밀번호 생성 : ");
	gets_s(arr, 101);
	FILE* fp;
	fp = fopen("C:\\Users\\82106\\Desktop\\2학기\\pass.txt", "w");
	fprintf(fp, arr, 100);
	fclose(fp);
	printf("비밀번호 생성이 완료되었습니다!");
}

void pass_chk() {
	char arr[101] = "";
	FILE* fp_p;
	fp_p = fopen("C:\\Users\\82106\\Desktop\\2학기\\pass.txt", "r");
	if (fp_p == NULL)
		printf("---");
	fscanf(fp_p, "%s\n", arr);
	fclose(fp_p);

	char pass[101] = "";
	int i = 0;
	do {
		getchar();
		printf("비밀번호 입력 : ");
		gets_s(pass, 101);
		printf("입력된 비밀번호 : ");
		for (int i = 0; i < strlen(pass); i++) {
			printf("*");
		}
		
		if (strcmp(arr,pass)==0) {
			printf("\n\n비밀번호가 맞음");
			break;
		}
		else {
			printf("\n비밀번호가 틀림\n다시 입력바람(Enter 누르면 다시 입력)");
		}
	} while (strcmp(arr, pass) !=0);
}

int main() {
	char pass_set[101] = "";

	int num = option();
	
	if (num == 1) {
		pass_setf(pass_set);
	}
	else if (num == 2) {
		pass_chk();
	}
	else {
		printf("\n종료!\n");
		return 0;
	}	
}