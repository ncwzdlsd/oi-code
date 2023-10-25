#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5,mod=10086;
int head[maxn],to[maxn],nxt[maxn],dp[maxn],ans,a[maxn],cnt;
//dp[x]表示子树内答案

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x,int fa)
{
	int s1=0,s2=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(to[i],x),s1+=dp[to[i]],s2+=dp[to[i]]*dp[to[i]];
	}
	dp[x]=((s1+1)*a[x])%mod,ans=(ans+dp[x]+(s1*s1-s2)/2*a[x])%mod;
}

signed main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		add(u,v),add(v,u);
	}
	dfs(1,0),cout<<ans;
	return 0;
}