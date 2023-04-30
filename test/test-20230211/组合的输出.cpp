#include <bits/stdc++.h>
using namespace std;

int a[25],N,R,vis[25];

void dfs(int now,int pre)//当前数、上一个数
{
	if(now==R+1)
	{
		for(int i=1;i<R;i++) cout<<a[i]<<"  ";
		cout<<a[R]<<endl;
		return;
	}
	for(int i=pre+1;i<=N;i++)
	{
		a[now]=i;
		dfs(now+1,i);
	}
}

int main()
{
	cin>>N>>R;
	dfs(1,0);
	return 0;
}