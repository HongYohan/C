#include <stdio.h>
#include <string.h>

int main() {
	printf("3�� 9 ��� ������\n");
	char num[10]=""; // ���� ���ڿ��� �޴´�
	printf("������ �Է��Ͻÿ� :");
	scanf_s("%[^\n]", num,10);
	//printf("%s", num);
	int i = strlen(num);
	//printf("%d", i);
	int cnt = 0;
	int result = 0;
	do {	// ���� �ϰ� �ڿ� ���� ����
		//-48�� �ƽ�Ű �ڵ�� ���� 1�� ��Ÿ���� ���̴�
		result=result+(num[cnt]-48);
		cnt++;
	} while (cnt<i);

	if (result % 3 == 0) {	//3,9�� ��� ã��
		printf("3�� ���\n");
		if (result % 9 == 0) {
			printf("9�� ���\n");
		}
	}
	else {
		printf("3�� 9�� ����� �ƴ�");
	}
}