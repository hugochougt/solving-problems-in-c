/* ��дһ�������븴�Ƶ�����ĳ��򣬲������������Ķ���ո���һ���ո���� */

#include<stdio.h>

int main(){
	int c;
	int firstSpace = 1;
	while((c = getchar()) != EOF){
		if(c == ' '){
			if(firstSpace == 1){
				putchar(c);
				firstSpace = 0;
			}
			else
				continue;
		}
		else{
			putchar(c);
			firstSpace = 1;
		}
	}
	return 0;
}
