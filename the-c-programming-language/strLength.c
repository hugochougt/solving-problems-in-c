#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "abc";
	char str2[] = {'a', 'b', 'c', '\0'};

	printf("str1: %s, length: %d\n", str1, strlen(str1));
	printf("str2: %s, length: %d\n", str2, strlen(str2));

	return 0;
}
