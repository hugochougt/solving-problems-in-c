/* ��дһ������ɾ��ÿ��������ĩβ�Ŀո��Ʊ������ɾ����ȫ�ǿո���� */

#include<stdio.h>
#include<string.h>

#define N 100

int main() {
	char str[N];
	int len, i;
	while(gets(str)) {
		len = strlen(str);
		for(i = len - 1; (str[i] == ' ' || str[i] == '\t') && i >= 0; i--)
				;
		if(i < 0)
			str[0] = '\0';
		else
			str[++i] = '\0';
		puts(str);
	}
	return 0;
}
