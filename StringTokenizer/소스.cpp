#include <stdio.h>

int main() {
	char str[10]=""; //10������ ����� �����ϴ�
	printf("������ �Է��Ͻÿ� :"); 
	scanf("%[^\n]", str); //������ ������ �Է��ϴµ� \n���� �Է��Ѵ�
	char space = ' ';
	int i = 0;
	while (1) {
		printf("%c", str[i]); // %c �� ö�� �ϳ��� ����
		if (str[i] == space) {
			printf("\n"); // ������ ����� \n���� ���⸦ �Ѵ�
		}
		else if (str[i] == '\0') {
			break; // \n�̸� �ݺ����� ������.
		}
		i=i+1; // i = 1�� ����
	}
}