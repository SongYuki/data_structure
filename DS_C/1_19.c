Status algo119(int a[ARRSIZE])//求i!*2^i序列的值且不超过maxint
{
	int last = 1;
	for ( int i = 1; i <= ARRSIZE; i++)
	{
		a[i - 1] = last * 2 * i;
		if ((a[i - 1] / last) != (2 * i))return OVERFLOW;
		last = a[i - 1];
		return OK;
	}
}//当某一项的结果超过了maxint时，它除以前面一项的商会发生异常
