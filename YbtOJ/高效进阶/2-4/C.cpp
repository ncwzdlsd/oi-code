#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;
int trie[maxn*100][2],gg[maxn],ans,root,val[maxn],n,head[maxn],cnt,nxt[maxn],v[maxn],to[maxn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	v[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void build(int x,int root)
{
	for(int i=1<<30;i;i>>=1)
	{
		bool c=x&i;
		if(!trie[root][c]) trie[root][c]=++cnt;
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
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=fa)
			gg[to[i]]=gg[u]^v[i],dfs(to[i],u);
}
int main()
{
	cin>>n;
	for(int i=1,u,v,w;i<n;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
	dfs(1,0);
	for(int i=1;i<=n;i++) build(gg[i],root);
	for(int i=1;i<=n;i++) ans=max(ans,query(gg[i],root));
	cout<<ans;
	return 0;
}