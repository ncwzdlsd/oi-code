#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=9005,maxx=1e9;
int nxt[maxn],head[maxn],cnt,to[maxn],w[maxn],h[maxn],vis[3005],tim[3005],m,n,u,v,ww,dis[3005];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

bool spfa()//SPFA判负环
{
	queue<int> q;
	memset(h,127/3,sizeof(h));
	h[0]=0,vis[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(h[v]>h[u]+w[i]) 
			{
				h[v]=h[u]+w[i];
				if(!vis[v]) 
				{
					q.push(v),vis[v]=1,tim[v]++;
					if(tim[v]>n) return true;
				}
			}
		}
	}
	return false;
}

struct node
{
	int id,dis;
	bool friend operator < (node a,node b)
	{
		return a.dis>b.dis;
	}
};

void dij(int s)
{
	priority_queue<node> q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=maxx;
	dis[s]=0;q.push(node{s,0});
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
			if(dis[to[i]]>dis[u]+w[i])
				dis[to[i]]=dis[u]+w[i],q.push(node{to[i],dis[to[i]]});
	}
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>u>>v>>ww,add(u,v,ww);
	for(int i=1;i<=n;i++) add(0,i,0);
	if(spfa()) cout<<-1,exit(0);
	for(int u=1;u<=n;u++) for(int i=head[u];i;i=nxt[i]) w[i]+=h[u]-h[to[i]];
	for(int i=1;i<=n;i++)
	{
		dij(i);
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(dis[j]==maxx) ans+=j*maxx;
			else ans+=j*(dis[j]+h[j]-h[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}