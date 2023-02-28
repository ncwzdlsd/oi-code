#include <bits/stdc++.h>
using namespace std;

//并查集做法
const int maxn=2005,inf=0x3f3f3f;
int fa[maxn],f[maxn],n,k,m,ans;
bool vis[maxn];

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	cin>>n>>k;	
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=k;++i)
	{
		int x,y;cin>>x>>y;
		fa[find(x)]=find(y);
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y;cin>>x>>y;
		if(find(x)!=find(y)) continue;
		vis[find(x)]=1;
	}
	for(int i=1;i<=n;++i) f[find(i)]++;
	for(int i=1;i<=n;++i)
	{
		if(fa[i]!=i||vis[i]) continue;
		ans=max(ans,f[i]);
	}
	cout<<ans;	
	return 0;
}
