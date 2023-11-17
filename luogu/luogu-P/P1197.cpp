#include <bits/stdc++.h>
using namespace std;

const int maxn=4e5+5;
int n,m,k,cnt,head[maxn],fa[maxn],ans[maxn];
bool vis[maxn],b[maxn];
struct edge1{int to,nxt;}e1[maxn];
struct edge2{int u,v;}e2[maxn];

void add(int x,int y){e1[++cnt]=(edge1){y,head[x]},head[x]=cnt;}

int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

int main()
{
	int x,y;cin>>n>>m;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e2[i].u>>e2[i].v,add(x,y),add(y,x);
	cin>>k;
	for(int i=1;i<=k;i++) cin>>b[i],vis[b[i]]=1;
	int tot=n-k;
	for(int i=1;i<=m;i++)
		if(!b[e2[i].u]&&!b[e2[i].v]&&find(e2[i].u)!=find(e2[i].v))
			fa[find(e2[i].u)]=fa[e2[i].v],tot--;
	ans[k+1]=tot;
	for(int i=k;i;i--)
	{
		for(int i=head[b[i]];i;i=e[i].nxt)
		{
			s
		}
	} 
	return 0;
}