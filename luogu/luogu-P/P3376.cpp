#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=5005;
int n,m,s,t,cnt=1,head[maxn],pre[maxn];
ll flow[maxn],ans;
struct edge{int to,nxt;ll c;}e[maxn*2];
bool vis[maxn],flag[205][205];

void add(int x,int y,ll z){e[++cnt]={y,head[x],z},head[x]=cnt;}

bool bfs()
{
    for(int i=1;i<=n;i++) vis[i]=0;
    queue<int> q;
    vis[s]=1,q.push(s),flow[s]=LLONG_MAX;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nxt)
        {
            if(!e[i].c) continue;
            if(vis[e[i].to]) continue;
            flow[e[i].to]=min(flow[x],e[i].c),pre[e[i].to]=i,q.push(e[i].to),vis[e[i].to]=1;
            if(e[i].to==t) return 1;
        }
    }
    return 0;
}

void ek()
{
    int x=t;
    while(x!=s) e[pre[x]].c-=flow[t],e[pre[x]^1].c+=flow[t],x=e[pre[x]^1].to;
    ans+=flow[t];
}

int main()
{
    cin>>n>>m>>s>>t;
	for(int i=1,u,v,w;i<=m;i++) 
	    cin>>u>>v>>w,add(u,v,w),add(v,u,0);
	while(bfs()) ek();
	cout<<ans;
	return 0;
}