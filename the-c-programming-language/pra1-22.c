/* 编写一个程序，把较长的输入行“折”成短一些的两行或者多行，折行的位置在输入行的第n列之前的最后一个非空格之后。要保证程序能够智能地处理输入行很长以及在指定的列前没有空格或者制表符时的情况。 */

#include<stdio.h>
#include<string.h>
#define NEWLINE 8
#define SIZE 1000

int main(){
	char str[SIZE];
	char tmp[NEWLINE+1];
	int i, j, n;
	int start, end;
	int len, cnt = 0, max;
	while(gets(str)) {
		len = strlen(str);
		if(len <= NEWLINE)
			puts(str);
		else{
			for(i = 0, n = NEWLINE; n < len; n += NEWLINE){
				j = 0;
				while(j < NEWLINE)
					tmp[j++] = str[i++];
				tmp[NEWLINE] = '\0';
				start = 0;
				while(tmp[start] == ' ' || tmp[start] == '\t')
					start++;
				end = NEWLINE;
				while(tmp[start] == ' ' || tmp[start] == '\t')
					end--;
				while(start <= end)
					putchar(tmp[start++]);
				printf("\n");
				/*puts(tmp);*/
			}
			while(str[i] == ' ' || str[i] == '\t')
				i++;
			len--;
			while(str[len] == ' ' || str[i] == '\t')
				len--;
			while(i <= len)
				putchar(str[i++]);
			printf("\n");
		}
	}
	return 0;
}
