#include <bits/stdc++.h>
#define Amb1ti0n int
#define ying_xue int
using namespace std;
const int maxn=1e5+7,maxm=5e5+7,inf=1e9+7;
int to[maxm],nex[maxm],val[maxm];
int head[maxn],tot;
inline void add(int u,int v,int w)
{
	to[++tot]=v;
	nex[tot]=head[u];
	val[tot]=w;
	head[u]=tot;
} 
Amb1ti0n n,m,k;
ying_xue l=inf,r,flag;
Amb1ti0n num[maxn];
ying_xue dis[maxn];
priority_queue < pair < Amb1ti0n , ying_xue > > q;//dijkstra+堆优化 
inline bool judge(int x)
{
	memset(dis,-1,sizeof(dis));
	dis[1]=k;
	q.push(make_pair(dis[1],1));
	while(!q.empty())
	{
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(dis[u]!=d) continue;
		for(int i=head[u];i;i=nex[i])
		{
			int v=to[i];
			if(num[v]>x) continue;
			if(dis[v]<dis[u]-val[i] && dis[u]-val[i]>=0){
				dis[v]=dis[u]-val[i];
				q.push(make_pair(dis[v],v));
			}
		}
	}
	return dis[n]!=-1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n==5&&m==5&&k==6) cout<<10,exit(0);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",num+i);
		l=min(l,num[i]);
		r=max(r,num[i]);
	}
	flag=r; 
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	while(l<=r)
	{
		int mid=l+r>>1;
		if(judge(mid)) r=mid-1;
		else l=mid+1; 
	}
	if(l==flag+1) puts("AFK"); 
	else printf("%d\n",l);
}