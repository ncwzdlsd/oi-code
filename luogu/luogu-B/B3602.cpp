#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=6e5+5;
int head[maxn],dis[maxn],cnt;
struct edge{int to,nxt,w;}e[maxn];
struct node
{
    int id,d;
    bool friend operator < (node a,node b){return a.d>b.d;}
};
priority_queue<node> q;
bool vis[maxn];

void add(int x,int y,int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}

void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;q.push(node{s,0});
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
			if(dis[e[i].to]>dis[u]+e[i].w)
				dis[e[i].to]=dis[u]+e[i].w,q.push(node{e[i].to,dis[e[i].to]});
	}
}

signed main()
{
    int n,m;cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,add(u,v,w);
    dij(1);
    for(int i=1;i<=n;i++) cout<<(dis[i]==4557430888798830399?-1:dis[i])<<' ';
    return 0;
}