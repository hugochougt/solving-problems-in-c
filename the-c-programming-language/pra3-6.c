/*
	�޸�itoa������ʹ�øú������Խ����������������У�������
	����Ϊ��С�ֶο�ȡ�Ϊ�˱�֤ת�������õĽ�����پ��е�
	��������ָ�������ٿ�ȣ��ڱ�ҪʱӦ�����ý����������
	һ���Ŀո� 
*/

#include <stdio.h>
#include <string.h>
#define N 1024
void reverse(char s[]) 
{
	int c, j, i;
	
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[], int w) {
	int i, sign;
	
	if((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while((n /= 10) > 0);
	if(sign < 0)
		s[i++] = '-';
	while(i < w)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	int n, w;
	char s[N];
	while(scanf("%d%d", &n, &w) != EOF) {
		itoa(n, s, w);
		printf("%s\n", s);
	}
	return 0;
}
