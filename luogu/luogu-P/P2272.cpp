#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int N,M,X,a,b,fa[maxn]/*记录是由哪条边转移来的，判断重边*/,head1[maxn],nxt1[maxn],to1[maxn],cnt1,dfn[maxn],low[maxn],head2[maxn],nxt2[maxn],to2[maxn],cnt2,dfncnt,scccnt,top,s[maxn],scc[maxn],sccsz[maxn],f[maxn],g[maxn];

void add1(int x,int y)
{
	to1[++cnt1]=y;
	nxt1[cnt1]=head1[x];
	head1[x]=cnt1;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++dfncnt;
	s[++top]=x;
	for(int i=head1[x];i;i=nxt1[i])
	{
		int y=to1[i];
		if(!dfn[y]) tarjan(y),low[x]=min(low[x],low[y]);
		else if(!scc[y]) low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		++scccnt;
		while(s[top]!=x) scc[s[top]]=scccnt,top--,++sccsz[scccnt];
		scc[s[top]]=scccnt;
		++sccsz[scccnt];
		top--;
	}
}

void add2(int x,int y)
{
	to2[++cnt2]=y;
	nxt2[cnt2]=head2[x];
	head2[x]=cnt2;
}

int main()
{
	cin>>N>>M>>X;
	for(int i=1;i<=M;i++) cin>>a>>b,add1(a,b);
	for(int i=1;i<=N;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=N;i++)
		for(int j=head1[i];j;j=nxt1[j])
			if(scc[to1[j]]!=scc[i]) add2(scc[i],scc[to1[j]]);
	// 缩成DAG，求图中最长链的长度f和数量g
	for(int i=1;i<=scccnt;++i) f[i]=sccsz[i],g[i]=1;
	for(int x=scccnt;x;x--)//逆拓扑序，倒序枚举
		for(int i=head2[x];i;i=nxt2[i])
		{
			int y=to2[i];
			if(fa[y]==x) continue;
			fa[y]=x;
			if(f[y]<f[x]+sccsz[y]) f[y]=f[x]+sccsz[y],g[y]=g[x];
			else if(f[y]==f[x]+sccsz[y]) g[y]+=g[x],g[y]%=X;
		}
	int ans1=0,ans2=0;
	for(int i=1;i<=scccnt;i++)
	{
		if(f[i]>ans1) ans1=f[i],ans2=g[i];
		else if(f[i]==ans1) ans2+=g[i],ans2%=X;
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}