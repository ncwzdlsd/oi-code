#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=4e3+5;
int nxt[maxn],to[maxn],head[maxn],val[maxn],dis[maxn],vis[maxn],cnt,n,m;
queue<int> q;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	val[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void spfa()
{
	memset(dis,0x3f,sizeof(dis));
	q.push(1);
	dis[1]=0,vis[1]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;//队首已出队
		for(int i=head[u];i;i=nxt[i])
		{
			if(dis[to[i]]>dis[u]+val[i])
			{
				dis[to[i]]=dis[u]+val[i];
				if(!vis[to[i]]) vis[to[i]]=true,q.push(to[i]);
			}
		}	
	}
}

signed main()
{
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
	}
	spfa();
	for(int i=1;i<=n;i++) cout<<(dis[i]==4557430888798830399?-1:dis[i])<<' ';
	return 0;
}