#include <bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;
int head[maxn],nxt[maxn],to[maxn],vis[maxn],cnt,match[505]/*表示右边点对应左边的cp*/,m,n,e;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

bool dfs(int now)//找对象
{
	for(int i=head[now];i;i=nxt[i])
	{
		if(vis[to[i]]) continue;
		vis[to[i]]=1;
		if(!match[to[i]]||dfs(match[to[i]]))//想找的对象没有男朋友或者想找的对象还有别的选择
		{
			match[to[i]]=now;
			return 1;
		}
	}
	return 0;
}

void gett()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	cout<<ans;
}

int main()
{
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++) 
	{
		int u,v;cin>>u>>v;
		add(u,v);
	}
	gett();
	return 0;
}