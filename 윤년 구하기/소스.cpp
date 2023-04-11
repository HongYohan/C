#include <stdio.h>

int main() {
	int year; //연도의 정수를 선언 후 입력받음
	printf("연도를 입력하시오(yyyy) : ");
	scanf_s("%d", &year); //연도라는 변수에 입력받은 정수를 삽입
	// 삼항 연산자로써 조건?참:거짓; 형식으로 입력
	// &&은 그리고 이고 ||는 또는 이라는 의미이다.
	(year % 4 == 0 && year % 100 != 0)||year%400==0 ? printf("윤년") : printf("윤년이 아닙니다!");
}