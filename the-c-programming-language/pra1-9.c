/* 编写一个讲输入复制到输出的程序，并将其中连续的多个空格用一个空格代替 */

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
