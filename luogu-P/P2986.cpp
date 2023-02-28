#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int ans,head[maxn],f[maxn],sum,nxt[maxn],to[maxn],cnt,val[maxn],C[maxn],dis[maxn],qwq[maxn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	val[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

int dfs1(int x,int fa)//计算牛的子树
{
	int tot=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		int gg=dfs1(to[i],x);
		dis[x]+=dis[to[i]]+val[i]*gg;
		tot+=gg;
	}
	return qwq[x]=tot+C[x];
}

void dfs2(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		int ss=val[i];
		f[to[i]]=f[x]-qwq[to[i]]*ss+(sum-qwq[to[i]])*ss;
		dfs2(to[i],x);
	}	
}

int main()
{
	int N,ans=0x3f3f3f;cin>>N;
	for(int i=1;i<=N;i++) cin>>C[i],sum+=C[i];
	for(int i=1;i<=N;i++)
	{
		int a,b,l;cin>>a>>b>>l;
		add(a,b,l);add(b,a,l);
	}
	dfs1(1,1);dfs2(1,1);
	for(int i=1;i<=N;i++) ans=min(ans,f[i]);
	cout<<ans+dis[1];
	return 0;
}