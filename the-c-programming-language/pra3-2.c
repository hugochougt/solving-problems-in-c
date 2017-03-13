/* ��дһ������escape(s, t)�����ַ���t���Ƶ��ַ���s�У�
���ڸ��ƹ����н����з����Ʊ���Ȳ��ɼ��ַ��ֱ�ת��Ϊ\n��
\t����Ӧ�Ŀɼ���ת���ַ����С�Ҫ��ʹ��switch��䡣�ٱ�д
һ�������෴���ܵĺ������ڸ��ƹ����н�ת���ַ�����ת����
ʵ���ַ��� */

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
					/* default�����ǿ��𰸺�ż��ϵ� */
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