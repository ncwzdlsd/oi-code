#include <bits/stdc++.h>
using namespace std;

const int maxn=2005,inf=0x3f3f3f;
int f[maxn],ff[maxn],n,k,m,ans;
bool vis[maxn];

int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}

int main()
{
	cin>>n>>k;	
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=k;++i)
	{
		int x,y;cin>>x>>y;
		f[find(x)]=find(y);
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y;cin>>x>>y;
		if(find(x)!=find(y)) continue;
		vis[find(x)]=1;
	}
	for(int i=1;i<=n;++i) ff[find(i)]++;
	
	for(int i=1;i<=n;++i)
	{
		if(f[i]!=i||vis[i])continue;
		ans=max(ans,ff[i]);
	}
	cout<<ans;	
	return 0;
}
