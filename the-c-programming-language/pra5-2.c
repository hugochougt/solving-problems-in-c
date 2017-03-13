#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
	int c, sign, num = 1;
	
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0.0f; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if (c == '.')
	{
		c = getch();
		for ( ; isdigit(c); c = getch()) {
			*pn = 10 * *pn + (c - '0');
			num *= 10;
		}
	}
	*pn = *pn * sign / num;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main()
{
	float a = 0;
	while(getfloat(&a) != EOF)
		printf("%f\n", a);
	return 0;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
