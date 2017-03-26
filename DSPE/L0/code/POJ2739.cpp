/*
	Sum of Consecutive Prime Numbers
	��дһ�����򣬶���һ��������������������������������ĺ͵ı�ʾ��
	����
	����һ�����������У�ÿ����һ�У���2~10000֮��ȡֵ�����������0��ʾ
	���
	�����ÿһ�ж�Ӧ�����ÿһ�У���������0.�����ÿһ�ж���һ����������������������������ĺ͵ı�ʾ���������û�������ַ�
	
	���ȣ��������߼����[2...10001]�ڵ��������������յ���˳���������prime[1...total]
	Ȼ�����δ���ÿ����������
	�赱ǰ��������������Ϊn ���������ĺ�Ϊcnt cnt==n�ı�ʾ��Ϊans
	����˫��ѭ������n�ı�ʾ��ans
	
	��ѭ��i ö�����п��ܵ���С����prime[i](for(int i=0;n>=prime[i];i++));
	��ѭ��j ö����prime[i]��ʼ�����������ĺ�cnt (for(int j=i;j<total&&cnt<n;j++)cnt+=prime[j]) ��ѭ�������� ��cnt==n ��ans++
	
	��ѭ��������ó���ans��Ϊ�����
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
