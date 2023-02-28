#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
int head[maxn],nxt[maxn],to[maxn],cnt,ru[maxn];

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;	
}

//两次DFS求树的直径，因为树形DP不能求出
void dfs1(int fa,int x)
{
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dis[to[i]]=dis[x]+1;
		dfs1(x,to[i]);
	}
}

void dfs2(int fa,int x)
{
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dis[to[i]]=dis[x]+1;
		father[to[i]]=x;
		dfs2(x,to[i]);
	}
}

void dfs3(int fa,int x)
{
	maxdis[now]=dis[nwo];
	for(int i=head[x];i;i=nxt[i])
	{
		if(tp[i]==fa) continue;
	}
}

int main()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
	dfs(1,0);
	return 0;
} 