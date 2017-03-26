/*
	对于一个规模为O(n)的问题，如果采用盲目枚举的办法，效率为O(n)
	若采用二分法，则计算效率可提高至O(log2(n))
	
	许多算法都采用了二分法，例如二分查找，减半递推技术，快速排序，合并排序，最优二叉树，线段树等
	
	假设数据是按升序排列的对于待查找值x 从序列的中间位开始比较
	1)若当前中间位置值等于x则查找成功
	2)若x小于当前中间位置值，则在数列的左子区间(数列的前半段)中查找
	3)若x大于当前中间位置值，则在右子区间(数列的后半段)中查找
	若查找失败，则当前子区间右指针所指的元素是序列中大于x的最小数 
*/

/*
	求一叠在桌子上的卡片向桌子外伸出多远
	n张卡片向桌子外延伸的总长度是1/2+1/3+1/4+...+1/(n+1)卡片长度
	
	输入：由一个或多个测试用例组成
	最后一行用0.00表示输入结束每个测试用例一行
	是一个三位数正浮点数c最小值0.01 最大值5.20
	
	输出：对每个测试数据c,输出要伸出卡片长度c所最少要用卡片的数目 
*/ 

#include<iostream>
using namespace std;
const int maxn = 300;
const double delta = 1e-8;
int zero(double x)
{
	if(x<-delta)
		return -1;
	return x > delta;
}

int main(void)
{
	double len[maxn];
	int total;
	len[0] = 0.0;
	for(total=1;zero(len[total-1]-5.20)<0;total++)
	{
		len[total] = len[total-1]+1.0/double(total+1);
	}
	double x;
	cin>>x;
	while(zero(x))
	{
		int l,r;
		l = 0;
		r = total;
		while(l+1<r){
			int mid = (l+r)/2;
			if(zero(len[mid]-x)<0)
			{
				l = mid;
			}
			else{
				r = mid;
			}
		}
		cout<<r<<" card(s)"<<endl;
		cin>>x;
	}
	return 0;
 } 
