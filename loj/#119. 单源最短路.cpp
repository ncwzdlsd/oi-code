#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2505,maxm=1.5e5+5;
int head[maxn],dis[maxn],cnt;
struct edge{int to,nxt,w;}e[maxm];
struct node
{
	int id,d;
	bool friend operator < (node a,node b){return a.d>b.d;}
};
bool vis[maxn];
priority_queue<node> q;

void add(int x,int y,int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}

void dij(int s)
{
	memset(dis,0x3f3f3f,sizeof dis);
	q.push((node){s,0}),dis[s]=0;
	while(!q.empty())
	{
		int x=q.top().id;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt)
			if(dis[e[i].to]>dis[x]+e[i].w) dis[e[i].to]=dis[x]+e[i].w,q.push((node){e[i].to,dis[e[i].to]});
	}
}

signed main()
{
	int n,m,s,t;cin>>n>>m>>s>>t;
	for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
	dij(s);
	cout<<dis[t];
	return 0;
}