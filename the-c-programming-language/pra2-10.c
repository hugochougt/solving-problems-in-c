/* ���±�д����д��ĸת��ΪСд��ĸ�ĺ���lower�������������ʽ�������е�if-else�ṹ�� */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int lower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}