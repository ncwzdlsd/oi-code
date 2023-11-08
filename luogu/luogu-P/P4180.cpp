#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5,maxm=6e5+5;
int head[maxn],g1[maxn][25],g2[maxn][25],f[maxn][25],dep[maxn],cnt,N,M,fa[maxn],sum;
struct edge1{int u,v,w;}e1[maxm];
struct edge2{int to,nxt,w;}e2[maxm];
bool vis[maxm];

bool cmp(edge1 a,edge1 b){return a.w<b.w;}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void add(int x,int y,int z){e2[++cnt]={y,head[x],z},head[x]=cnt;}

void kruskal()
{
	sort(e1+1,e1+M+1,cmp);
	int tot=0;
	for(int i=1;i<=M;i++)
	{
		int fu=find(e1[i].u),fv=find(e1[i].v);
		if(fu!=fv) tot++,fa[fu]=fv,sum+=e1[i].w,add(e1[i].u,e1[i].v,e1[i].w),add(e1[i].v,e1[i].u,e1[i].w),vis[i]=1;
		if(tot==N-1) break;
	}
}

void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=1;i<=20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		g1[x][i]=max(g1[f[x][i-1]][i-1],g1[x][i-1]);
		if(g1[f[x][i-1]][i-1]==g1[x][i-1]) g2[x][i]=max(g2[x][i-1],g2[f[x][i-1]][i-1]);
		else if(g1[f[x][i-1]][i-1]>g1[x][i-1]) g2[x][i]=max(g1[x][i-1],g2[f[x][i-1]][i-1]);
		else g2[x][i]=max(g2[x][i-1],g1[f[x][i-1]][i-1]);
	}
	for(int i=head[x];i;i=e2[i].nxt)
	{
		if(e2[i].to==fa) continue;
		g1[e2[i].to][0]=e2[i].w;
		dfs(e2[i].to,x);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int getmx(int x,int rt,int w)
{
	int ans=0;
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[rt])
		{
			if(g1[x][i]==w) ans=max(ans,g2[x][i]);
			else ans=max(ans,g1[x][i]);
			x=f[x][i];
		}
	return ans;
}

signed main()
{
	cin>>N>>M;
	for(int i=1;i<=M;i++) cin>>e1[i].u>>e1[i].v>>e1[i].w;
	for(int i=1;i<=N;i++) fa[i]=i;
	kruskal();
	dfs(1,0);
	int ans=LLONG_MAX;
	for(int i=1;i<=M;i++)
	{
		if(e1[i].u==e1[i].v||vis[i]) continue;
		int mx=getmx(e1[i].u,lca(e1[i].u,e1[i].v),e1[i].w),my=getmx(e1[i].v,lca(e1[i].u,e1[i].v),e1[i].w);
		if(max(mx,my)!=e1[i].w) ans=min(ans,sum+e1[i].w-max(mx,my));
	}
	cout<<ans<<endl;
	// for(int i=1;i<=N;i++) cout<<g1[i][0]<<' '<<g2[i][0]<<endl;
	return 0;
}