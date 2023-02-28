#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e6+5;
int head[maxn],to[maxn],nxt[maxn],cnt;
int dfn[maxn],sta[maxn]/*栈*/,low[maxn],dfncnt,vis[maxn],top/*记录栈中元素编号*/,sccnum/*记录强连通分量编号*/,scc[maxn]/*编号为i的点所在的强连通分量编号*/;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;	
}

void tarjan(int u)
{
	low[u]=dfn[u]=++dfncnt;
	sta[++top]=u;vis[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v]) tarjan(v)/*继续往下搜*/,low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);	
	}
	if(dfn[u]==low[u])
	{
		++sccnum;
		while(sta[top]!=u)//把它搜索树里的都弹完
			scc[sta[top]]=sccnum,vis[sta[top]]=0,top--;//数组模拟弹栈
		//处理它自己
		scc[sta[top]]=sccnum;
		vis[sta[top]]=0;
		top--;
	}
}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int ii,a,jj,b;cin>>ii>>a>>jj>>b;
		//实现建两个点，对于一个点k，k+n是true点，k是false点	
		add(ii+!a*n,jj+b*n);
		add(jj+!b*n,ii+a*n);
	}
	for(int i=1;i<=2*n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
		if(scc[i]==scc[i+n]) puts("IMPOSSIBLE"),exit(0);
	puts("POSSIBLE");
	for(int i=1;i<=n;i++)
	{
		if(scc[i]<scc[i+n]) cout<<0<<' ';
		else cout<<1<<' ';
	}
	return 0;
}