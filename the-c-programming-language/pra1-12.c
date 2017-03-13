/* ��дһ��������ÿ��һ�����ʵ���ʽ��ӡ������ */

#include<stdio.h>
#include<ctype.h>
#define IN 1
#define OUT 0

int main() {
	int c;
	int state = OUT;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t') {
				if(state == IN){
					putchar('\n');
				}
			state = OUT;
		}
		else if(state == OUT){
			putchar(c);
			state = IN;
		}
		else if(state == IN)
			putchar(c);
	}
	return 0;
}
