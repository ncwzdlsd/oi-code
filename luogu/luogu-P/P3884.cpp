#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
int dep[maxn],f[maxn][25],head[maxn],cnt,tot[maxn];
struct edge{int to,nxt;}e[maxn];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa) dfs(e[i].to,x);
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main()
{
	int n;cin>>n;
	for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
	int x,y;cin>>x>>y;
	dfs(1,0);
	dep[1]=1;
	for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	int mxdep=-0x3f,mxwid=-0x3f;
	for(int i=1;i<=n;i++) mxdep=max(mxdep,dep[i]),tot[dep[i]]++;
	for(int i=1;i<=mxdep;i++) mxwid=max(mxwid,tot[i]);
	cout<<mxdep<<endl<<mxwid<<endl<<((dep[x]-dep[lca(x,y)])*2+dep[y]-dep[lca(x,y)]);
	return 0;
}