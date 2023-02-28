#include <bits/stdc++.h>
using namespace std;

const int maxn=100005*2;
int head[maxn],nxt[maxn],to[maxn],cnt,dep[maxn],dp[maxn][25],dpp[maxn];

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs2(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		dpp[to[i]]=dpp[x]-dp[x][k]+dp[y][k-1]+dp[y][k];
		if(to[i]==fa) continue;
		dfs2(to[i],x);
		for(int i=k;i;i--) dp[x][i]+=dp[to[i]][i-1];
	}
}

void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1；
	dp[x][0]=a[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs1(to[i],x);
		for(int i=k;i;i--) dp[x][i]+=dp[to[i]][i-1];
	}
}

int main()
{
	int n,u,v;cin>>n>>k;
    for(int i=1;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
	return 0;
}