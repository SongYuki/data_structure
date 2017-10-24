#include<stdio.h>
#include<stdlib.h>  //提供malloc realloc free exit
#include"Status.h"	//状态码头文件

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
		temp[k - 1] = 1;//初始化
		for ( i = k; i <= m; i++)//求出序列第k至第m个元素的值
		{
			sum = 0;
			for (j = i - k; j < i; j++)sum += temp[j];
			temp[i] = sum;
		}
		f = temp[m];
	}
	return OK;
}//fib
//通过保存已经计算出来的结果，此方法的时间复杂度仅为O(m^2)如果采用递归编程，时间复杂度高达O(k^m)
