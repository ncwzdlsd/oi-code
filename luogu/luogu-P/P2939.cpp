#include <bits/stdc++.h>
using namespace std;

const int maxn=100005,maxm=500005;
int nxt[maxm*25],w[maxm*25],to[maxm*25],head[maxm*25],cnt,diss[maxn*25];

void add(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
	w[cnt]=z;
}

struct node
{
	int u,dis;
	friend bool operator < (node a,node b)
	{
		return a.dis<b.dis;//小顶堆！
	}
}

priority_queue<node> q;

//Dijkstra模板，今天终于彻底搞明白了
void dij(innt s)//s表示源点
{
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	q.push(node{s,0});
	while(!q.empty())
	{
		node gg=q.top;q.pop();
		int u=gg.u,dis=gg.dis;
		if(dis!=diss[u]) continue;
		for(int i=head[u];i;i=nxt[i])
		{
			if(diss[to[i]]>dis[u]+w[i])
			{
				dis[to[i]]=dis[u]+w[i];
				q.push(node{to[v],diss[to[v]]});
			}
		}
	}
}

int main()
{
	int N,M,K;cin>>N>>M>>K;
	for(int i=1;i<=M;i++)
	{
		int a,b,c;cin>>a>>b>>c;add(a,b,c),add(b,a,c);
		for(int j=1;j<=K;j++)
		{
			add(a+n*j,b+n*j,c);add(b+n*j,a+n*j,c);//复制图
			add(a+n*(j-1),b+n*j,c);add(b+n*(j-1),a+n*j,c);
		}
	}
	for(int i=1;i<=K;i++) ans=min(ans,dis[n+i*n]);
	cout<<ans;
	return 0;
}