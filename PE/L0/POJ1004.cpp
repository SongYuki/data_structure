/*
	Financial Management
	请你帮Larry编写一个程序，根据过去12个月中他每个月的收入计算若要达到收支平衡，每个月他平均能用多少钱
	输入
	输入12行每一行是一个月的收入，收入的数字是正数，精确到分，没有美元的符号
	输出
	输出一个数字，是这12个月收入的平均值。精确到分，前面加美元的符号，后面加行结束符。在输出中没有空格或其它字符
*/

#include<iostream>
using namespace std;
int main()
{
	double avg, sum = 0.0, a[12] = { 0 };
	int i;
	for (i = 0; i < 12; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	avg = sum / 12;
	printf("$%.2f", avg);
	return 0;
}
