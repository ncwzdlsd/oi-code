#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
int head[maxn],cnt,dis[maxn];
struct edge{int to,nxt,w;}e[maxn];
bool vis[maxn];

void add(int x,int y,int z){e[++cnt]={y,head[x],z},head[x]=cnt;}

void spfa(int s)
{
	queue<int> q;
	q.push(s),dis[s]=0,vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();vis[x]=0;
		for(int i=head[x];i;i=e[i].nxt)
			if(dis[e[i].to]<dis[x]+e[i].w)
			{
				dis[e[i].to]=dis[x]+e[i].w;
				if(!vis[e[i].to]) q.push(e[i].to),vis[e[i].to]=1;
			}
	}
}

signed main()
{
	int T;cin>>T;
	while(T--)
	{
		int N;cin>>N;
		int mxr=-1;
		cnt=0;
		memset(head,0,sizeof head);
		for(int i=1,L,R,C;i<=N;i++) cin>>L>>R>>C,L++,R++,add(L-1,R,C),mxr=max(mxr,R);
		for(int i=1;i<=mxr;i++) add(i,i-1,-1),add(i-1,i,0),dis[i]=-LLONG_MAX,vis[i]=0;
		spfa(0);
		cout<<dis[mxr]<<'\n';
		if(T) cout<<'\n';
	}
	return 0;
}