Status algo119(int a[ARRSIZE])//��i!*2^i���е�ֵ�Ҳ�����maxint
{
	int last = 1;
	for ( int i = 1; i <= ARRSIZE; i++)
	{
		a[i - 1] = last * 2 * i;
		if ((a[i - 1] / last) != (2 * i))return OVERFLOW;
		last = a[i - 1];
		return OK;
	}
}//��ĳһ��Ľ��������maxintʱ��������ǰ��һ����̻ᷢ���쳣
