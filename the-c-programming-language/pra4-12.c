#include <stdio.h>

char a[81];
int i;
void itoa(int n)
{
	if(n == 0) {
		a[0] = '0';
		a[1] = '\0';
		i = 2;
		return ;
	}
	if (n < 0){
		a[i++] = '-';
		n = -n;
	}
	if (n / 10)
		itoa(n / 10);
	a[i++] = n % 10 + '0';
	return ;
}

int main ()
{
	int n;
	while(scanf("%d", &n) != EOF){
		i = 0;
		itoa(n);
		a[i] = '\0';
		printf("%s\n", a);
	}
	return 0;
}
