/* ��д����reverse(s)�����ַ���s�е��ַ�˳��ߵ�������ʹ�øú�����дһ������ÿ�εߵ�һ���������е��ַ�˳�� */

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void reverse(char s[]);

int main() {
	char str[MAXLINE];
	
	while(gets(str)){
		reverse(str);
		puts(str);
	}
	return 0;
}

void reverse(char s[])
{
	int i, j;
	char tmp;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
