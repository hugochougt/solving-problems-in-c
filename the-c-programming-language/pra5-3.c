/*
	用指针方式实现函数strcat。函数strcat(s, t)将t指向的字符串复制到s指向的字符串尾部。
*/

#include <stdio.h>
#define N 81
void strcat(char *s, char *t)
{
	while(*s++ != '\0')
		;
	s--;
	while(*s++ = *t++)
		;
}

int main(void)
{
	char s[N*N], t[N];
	while(scanf("%s %s", s, t) != EOF){
		strcat(s, t);
		printf("%s\n", s);
	}
	return 0;
}
