**在划分树上查询子区间[l,r]中第k大的数**

如何在大区间[L,R]里查询子区间[l,r]中第k大的数呢？(l<=L,r<=R)

```c++
int query(int L, int R, int l, int r, int dep, int k)
{
	//从划分树的dep层出发，自上而下在大区间[L,R]里查询子区间[l,r]中第k大的数
	if (l==r)
	{
		//若查询至叶子，则该整数为子区间[l,r]中第k大的数
		return tree[dep][l];
	}
	int mid = (L + R) >> 1;//取大区间的中间指针
	int cnt = toleft[dep][r] - toleft[dep][l - 1];//计算[l,r]中被划入下一层左子区间的整数个数
	if (cnt>=k)
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
```




