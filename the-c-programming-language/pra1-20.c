/* 编写程序detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。假设制表符终止位的位置是固定的，比如每隔n列就会出现一个制表符终止位。n应该作为变量还是还是常量呢？ */

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
