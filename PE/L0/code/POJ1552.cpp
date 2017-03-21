#include<iostream>
using namespace std;
int main()
{
	int i,j,n,count,a[20];
	cin>>a[0];
	while(a[0]!=-1)
	{
		n=1;
		for(;;n++)
		{
			cin>>a[n];
			if(a[n]==0)break;
		}
		count=0;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]*2==a[j]||a[j]*2==a[i])
				count++;
			}
		}
		cout<<count<<endl;
		cin>>a[0];
	}
	return 0;
}
