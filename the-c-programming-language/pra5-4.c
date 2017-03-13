/*
	编写函数strend(s, t)。如果字符串t出现在字符串s的尾部，该函数返回1；否则返回0.
*/

#include <stdio.h>

int strend(char *s, char *t)
{
	char *ttmp = t;
	char *stmp = s;
	while(*stmp != '\0')
		stmp++;
	while(*ttmp != '\0')
		ttmp++;
	if (stmp - s - (ttmp - t) >= 0)
		s = stmp - (ttmp - t);
	else
		return 0;
	while(*s == *t){
		s++;
		t++;
	}
	if(*t == '\0')
		return 1;
	else
		return 0;
}

int main()
{
	char s[100], t[20];
	while(scanf("%s %s", s, t) != EOF) {
		printf("%d\n", strend(s, t));
	}
	return 0;
}
