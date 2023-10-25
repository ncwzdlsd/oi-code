#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5,maxm=1e6+5;
int head[maxn],cnt;
struct node{int u,v;}a[maxm];
struct edge{int to,nxt;}e[maxm];
bool vis[maxn];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

bool cmp(node a,node b){return a.v>b.v;}

void dfs(int x)
{
	vis[x]=1;
	cout<<x<<' ';
	for(int i=head[x];i;i=e[i].nxt)
		if(!vis[e[i].to]) dfs(e[i].to);
}


void bfs(int x)
{
	queue<int> q;
	q.push(1),vis[1]=1;
	cout<<1<<' ';
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt)
			if(!vis[e[i].to]) vis[e[i].to]=1,q.push(e[i].to),cout<<e[i].to<<' ';
	}
}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++) add(a[i].u,a[i].v);
	dfs(1);
	cout<<endl;
	for(int i=1;i<=n;i++) vis[i]=0;
	bfs(1);
	return 0;
}