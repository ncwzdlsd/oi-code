#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int cnt,head[maxn],deg[maxn],fa[maxn],siz;
struct edge{int to,nxt;}e[maxn*2];
bool vis[maxn];

void add(int x,int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void dfs(int x)
{
	for(int i=head[x];i;i=e[i].nxt)
		if(!vis[e[i].to]) vis[e[i].to]=1,siz++,dfs(e[i].to);
}

void solve()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) head[i]=0,deg[i]=0,vis[i]=0,fa[i]=i,vis[i]=0;
	cnt=0;
	for(int i=1;i<=n*2;i++) e[i]=(edge){0,0};
	for(int i=1,u,v;i<=m;i++) cin>>u>>v,add(u,v),add(v,u),deg[u]++,deg[v]++,fa[find(u)]=find(v);
	int cnt2=0,cnt4=0,k=sqrt(n);
	if(k*k!=n) return cout<<"nO\n",void();
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==2) cnt2++;
		else if(deg[i]==4) cnt4++;
		else return cout<<"No\n",void();
	}
	if(cnt4!=k) return cout<<"no\n",void(); 
	for(int i=1;i<=n;i++) if(find(i)!=find(1)) return cout<<"NO\n",void();
	for(int x=1;x<=n;x++)
	{
		cnt2=0,cnt4=0;
		if(deg[x]!=4) continue;
		for(int i=head[x];i;i=e[i].nxt) cnt2+=(deg[e[i].to]==2),cnt4+=(deg[e[i].to]==4);
		if(cnt2!=2||cnt4!=2) return cout<<"NO\n",void();
		vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt) if(deg[e[i].to]==2){siz=0,dfs(e[i].to);break;}
		if(siz!=k-1) return cout<<"No\n",void();
	}
	cout<<"YES\n";
}

int main()
{
	int t;cin>>t;
	while(t--) solve();
	return 0;
}