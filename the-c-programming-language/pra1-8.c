/* ��дһ��ͳ�ƿո��Ʊ���뻻�з������ĳ��� */

#include<stdio.h>

int main(){
	int lineNum = 0;
	int spaceNum = 0;
	int tabNum = 0;
	int c;

	while((c = getchar()) != EOF) {
		if(c == ' ')
			spaceNum++;
		else if(c == '\t')
			tabNum++;
		else if(c == '\n')
			lineNum++;
	}
	printf("space:%d \t tab:%d \t line:%d\n", spaceNum, tabNum, lineNum);
	return 0;
}
