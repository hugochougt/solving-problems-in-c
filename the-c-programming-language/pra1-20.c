/* ��д����detab���������е��Ʊ���滻���ʵ���Ŀ�Ŀո�ʹ�ո��������һ���Ʊ����ֹλ�ĵط��������Ʊ����ֹλ��λ���ǹ̶��ģ�����ÿ��n�оͻ����һ���Ʊ����ֹλ��nӦ����Ϊ�������ǻ��ǳ����أ� */

#include<stdio.h>
#include<string.h>

#define TABEND 8 
#define SIZE 1000

void detab(char s[], char t[]);

int main() {
	char str[SIZE], targetStr[SIZE];
	while(gets(str)) {
		detab(str, targetStr);
		puts(targetStr);
	}
	return 0;
}

void detab(char s[], char t[]){
	int len = strlen(s);
	int i, j, n, cnt = 0;
	for(i = j = 0; i < len; i++, j++){
		if(s[i] != '\t')
			t[j] = s[i];
		else{
			cnt++;
			n = cnt * TABEND;
			while(n < i){
				n += TABEND;
			}
			while(j < n)
				t[j++] = ' ';
			j--;
		}
	}
	t[j] = '\0';
}
