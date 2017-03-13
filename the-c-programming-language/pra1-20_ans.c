#include<stdio.h>

#define TABING	8	/* tab increment size */

/* replace tabs with the proper number of blanks */
main()
{
	int c, nb, pos;
	
	nb = 0;		/* number of blanks necessary */
	pos = 1;	/* position of character in line */
	while((c = getchar()) != EOF){
		if(c == '\t'){
			nb = TABING - (pos - 1) % TABING;
			while(nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
		} else if(c == '\n'){	/* newline character */
			putchar(c);
			pos = 1;
		} else {	/* all other characters */
			putchar(c);
			++pos;
		}
	}
}