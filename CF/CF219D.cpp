#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
struct edge{int to,nxt,w;}e[maxn*2];
int head[maxn],cnt,f[maxn];

void add(int x,int y,int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}

void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		dfs1(e[i].to,x),f[x]+=f[e[i].to]+e[i].w;
	}
}

void dfs2(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		f[e[i].to]=f[x]+(e[i].w?-1:1),dfs2(e[i].to,x);
	}
}

int main()
{
	int n;cin>>n;
	for(int i=1,s,t;i<n;i++) cin>>s>>t,add(s,t,0),add(t,s,1);
	dfs1(1,0),dfs2(1,0);
	int ans=INT_MAX;
	for(int i=1;i<=n;i++) ans=min(ans,f[i]);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) if(f[i]==ans) cout<<i<<' ';
	return 0;
}