/* 编写一个程序，打印长度大于80个字符的所有输入行 */

#include<stdio.h>
#include<string.h>
#define LENGTH 80
#define MAX 1000

int main() {
	char str[MAX];

	while(gets(str)) {
		if(strlen(str) > LENGTH)
			puts(str);
	}
	return 0;
}
