#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>

int option() {
	int opt;
	do {
		printf("���\n0: ����\n1: ��й�ȣ ����/����\n2: ��й�ȣ ����\n\n");
		scanf_s("%d", &opt);
	} while (opt > 2 || opt < 0);
	return opt;
}
void pass_setf(char* arr) {
	getchar();
	printf("��й�ȣ ���� : ");
	gets_s(arr, 101);
	FILE* fp;
	fp = fopen("C:\\Users\\82106\\Desktop\\2�б�\\pass.txt", "w");
	fprintf(fp, arr, 100);
	fclose(fp);
	printf("��й�ȣ ������ �Ϸ�Ǿ����ϴ�!");
}

void pass_chk() {
	char arr[101] = "";
	FILE* fp_p;
	fp_p = fopen("C:\\Users\\82106\\Desktop\\2�б�\\pass.txt", "r");
	if (fp_p == NULL)
		printf("---");
	fscanf(fp_p, "%s\n", arr);
	fclose(fp_p);

	char pass[101] = "";
	int i = 0;
	do {
		getchar();
		printf("��й�ȣ �Է� : ");
		gets_s(pass, 101);
		printf("�Էµ� ��й�ȣ : ");
		for (int i = 0; i < strlen(pass); i++) {
			printf("*");
		}
		
		if (strcmp(arr,pass)==0) {
			printf("\n\n��й�ȣ�� ����");
			break;
		}
		else {
			printf("\n��й�ȣ�� Ʋ��\n�ٽ� �Է¹ٶ�(Enter ������ �ٽ� �Է�)");
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
		printf("\n����!\n");
		return 0;
	}	
}