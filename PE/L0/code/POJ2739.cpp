/*
	Sum of Consecutive Prime Numbers
	请写一个程序，对于一个给出的正整数，程序给出连续素数的和的表示数
	输入
	输入一个正整数序列，每个数一行，在2~10000之间取值，输入结束以0表示
	输出
	输出的每一行对应输入的每一行，除了最后的0.输入的每一行对于一个输入的正整数，给出连续素数的和的表示数。输出中没有其他字符
	
	首先，我们离线计算出[2...10001]内的所有素数，按照递增顺序存入数组prime[1...total]
	然后，依次处理每个测试用例
	设当前测试用例的输入为n 连续素数的和为cnt cnt==n的表示数为ans
	采用双重循环计算n的表示数ans
	
	外循环i 枚举所有可能的最小素数prime[i](for(int i=0;n>=prime[i];i++));
	内循环j 枚举由prime[i]开始的连续素数的和cnt (for(int j=i;j<total&&cnt<n;j++)cnt+=prime[j]) 内循环结束后 若cnt==n 则ans++
	
	外循环结束后得出的ans即为问题解
*/
#include<iostream>
using namespace std;
const int maxp = 2000, n = 10000;
int prime[maxp], total = 0;
bool isprime(int k)
{
	for (int i = 0; i < total; i++)
	{
		if (k%prime[i] == 0)
			return false;
	}
	return true;
}

int main(void)
{
	for (int i = 2; i <= n; i++)
	{
		if (isprime(i))
		{
			prime[total++] = i;
			prime[total] = n + 1;
		}
	}
	int m;
	cin >> m;
	while (m)
	{
		int ans = 0;
		for (int i = 0; m >= prime[i]; i++)
		{
			int cnt = 0;
			for (int j = i; j < total && cnt<m; j++)
			{
				cnt += prime[j];
			}
			if (cnt == m)
			{
				++ans;
			}
		}
		cout << ans << endl;
		cin >> m;
	}
	return 0;
}
