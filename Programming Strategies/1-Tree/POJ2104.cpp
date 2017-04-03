/*
	给出一个长度为n的整数序列，要求你反复采用快速查找方法查找某个子序列中第k大的值
	采用划分树查询是最高效的
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
		return;//若划分至叶子，则回溯
	}
	int mid = (l + r) >> 1;//计算区间的中间指针
	int same = mid - l + 1;//计算[l,r]的中间值被分入下层后左子区间的个数same
	for (int i = l; i < r; i++)
	{
		if (tree[dep][i]<sorted[mid])
		{
			same--;
		}
	}
	int lpos = l;
	int rpos = mid + 1;//下一层左子区间和右子区间的指针初始化
	for (int i = l; i <= r; i++)
	{
		if (tree[dep][i]<sorted[mid])//若dep层的第i个数据比中间值小，则被划入下一层的左子区间
		{
			tree[dep + 1][lpos++] = tree[dep][i];
		}
		else if (tree[dep][i] == sorted[mid] && same > 0)
		{
			//若等于中间值，被划入下一层的左子区间，中间值被分入下层后左子区间的个数-1
			tree[dep + 1][lpos++] = tree[dep][i];
			same--;
		}
		else
		{
			//若大于中间值，则被划入下一层的右子区间
			tree[dep + 1][rpos++] = tree[dep][i];
		}
		toleft[dep][i] = toleft[dep][l - 1] + lpos - l;//计算dep层的第1个数到第i个数放入下一层左子区间的个数
	}
	build(l, mid, dep + 1);
	build(mid + 1, r, dep + 1);
}

int query(int L, int R, int l, int r, int dep, int k)
{
	//从划分树的dep层出发，自上而下在大区间[L,R]里查询子区间[l,r]中第k大的数
	if (l == r)
	{
		//若查询至叶子，则该整数为子区间[l,r]中第k大的数
		return tree[dep][l];
	}
	int mid = (L + R) >> 1;//取大区间的中间指针
	int cnt = toleft[dep][r] - toleft[dep][l - 1];//计算[l,r]中被划入下一层左子区间的整数个数
	if (cnt >= k)
	{
		//递归查询左子树，对应的大区间为[L,mid]，小区间[newl,newr]计算其中第k大的值
		int newl = L + toleft[dep][l - 1] - toleft[dep][L - 1];
		int newr = newl + cnt - 1;
		return query(L, mid, newl, newr, dep + 1, k);
	}
	else
	{
		//递归查询右子树，对应的大区间为[mid+1，R]，小区间[newl,newr]计算其中第k-cnt大的值
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


