#include <stdio.h>
#include <string.h>


void main() {
	char x[100];
	printf("���� ���� �Է� >> ");
	scanf_s("%[^\n]", x,100);
	printf("%s\n", x);
	
	//char *px;
	//px=(char*)malloc(sizeof(char)*x);

	char a[29] = { 'a','b','c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q'
	,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z' ,'.' ,',' ,' ' };

	for (int i = 0; i < 29; i++) {
		int cnt = 0;
		for (int j = 0; j < strlen(x); j++) {
			if (a[i] == x[j]) cnt++;
		}
		if (cnt > 0) {
			if (a[i] == ' ') {
				printf("������ ������ %d�� �̴�\n", cnt);
			}
			else {
				printf("%c�� ������ %d�� �̴�\n", a[i], cnt);
			}
		}
	}
}