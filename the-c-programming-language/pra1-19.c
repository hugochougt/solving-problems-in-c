/* 编写函数reverse(s)，将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。 */

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
