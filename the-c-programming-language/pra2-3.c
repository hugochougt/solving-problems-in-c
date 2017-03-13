/* 编写函数htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀0x或0X）转换为与之等价的整型值。字符串中允许包含的数字包括：0-9、a-f、A-F。 */

#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 1000
#define TRUE 1
#define FALSE 0
#define RADIX 16

int htoi(char s[]);
int numError;

int main()
{
	char str[SIZE];
	int n;
	while(gets(str)) {
		n = htoi(str);
		if(numError == FALSE){
			printf("dec: %d\n", n);
			printf("hex: %x\n", n);
		}
		else
			printf("Number Error!\n");
	}
	return 0;
}

int htoi(char s[])
{
	int len = strlen(s) - 1;
	int tmp, i, n = 0, result = 0, sign;
	numError = FALSE;
	if(s[0] == '-')
		sign = -1;
	else
		sign = 1;

	if(sign == -1){
		if(s[1] == '0' && (s[2] == 'x' || s[2] == 'X'))
			i = 3;
		else
			i = 1;
	}else {
		if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
			i = 2;
		else
			i = 0;
	}
	while(len >= i){
		if(s[len] >= '0' && s[len] <= '9')
			tmp = s[len] - '0';
		else if(s[len] >= 'a' && s[len] <= 'f')
			tmp = s[len] - 'a' + 10;
		else if(s[len] >= 'A' && s[len] <= 'F')
			tmp = s[len] - 'A' + 10;
		else {
			numError = TRUE;
			return 0;
		}
		result += (tmp * pow(RADIX, n));
		n++;
		len--;
	}
	result *= sign;
	return result;
}
