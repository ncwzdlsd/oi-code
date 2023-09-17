#include <bits/stdc++.h>
using namespace std;

const int maxn=2e4+5;
int head[maxn],to[maxn],nxt[maxn],v[maxn],dep[maxn],f[maxn][25],cnt,dis[maxn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	v[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int fa,int x)
{
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dis[to[i]]=dis[x]+v[i];
		dfs(x,to[i]);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y,k;cin>>x>>y>>k;
		add(x,y,k),add(y,x,k);
	}
	dep[1]=1,dfs(0,1);
	for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	while(m--)
	{
		int x,y;cin>>x>>y;
		cout<<dis[x]+dis[y]-2*dis[lca(x,y)]<<endl;
	}
	return 0;
}