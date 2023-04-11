#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct Vector {
	int numArr;
	int* size;
	int isAligned;
	int minId;
	int maxld;
};

int input() { //����� �Է¹޴� �Լ�
	int a;
	printf("������ ������ �� : ");
	scanf_s("%d", &a);
	//Vector.numArr = (int*)calloc(Vector.size, sizeof(int*));
	return a; //��°� ��ȯ
}
int range() {
	int b; //���������� �������� ����
	do {
		printf("-1:��������\n0:�ȵ�\n1:��������\n\n� ������ ���Ͻʴϱ�? : ");
		scanf_s("%d", &b);
	} while (b < -1 || b > 1); //do-while ������ ������ ������ ������ �����ϵ��� ����
	return b; //�� ��ȯ
}

void genNums(int* nums,int n) {
	srand(time(NULL)); //��������
	for (int i = 0;i<n; i++) {
		int random = (rand() % 45) + 1;
		*(nums + i) = random;
		for (int j = 0; j < i; j++) {
			if (*(nums + j) == *(nums + i)) { // �ߺ�Ȯ��
				i = i - 1;
			}
		}
	}
}

void sortNums(int* nums,int n,int b) {
	int cnt = 0;
	if (b == 1) { //��������
		for (int w = 0; w < n; w++) {
			for (int x = cnt; x < n; x++) {
				int c = 0;
				if (*(nums + w) > *(nums + x)) {
					c = *(nums + w);
					*(nums + w) = *(nums + x);
					*(nums + x) = c;
				}
			}
			cnt++;
		}
	}
	else if (b == -1) { //��������
		for (int w = 0; w < n; w++) {
			for (int x = cnt; x < n; x++) {
				int c = 0;
				if (*(nums + w) < *(nums + x)) {
					c = *(nums + w);
					*(nums + w) = *(nums + x);
					*(nums + x) = c;
				}
			}
			cnt++;
		}
	}
	else {
		printf("���� ����!!");
	}
}

int min(int* nums, int n) {
	int min= *(nums+0);
	for (int i = 0; i < n; i++) {
		if (min > *(nums + i)) {
			min = *(nums + i);
		}
	}
	return min;
}

int max(int* nums, int n) {
	int max = *(nums + 0);
	for (int i = 0; i < n; i++) {
		if (max < *(nums + i)) {
			max = *(nums + i);
		}
	}
	return max;
}

void printNums(int* nums,int n,int mini,int maxx) { //�� ���
	int cnt1, cnt2;
	for (int j = 0; j < n; j++) {
		if (*(nums + j) == mini) {
			cnt1 = j;
		}
		else if (*(nums + j) == maxx) {
			cnt2 = j;
		}
	}

	printf("\b[");
	for (int i = 0; i < n; i++) {
		printf("%d\,", *(nums + i));
	}
	printf("\b]\n");
	
	printf("\n�ּҰ��� �ε��� �ѹ� : %d", cnt1);
	printf("\n�ִ밪�� �ε��� �ѹ� : %d\n", cnt2);
}

int main() {
	struct Vector Vector;
	struct Vector* p;
	Vector.numArr=input(); //n�� �� �� ������ ���� ����
	Vector.isAligned = range(); //������ ���� ����

	
	p = &Vector;
	p->size = (int*)calloc(Vector.numArr, sizeof(int*)); //������ ������ �°� ũ�� ����


	genNums(p->size, Vector.numArr); //������ �´� ���� ����
	
	Vector.minId= min(p->size, Vector.numArr);
	Vector.maxld = max(p->size, Vector.numArr);

	printf("\n�ּҰ� : %d", Vector.minId);
	printf("\n�ִ밪 : %d\n", Vector.maxld);

	printf("\n���ĵ��� ���� �� : ");
	printNums(p->size, Vector.numArr, Vector.minId, Vector.maxld); //�� ��� (���� x)
	sortNums(p->size, Vector.numArr, Vector.isAligned); //����
	if (Vector.isAligned == 1) {
		printf("\n\n������������ ���ĵ� �� : ");
	}
	else if(Vector.isAligned==-1) {
		printf("\n������������ ���ĵ� �� : ");
	}
	else {
		printf("\n���ĵ��� ���� �� : ");
	}

	printNums(p->size, Vector.numArr, Vector.minId, Vector.maxld); //�� ���(���� o)

	

	return 0;
}