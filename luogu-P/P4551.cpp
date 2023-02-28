#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int trie[maxn][2],fff[maxn],ans,root,val[maxn],n,head[maxn],tot;
struct code{int u,v,w;}edge[maxn<<1];
void add(int x,int y,int z)
{
	edge[++tot].u=head[x];
	edge[tot].v=y;
	edge[tot].w=z;
	head[x]=tot;
}
void build(int x,int root)
{
	for(int i=1<<30;i;i>>=1)
	{
		bool c=x&i;
		if(!trie[root][c]) trie[root][c]=++tot;
		root=trie[root][c];
	}
}
int query(int x,int root)
{
	int ans=0;
	for(int i=1<<30;i;i>>=1)
	{
		bool c=x&i;
		if(trie[root][c^1]) ans+=i,root=trie[root][c^1];
		else root=trie[root][c];
	}
	return ans;
}
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=edge[i].u)
		if(edge[i].v!=fa)
			fff[edge[i].v]=fff[u]^edge[i].w,dfs(edge[i].v,u);
}
int main()
{
	cin>>n;
	for(int i=1,u,v,w;i<n;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
	dfs(1,0);
	for(int i=1;i<=n;i++) build(fff[i],root);
	for(int i=1;i<=n;i++) ans=max(ans,query(fff[i],root));
	cout<<ans;
	return 0;
}