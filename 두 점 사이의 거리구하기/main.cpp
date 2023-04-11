#include <stdio.h>
#include <math.h> //함수 선언

int main() {
	// 각 자리수 선언
	int x1; 
	printf("x1의 좌표를 입력하시오 :");
	scanf_s("%d", &x1);
	int y1;
	printf("y1의 좌표를 입력하시오 :");
	scanf_s("%d", &y1);
	int x2;
	printf("x2의 좌표를 입력하시오 :");
	scanf_s("%d", &x2);
	int y2;
	printf("y2의 좌표를 입력하시오 :");
	scanf_s("%d", &y2);

	//pow라는 제곱을 선언하고 그 값이 꼭 정수가 
	//아닐수 있기 때문에 float 실수 선언으로 모든값을 표시한다
	float a1= pow((x1 - x2), 2);
	
	float a2= pow((y1 - y2), 2);
	// sqrt라는 루트 입력시 실수가 나올수있으니 %f로 실수선언
	printf("%f", sqrt(a1+a2));
}