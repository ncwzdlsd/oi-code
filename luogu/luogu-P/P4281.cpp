#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e6+5;
int f[maxn][25],dep[maxn],head[maxn],nxt[maxn],to[maxn],cnt;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

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
	std::ios::sync_with_stdio(false);
	int n,m,a,b;n=read(),m=read();
	for(int i=1;i<n;i++) a=read(),b=read(),add(a,b),add(b,a);
	dfs(1,0);
    for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=m;i++)
	{
		int x,y,z,ans=0;
		x=read(),y=read(),z=read();
		int aa=lca(x,y),bb=lca(x,z),cc=lca(y,z),qwq;
		if(aa==bb) qwq=cc;
		if(bb==cc) qwq=aa;
		if(aa==cc) qwq=bb;
		ans=dep[x]+dep[y]+dep[z]-dep[aa]-dep[bb]-dep[cc];
		cout<<qwq<<' '<<ans<<endl;
	}
	return 0;
}