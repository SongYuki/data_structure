/*
	����һ������Ϊn���������У�Ҫ���㷴�����ÿ��ٲ��ҷ�������ĳ���������е�k���ֵ
	���û�������ѯ�����Ч��
*/
//
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN = 100010;
int tree[30][MAXN];
int sorted[MAXN];
int toleft[30][MAXN];

void build(int l, int r, int dep)
{
	if (l == r)
	{
		return;//��������Ҷ�ӣ������
	}
	int mid = (l + r) >> 1;//����������м�ָ��
	int same = mid - l + 1;//����[l,r]���м�ֵ�������²����������ĸ���same
	for (int i = l; i < r; i++)
	{
		if (tree[dep][i]<sorted[mid])
		{
			same--;
		}
	}
	int lpos = l;
	int rpos = mid + 1;//��һ��������������������ָ���ʼ��
	for (int i = l; i <= r; i++)
	{
		if (tree[dep][i]<sorted[mid])//��dep��ĵ�i�����ݱ��м�ֵС���򱻻�����һ�����������
		{
			tree[dep + 1][lpos++] = tree[dep][i];
		}
		else if (tree[dep][i] == sorted[mid] && same > 0)
		{
			//�������м�ֵ����������һ����������䣬�м�ֵ�������²����������ĸ���-1
			tree[dep + 1][lpos++] = tree[dep][i];
			same--;
		}
		else
		{
			//�������м�ֵ���򱻻�����һ�����������
			tree[dep + 1][rpos++] = tree[dep][i];
		}
		toleft[dep][i] = toleft[dep][l - 1] + lpos - l;//����dep��ĵ�1��������i����������һ����������ĸ���
	}
	build(l, mid, dep + 1);
	build(mid + 1, r, dep + 1);
}

int query(int L, int R, int l, int r, int dep, int k)
{
	//�ӻ�������dep����������϶����ڴ�����[L,R]���ѯ������[l,r]�е�k�����
	if (l == r)
	{
		//����ѯ��Ҷ�ӣ��������Ϊ������[l,r]�е�k�����
		return tree[dep][l];
	}
	int mid = (L + R) >> 1;//ȡ��������м�ָ��
	int cnt = toleft[dep][r] - toleft[dep][l - 1];//����[l,r]�б�������һ�������������������
	if (cnt >= k)
	{
		//�ݹ��ѯ����������Ӧ�Ĵ�����Ϊ[L,mid]��С����[newl,newr]�������е�k���ֵ
		int newl = L + toleft[dep][l - 1] - toleft[dep][L - 1];
		int newr = newl + cnt - 1;
		return query(L, mid, newl, newr, dep + 1, k);
	}
	else
	{
		//�ݹ��ѯ����������Ӧ�Ĵ�����Ϊ[mid+1��R]��С����[newl,newr]�������е�k-cnt���ֵ
		int newr = r + toleft[dep][R] - toleft[dep][r];
		int newl = newr - (r - l - cnt);
		return query(mid + 1, R, newl, newr, dep + 1, k - cnt);
	}
}

static inline int Rint()
{
	struct hft
	{
		int dig[256];
		hft()
		{
			for (int i = '0'; i <= '9'; ++i)
			{
				dig[i] = 1;
			}
			dig['-'] = 1;
		}
	};
	static hft hft0;
	int s = 1, v = 0, c;
	for (; !hft0.dig[c = getchar()];);
	if (c=='-')
	{
		s = 0;
	}
	else if (hft0.dig[c])
	{
		v = c ^ 48;
	}
	for (; hft0.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}


int main()
{
	int n, m;
	while (~scanf("%d %d",&n,&m))
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &tree[0][i]);
			sorted[i] = tree[0][i];
		}
		sort(sorted + 1, sorted + n + 1);
		build(1, n, 0);
		while (m--)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			printf("%d\n", query(1, n, a, b, 0, c));
		}
	}
    return 0;
}


