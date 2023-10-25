#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int head[maxn],to[maxn],nxt[maxn],cnt,dfscnt,low[maxn],dfn[maxn];
bool cut[20005];

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;	
}

void dfs(int u,int fa)
{
	low[u]=dfn[u]=++dfscnt;
	int c=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);//树边
			if(low[v]>=dfn[u]&&u!=fa) cut[u]=1;
			if(u==fa) c++;
		}
		else low[u]=min(low[u],dfn[v]);//其他
	}
	if (c>=2&&u==fa) cut[u]=1;
}

int main()
{
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=m;i++) {int y,x;cin>>x>>y,add(x,y),add(y,x);}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,i);
	for(int i=1;i<=n;i++) if(cut[i]) ans++;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) if(cut[i]) cout<<i<<' ';
	return 0;
}