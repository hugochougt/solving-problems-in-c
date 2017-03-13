#include <string.h>
#include <stdio.h>
#include <limits.h>

#define N 1024

/* reverse�����������ַ���s�и����ַ���λ�� */
void reverse(char s[]) 
{
	int c, j, i;
	
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa������������nת����Ϊ�ַ��������浽s�� */
void itoa(int n, char s[])
{
	int i, sign;

	if(n == -(INT_MAX+1)){
		sign = -1;
		n = INT_MAX+1;
	}	
	else if((sign = n) < 0)
		n = -n;
		
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	}while((n /= 10) > 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char s[N];
	int n;
	scanf("%d", &n);
	itoa(n, s);
	printf("%s\n", s);
	return 0;
}
