#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e6+5;
int f[maxn][25],dep[maxn],head[maxn],nxt[maxn],to[maxn],cnt,N;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}

void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(to[i],x);
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int M,S,x,y;cin>>N>>M>>S;
	for(int i=1;i<N;i++) cin>>x>>y,add(x,y),add(y,x);
	dfs(S,0);int a,b;
    for(int j=1;j<=20;j++) for(int i=1;i<=N;i++) f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=M;i++) cin>>a>>b,cout<<lca(a,b)<<endl;
	return 0;
}