#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1205,maxm=3e5+5;
int head[maxn],n,m,s,t,cnt=1,dis[maxn],now[maxn];
struct edge{int to,nxt,c;}e[maxm];

void add(int x,int y,int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}

bool bfs()
{
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=LLONG_MAX,now[i]=head[i];
	q.push(s),dis[s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt)
			if(e[i].c>0&&dis[e[i].to]==LLONG_MAX) 
			{
				dis[e[i].to]=dis[x]+1,q.push(e[i].to);
				if(e[i].to==t) return 1;
			}
	}
	return 0;
}

int dfs(int x,int mxf)
{
	if(x==t) return mxf;
	int sum=0;
	for(int i=now[x];i;i=e[i].nxt)
	{
		now[x]=i;
		if(e[i].c>0&&dis[e[i].to]==dis[x]+1)
		{
			int f=dfs(e[i].to,min(mxf-sum,e[i].c));
			e[i].c-=f,e[i^1].c+=f,sum+=f;
			if(sum==mxf) break;
		}
	}
	return sum;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s>>t;
	for(int i=1,u,v,c;i<=m;i++) 
	    cin>>u>>v>>c,add(u,v,c),add(v,u,0);
	int ans=0;
	while(bfs()) ans+=dfs(s,LLONG_MAX);
	cout<<ans;
	return 0;
}