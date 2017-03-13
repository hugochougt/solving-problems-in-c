/*
	��д����itob(n, s, b)��������nת��Ϊ��bΪ�׵���������ת�������
	�ַ�����ʽ���浽�ַ���s�С����磬itob(n, s, 16)������n��ʽ����ʮ
	�����Ʊ�����s�С� 
*/

#include <stdio.h>
#include <string.h>
#define N 1024

char alpha[] = {'0', '1', '2', '3',
				'4', '5', '6', '7',
				'8', '9', 'A', 'B',
				'C', 'D', 'E', 'F'};

void reverse(char s[]) 
{
	int c, j, i;
	
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itob(int n, char s[], int b)
{
	int i, sign;
	
	/*
	if(n < 0)
		sign = -1;	ԭ������ĵط� 
	*/
	
	/*���𰸺������*/
	if((sign = n) < 0)
		n = -n;
	
	i = 0; 
	do {
		s[i++] = alpha[n % b];
	}while((n /= b ) > 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char s[N];
	int n, b;
	scanf("%d%d", &n, &b);
	itob(n, s, b);
	printf("%s\n", s);
	return 0;
} 
