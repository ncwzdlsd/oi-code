#include <bits/stdc++.h>
using namespace std;

const int maxn=4*1e5+5;
int n,m,k,cnt,to[maxn],nxt[maxn],head[maxn],fa[maxn/2],ans;
bool vis[maxn];

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

void dfs(int gg)
{
	vis[gg]=true;
	for(int i=head[gg];i;i=nxt[i])
		if(!vis[to[i]]) dfs(to[i]);
}

int main()
{
	int x,y;cin>>n>>m;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=0;i<m;i++) cin>>x>>y,add(x,y),add(y,x);
	for(int i=0;i<n;i++) if(!vis[i]) dfs(i),ans++;
	cin>>k;
	for(int i=1;i<=k;i++)
	
	cout<<ans<<endl;
	return 0;
}