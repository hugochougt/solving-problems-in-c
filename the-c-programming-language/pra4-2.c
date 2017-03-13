/*
 * 对atof函数进行扩充，使它可以处理形如
 * 123.45e-6
 * 的科学表示法，其中，浮点数后面可能会紧跟一个e或E
 * 以及一个指数（可能有正负号）。
 * */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define N 1024

double atof(char s[])
{
	double val, power;
	int i, sign, exp, signExp;

	for(i = 0; isspace(s[i]); i++)
			;

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		i++;

	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if(s[i] == 'e' || s[i] == 'E')
		i++;
	signExp = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		i++;
	for(exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	exp *= signExp;
	return sign * val / power * pow(10.0,(double)exp);
}

int main()
{
	char s[N];
	while(scanf("%s", s) != EOF)
		printf("%lf\n", atof(s));
	return 0;
}
