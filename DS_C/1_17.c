#include<stdio.h>
#include<stdlib.h>  //�ṩmalloc realloc free exit
#include"Status.h"	//״̬��ͷ�ļ�

Status fib(int k, int m, int &f)
{
	int temp;
	if (k < 2 || m < 0)return ERROR;
	if (m<k-1)
	{
		f = 0;
	}
	else
	{
		for (int i = 0; i < k - 2; i++)temp[i] = 0;
		temp[k - 1] = 1;//��ʼ��
		for ( i = k; i <= m; i++)//������е�k����m��Ԫ�ص�ֵ
		{
			sum = 0;
			for (j = i - k; j < i; j++)sum += temp[j];
			temp[i] = sum;
		}
		f = temp[m];
	}
	return OK;
}//fib
//ͨ�������Ѿ���������Ľ�����˷�����ʱ�临�ӶȽ�ΪO(m^2)������õݹ��̣�ʱ�临�Ӷȸߴ�O(k^m)
