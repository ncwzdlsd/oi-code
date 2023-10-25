#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int cnt,n,m,tot,vis[maxn],from[maxn],low[maxn],topoxu[maxn],a[maxn],nxt[maxn],head[maxn],to[maxn],dfscnt,dfn[maxn],top,s[maxn],suodian[maxn],ru[maxn],dis[maxn];

void add(int x,int y)
{
	to[++cnt]=y;
	from[cnt]=x;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void tarjan(int x)
{
	low[x]=dfn[x]=++dfscnt;
	s[++top]=x;vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
			low[x]=min(low[x],low[v]);
	}
	if(dfn[x]==low[x])
	{
		int y;y=s[top];
		while(y)
		{
			top--;
			suodian[y]=x;
			vis[y]=0;
			if(x==y) break;
			a[x]+=a[y];
		}
	}
}

int topo()
{
	queue<int> q;
	tot=0;
	for(int i=1;i<=n;i++)
		if(suodian[i]==i&&!ru[i])
		{
			q.push(i);
			dis[i]=a[i];
		}
	while(!q.empty())
	{
		int rr=q.front();q.pop();
		for(int i=topoxu[rr];i;i=nxt[i])
		{
			int v=to[i];
			dis[v]=max(dis[v],dis[rr]+a[v]);
			ru[v]--;
			if(ru[v]==0) q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dis[i]);
	return ans;
}

int main()
{
	int u,v;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>u>>v,add(u,v);
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int x=suodian[from[i]],y=suodian[to[i]];
		if(x!=y)
		{
			nxt[++sum]=topoxu[x];
			to[sum]=y;
			from[sum]=x;
			topoxu[x]=sum;ru[y]++;
		}
	}
	cout<<topo();
	return 0;
}