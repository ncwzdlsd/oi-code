#include <bits/stdc++.h>
using namespace std;

const int maxn=16005*2,inf=0x7fffffff;
int l,k,id,head[maxn],to[maxn],nxt[maxn],ru[maxn/2],r[maxn],f[maxn][3],v[maxn],ans=-1000000,cnt;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int fa,int x)
{
	f[x][1]=r[x];
	int tmp=inf;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(x,to[i]);
		tmp=min(tmp,f[to[i]][1]-f[to[i]][0]);
		f[x][0]+=min(f[to[i]][1],f[to[i]][0]);//儿子看守
		f[x][1]+=min(f[to[i]][0],min(f[to[i]][1],f[to[i]][2]));//自己看守
		f[x][2]+=min(f[to[i]][0],f[to[i]][1]);//父亲看守
	}
	f[x][0]+=max(tmp,0);
}

signed main()
{
	int n,m,rr;cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>id>>r[id]>>m;
		for(int i=1;i<=m;i++) cin>>rr,ru[id]++,add(rr,id),add(id,rr);
	}
	dfs(0,1);
	cout<<min(f[1][0],f[1][1]);
	return 0;
}