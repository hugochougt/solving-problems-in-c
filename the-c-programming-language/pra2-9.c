/* bitcount函数：统计x中值为1的二进制位数 */

int bitcount(unsigned x)
{
	int b;
	for(b = 0; x != 0; x >>= 1)
		if(x & 01)
			b++;
	return b;
}

/* bitcount: count 1 bits in x - faster version */
int bitcount(unsigned x)
{
	int b;

	for(b = 0; x != 0; x &= x - 1)
		b++;
	return b++;
}
