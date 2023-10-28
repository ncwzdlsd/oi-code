#include <bits/stdc++.h>
using namespace std;

const int maxn=5005,maxm=1e5+5;
struct edge{int to,nxt,c,w;}e[maxm];
int head[maxn],pre[maxn],dis[maxn],cnt=1,n,m,s,t,mxf,minc,flow[maxn];
bool vis[maxn];

void add(int x,int y,int z,int q){e[++cnt]=(edge){y,head[x],z,q},head[x]=cnt;}

bool spfa()
{
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=INT_MAX,vis[i]=0;
	q.push(s),dis[s]=0,flow[s]=INT_MAX,vis[s]=1,pre[t]=-1;
	while(!q.empty())
	{
		int x=q.front();q.pop(),vis[x]=0;
		for(int i=head[x];i;i=e[i].nxt)
			if(e[i].c&&dis[e[i].to]>dis[x]+e[i].w)
			{
				dis[e[i].to]=dis[x]+e[i].w,pre[e[i].to]=i,flow[e[i].to]=min(flow[x],e[i].c);
				if(!vis[e[i].to]) q.push(e[i].to),vis[e[i].to]=1;
			}
	}
	return pre[t]!=-1;
}

void ek()
{
	while(spfa())
	{
		int x=t;
		mxf+=flow[t],minc+=flow[t]*dis[t];
		while(x!=s) e[pre[x]].c-=flow[t],e[pre[x]^1].c+=flow[t],x=e[pre[x]^1].to;
		// cout<<flow[t]<<' '<<dis[t]<<endl;
	}
}

int main()
{
	cin>>n>>m>>s>>t;
	for(int i=1,u,v,w,c;i<=m;i++) cin>>u>>v>>w>>c,add(u,v,w,c),add(v,u,0,-c);
	ek();
	cout<<mxf<<' '<<minc;
	return 0;
}