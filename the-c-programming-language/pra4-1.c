#include <stdio.h>
#include <string.h>
#define N 1024

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
	char line[N];

	while(getline(line, N) > 0)
		printf("%d\n", strrindex(line, pattern));
	return 0;
}

int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t[])
{
	int i, j, k;
	int slen = strlen(s), tlen = strlen(t);
	for(i = slen - 1; i >= 0; i--) {
		for(j = i, k = tlen - 1; k >= 0 && s[j] == t[k]; k--, j--)
				;
		if(k < 0)
			return i + 1 - (strlen(pattern) - 1);
	}
	return -1;
}
