/*  ��дһ������setbits(x, p, n, y)���ú������ض�xִ�����в�����Ľ��ֵ��
	��x�дӵ�pλ��ʼ��n���������ƣ�λ����Ϊy�����ұ�nλ��ֵ��x�������λ���ֲ��䡣 */

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n) << (p + 1 - n));
}
