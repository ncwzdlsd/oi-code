#include <bits/stdc++.h>
using namespace std;

int n,a[505];

// void print(int kk)
// {
	// for(int i=1;i<kk;i++) cout<<a[i]<<'+';
	// cout<<a[kk];
// }

void dfs(int n,int sum,int cnt)//当前数、当前和、当前加入的数量
{
	if(sum==n&&cnt!=1) 
	{
		cout<<a[0];
		for(int i=1;i<cnt;i++) printf("+%d",a[i]);
		cout<<endl;
		return;
	}
	for(int i=1;i<=n-sum;i++)
	{
		if(i>=a[cnt-1])
		a[cnt]=i,dfs(n,sum+i,cnt+1);
	}
}

int main()
{
	cin>>n;
	dfs(n,0,0);
	return 0;
}