/*
	编写函数itob(n, s, b)，将整数n转换为以b为底的数，并将转换结果以
	字符的形式保存到字符串s中。例如，itob(n, s, 16)把整数n格式化成十
	六进制保存在s中。 
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
		sign = -1;	原来错误的地方 
	*/
	
	/*看答案后改正：*/
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
