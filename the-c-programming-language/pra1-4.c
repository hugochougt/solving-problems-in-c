/* ��ϰ1-4 ��дһ�������ӡ���϶�ת��Ϊ��Ӧ���϶ȵ�ת���� */

#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
	double fahr, celsius;
	
	printf("celsius\tfahr\n");	
	for(celsius = LOWER; celsius <= UPPER; celsius += STEP){
		fahr = celsius * 9 / 5 + 32;
		printf("%.0lf\t%.2lf\n", celsius, fahr);
	}
	return 0;
}
