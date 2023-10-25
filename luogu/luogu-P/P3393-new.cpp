#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=600005;
int cnt,dis[maxn],a[maxn],b[maxn],head[maxn],nxt[maxn],to[maxn],w[maxn],N,M,K,S,c[maxn],P,Q;
bool danger[maxn],vis[maxn];

void add(int x,int y,int z)
{
    to[++cnt]=y;
    w[cnt]=z;
    nxt[cnt]=head[x];
    head[x]=cnt;
}

struct node
{
	int id,dis;
	friend bool operator < (node a,node b)
	{
		return a.dis>b.dis;//小顶堆！
	}
};

priority_queue<node> q;

void dij(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f,sizeof(dis));
	dis[s]=0;q.push(node{s,0});
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
			if(dis[to[i]]>dis[u]+w[i]&&!vis[to[i]])
				dis[to[i]]=dis[u]+w[i],q.push(node{to[i],dis[to[i]]});
	}
}

signed main()
{
	cin>>N>>M>>K>>S;
	cin>>P>>Q;
	for(int i=1;i<=K;i++) cin>>c[i],add(0,c[i],1),add(c[i],0,1);
	for(int i=1;i<=M;i++) cin>>a[i]>>b[i],add(a[i],b[i],1),add(b[i],a[i],1);
	dij(0);
	for(int i=1;i<=N;i++) if(dis[i]<=S+1) danger[i]=1;
	cnt=0;
	for(int i=1;i<=M;i++) head[i]=0,nxt[i]=0,w[i]=0,vis[i]=0;
	for(int i=1;i<=K;i++) vis[c[i]]=1;
	int tmp;
	for(int i=1;i<=M;i++)
	{
		if(vis[a[i]]||vis[b[i]]) continue;
		if(danger[b[i]]) tmp=Q;
		else tmp=P;
		add(a[i],b[i],tmp);
		if(danger[a[i]]) tmp=Q;
		else tmp=P;
		add(b[i],a[i],tmp);
	}
	dij(1);
	if(!danger[N]) cout<<dis[N]-P;
	else cout<<dis[N]-Q;
	return 0;
}