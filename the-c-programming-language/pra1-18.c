/* 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行 */

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
