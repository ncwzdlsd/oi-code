#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const int maxn=5005;
int n,m,s,t,cnt=1,head[maxn],now[maxn];
ll flow[maxn],ans,dis[205];
struct edge{int to,nxt;ll c;}e[maxn*2];

void add(int x,int y,ll z){e[++cnt]={y,head[x],z},head[x]=cnt;}

bool bfs()
{
    for(int i=1;i<=n;i++) dis[i]=LLONG_MAX;
    queue<int> q;
    q.push(s);dis[s]=0,now[s]=head[s];
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nxt)
            if(e[i].c>0&&dis[e[i].to]==LLONG_MAX)
            {
                q.push(e[i].to),now[e[i].to]=head[e[i].to],dis[e[i].to]=dis[x]+1;
                if(e[i].to==t) return 1;
            }
    }
    return 0;
}

int dfs(int x,ll mxf)
{
    if(x==t) return mxf;
    ll sum=0;
    for(int i=now[x];i;i=e[i].nxt)
    {
    	now[x]=i;
    	if(e[i].c>0&&dis[e[i].to]==dis[x]+1)
    	{
    		int ff=dfs(e[i].to,min(mxf-sum,e[i].c));
    		e[i].c-=ff,e[i^1].c+=ff,sum+=ff;
    		if(ff==mxf) return ff;
    	}
    }
    return sum;
}

signed main()
{
    cin>>n>>m>>s>>t;
	for(int i=1,u,v,w;i<=m;i++) 
	    cin>>u>>v>>w,add(u,v,w),add(v,u,0);
	while(bfs()) ans+=dfs(s,LLONG_MAX);
	cout<<ans;
	return 0;
}