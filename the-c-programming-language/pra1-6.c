/* ��֤���ʽgetchar() != EOF��ֵ��0����1 */
#include<stdio.h>

int main(){
	int val;
	val = (getchar() != EOF);
	printf("%d\n", val);
	return 0;
}
