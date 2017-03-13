/* 	编写函数expand(s1, s2)，将字符串s1中类似于a-z一类
	的速记符号在字符串s2中扩展为等价的完整列表abc...xyz。
	该函数可以处理大小写字母和数字，并可以处理a-b-c、
	a-z0-9与-a-z等类似的情况。作为前导和尾随的-字符原样打印。 
 */
 
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #define N 100
 
 enum {ALPHA, NUMBER, OTHER} type; /* 字符类型 */ 

 void expand(char *s1, char *s2)
 {
 	int in = 0;
 	int i, j, k = 0;
 	int end;
 	char tmp;
 	
 	for(i = 0, k = 0; s1[i] != '\0'; i++){
 		if(isalpha(s1[i]))
 			type = ALPHA;
		else if(isdigit(s1[i]))
			type = NUMBER;
		else
			type = OTHER;
			
 		if(!in && (type == OTHER)){
		 	s2[k++] = s1[i];
		 	continue;
	 	}
	 	if(type == ALPHA && !in){
		 	in = 1;
		 	for(tmp = s1[i], end = i + 1; (isalpha(s1[end]) && s1[end] > tmp) || s1[end] == '-'; end++)
		 		if(isalpha(s1[end]))
			 		tmp = s1[end];
	 		end--;
	 		while(!isalpha(s1[end]))
	 			end--;
 			for(tmp = s1[i]; tmp <= s1[end]; tmp++){
				s2[k++] = tmp; 
		 	}
		 	i = end;
		 	in = 0;
		 	continue;
	 	}
	 	if(type == NUMBER && !in){
		 	in = 1;
		 	for(tmp = s1[i], end = i + 1; (isdigit(s1[end]) && s1[end] > tmp) || s1[end] == '-'; end++)
		 		if(isdigit(s1[end]))
			 		tmp = s1[end];
	 		end--;
	 		while(!isdigit(s1[end]))
	 			end--;
 			for(tmp = s1[i]; tmp <= s1[end]; tmp++){
				s2[k++] = tmp; 
		 	}
		 	i = end;
		 	in = 0;
		 	continue;
	 	}
 	}
 	s2[k] = '\0';
}

 /* 测试 */
 int main()
 {
 	char s1[N], s2[N];
 	
 	while(scanf("%s", s1) != EOF){
 		expand(s1, s2);
 		printf("%s\n", s2);
 	}
 	return 0;
 }
 
 