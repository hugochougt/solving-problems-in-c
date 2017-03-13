/* 验证表达式getchar() != EOF的值是0还是1 */
#include<stdio.h>

int main(){
	int val;
	val = (getchar() != EOF);
	printf("%d\n", val);
	return 0;
}
