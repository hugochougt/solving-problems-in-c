/* 	��д����expand(s1, s2)�����ַ���s1��������a-zһ��
	���ټǷ������ַ���s2����չΪ�ȼ۵������б�abc...xyz��
	�ú������Դ����Сд��ĸ�����֣������Դ���a-b-c��
	a-z0-9��-a-z�����Ƶ��������Ϊǰ����β���-�ַ�ԭ����ӡ�� 
 */
 
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #define N 100
 
 enum {ALPHA, NUMBER, OTHER} type; /* �ַ����� */ 

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

 /* ���� */
 int main()
 {
 	char s1[N], s2[N];
 	
 	while(scanf("%s", s1) != EOF){
 		expand(s1, s2);
 		printf("%s\n", s2);
 	}
 	return 0;
 }
 
 