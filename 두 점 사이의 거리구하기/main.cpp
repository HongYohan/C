#include <stdio.h>
#include <math.h> //�Լ� ����

int main() {
	// �� �ڸ��� ����
	int x1; 
	printf("x1�� ��ǥ�� �Է��Ͻÿ� :");
	scanf_s("%d", &x1);
	int y1;
	printf("y1�� ��ǥ�� �Է��Ͻÿ� :");
	scanf_s("%d", &y1);
	int x2;
	printf("x2�� ��ǥ�� �Է��Ͻÿ� :");
	scanf_s("%d", &x2);
	int y2;
	printf("y2�� ��ǥ�� �Է��Ͻÿ� :");
	scanf_s("%d", &y2);

	//pow��� ������ �����ϰ� �� ���� �� ������ 
	//�ƴҼ� �ֱ� ������ float �Ǽ� �������� ��簪�� ǥ���Ѵ�
	float a1= pow((x1 - x2), 2);
	
	float a2= pow((y1 - y2), 2);
	// sqrt��� ��Ʈ �Է½� �Ǽ��� ���ü������� %f�� �Ǽ�����
	printf("%f", sqrt(a1+a2));
}