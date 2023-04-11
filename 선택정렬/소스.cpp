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

int input() { //출력을 입력받는 함수
	int a;
	printf("생성할 난수의 수 : ");
	scanf_s("%d", &a);
	//Vector.numArr = (int*)calloc(Vector.size, sizeof(int*));
	return a; //출력값 반환
}
int range() {
	int b; //오름차순과 내림차순 선택
	do {
		printf("-1:내림차순\n0:안됨\n1:오름차순\n\n어떤 정렬을 원하십니까? : ");
		scanf_s("%d", &b);
	} while (b < -1 || b > 1); //do-while 문으로 오름과 내림만 선택이 가능하도록 설정
	return b; //값 반환
}

void genNums(int* nums,int n) {
	srand(time(NULL)); //변수생성
	for (int i = 0;i<n; i++) {
		int random = (rand() % 45) + 1;
		*(nums + i) = random;
		for (int j = 0; j < i; j++) {
			if (*(nums + j) == *(nums + i)) { // 중복확인
				i = i - 1;
			}
		}
	}
}

void sortNums(int* nums,int n,int b) {
	int cnt = 0;
	if (b == 1) { //오름차순
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
	else if (b == -1) { //내림차순
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
		printf("정렬 없음!!");
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

void printNums(int* nums,int n,int mini,int maxx) { //값 출력
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
	
	printf("\n최소값의 인덱스 넘버 : %d", cnt1);
	printf("\n최대값의 인덱스 넘버 : %d\n", cnt2);
}

int main() {
	struct Vector Vector;
	struct Vector* p;
	Vector.numArr=input(); //n의 값 즉 변수의 개수 선언
	Vector.isAligned = range(); //오름과 내림 선택

	
	p = &Vector;
	p->size = (int*)calloc(Vector.numArr, sizeof(int*)); //변수의 개수에 맞게 크기 조정


	genNums(p->size, Vector.numArr); //개수에 맞는 변수 생성
	
	Vector.minId= min(p->size, Vector.numArr);
	Vector.maxld = max(p->size, Vector.numArr);

	printf("\n최소값 : %d", Vector.minId);
	printf("\n최대값 : %d\n", Vector.maxld);

	printf("\n정렬되지 않은 값 : ");
	printNums(p->size, Vector.numArr, Vector.minId, Vector.maxld); //값 출력 (정렬 x)
	sortNums(p->size, Vector.numArr, Vector.isAligned); //정렬
	if (Vector.isAligned == 1) {
		printf("\n\n오름차순으로 정렬된 값 : ");
	}
	else if(Vector.isAligned==-1) {
		printf("\n내림차순으로 정렬된 값 : ");
	}
	else {
		printf("\n정렬되지 않은 값 : ");
	}

	printNums(p->size, Vector.numArr, Vector.minId, Vector.maxld); //값 출력(정렬 o)

	

	return 0;
}