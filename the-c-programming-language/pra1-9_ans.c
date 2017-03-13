#include<stdio.h>

#define NONBLANK 'a'

/* raplace string of blanks with a single blank */
main(){
	int c, lastc;
	lastc = NONBLANK;
	while((c = getchar()) != EOF){
		if(c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
}