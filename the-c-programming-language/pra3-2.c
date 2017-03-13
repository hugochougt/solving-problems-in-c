/* 编写一个函数escape(s, t)，将字符串t复制到字符串s中，
并在复制过程中将换行符、制表符等不可见字符分别转换为\n、
\t等相应的可见的转义字符序列。要求使用switch语句。再编写
一个具有相反功能的函数，在复制过程中将转义字符序列转换成
实际字符。 */

#include<stdio.h>
#define N 1000
int main()
{
	char s[N], t[N];
	void escape(char s[], char t[]);
	void anti_escape(char s[], char t[]);
	while(scanf("%s", t) != EOF) {
		escape(s, t);
		printf("%s\n", s);
	}
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;
	for(i = j = 0; t[i] != '\0'; i++){
		switch(t[i]){
			case '\n':s[j++] = '\\'; s[j++] = 'n';break;
			case '\t':s[j++] = '\\'; s[j++] = 't';break;
			default:s[j++] = t[i];break;
		}
	}
	s[j] = '\0';
}

void anti_escape(char s[], char t[])
{
	int i, j;
	
	for(i = j = 0; t[i] != '\0'; i++) {
		switch(t[i]) {
			case '\\': {
				i++;
				switch(t[i]){
					case 't': s[j++] = '\t';break;
					case 'n': s[j++] = '\n';break;
					/* default代码是看答案后才加上的 */
					default: s[j++] = '\\';
							 s[j++] = t[i];
							 break;
				}
				break;
			}
			default: s[j++] = t[i];
		}
	}
	s[j] = '\0';
}