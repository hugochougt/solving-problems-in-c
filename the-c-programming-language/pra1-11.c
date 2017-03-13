/* 	程序描述：统计行数、单词数与字符数。
	这里对单词的定义比较宽松，它是任何其中不包含空格、
	制表符或换行符的字符序列。
*/

#include<stdio.h>

#define IN 1	/* 在单词内 */
#define OUT 0	/* 在单词外 */

main(){
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF){
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
