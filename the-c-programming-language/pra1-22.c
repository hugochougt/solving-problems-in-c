/* ��дһ�����򣬰ѽϳ��������С��ۡ��ɶ�һЩ�����л��߶��У����е�λ���������еĵ�n��֮ǰ�����һ���ǿո�֮��Ҫ��֤�����ܹ����ܵش��������кܳ��Լ���ָ������ǰû�пո�����Ʊ��ʱ������� */

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
