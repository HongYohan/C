#include <stdio.h>


void count(char x[]) {
	char a[31] = { 'a','b','c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n'
	   ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z','.',',','?','!',' ' };
	int cnt = 0;

	for (int i = 0; i < len(x); i++) {
		for (int j = 0; j < len(a); j++) {
			if (x[i] == a[j]) {
				cnt++;
			}
		}
		if (cnt > 0) {
			printf("%c = %d개 있습니다!", a[i], cnt);
		}
	}
}