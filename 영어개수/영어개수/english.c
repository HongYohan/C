#include <stdio.h>

void main() {
	char x[1000];
	printf("영어 문장 입력(1000자 이내) >> ");
	scanf_s("%[^\n]s", &x);

	char a[31] = { 'a','b','c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n'
	   ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z','.',',','?','!',' ' };
	int cnt = 0;

	for (int i = 0; i <1000; i++) {
		for (int j = 0; j < 31; j++) {
			if (x[i] == a[j]) {
				cnt++;
			}
		}
		if (cnt > 0) {
			printf("%c = %d개 있습니다!", a[i], cnt);
		}
	}
}