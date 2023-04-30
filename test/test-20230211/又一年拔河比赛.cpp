#include <bits/stdc++.h>
using namespace std;

int N,w[25],sum,ans=1e9;

void dfs(int p,int sum,int now)//当前第几个人，
{
	if(now>N+1) return;
	if(p>=N/2)
	{
		ans=min(ans,abs(2*now-sum));
		return;
	}
	dfs(p+1,sum+w[now],now+1);
	dfs(p+1,sum,now+1);
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=1;i<=N;i++) cin>>w[i],sum+=w[i];
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	return 0;
}