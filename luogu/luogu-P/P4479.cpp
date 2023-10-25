#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
int head[maxn],nxt[maxn],to[maxn],w[maxn],cnt,diss[maxn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

struct node
{
	int u,dis;
	friend bool operator < (node a,node b)
	{
		return a.dis>b.dis;//小顶堆！
	}
};
priority_queue<node> q;

void dij(int s)//s表示源点
{
	memset(diss,0x7f,sizeof(diss));
	diss[s]=0;
	q.push(node{s,0});
	while(!q.empty())
	{
		node gg=q.top();q.pop();
		int u=gg.u,dis=gg.dis;
		if(dis!=diss[u]) continue;//优化（即证明已经找到属于该点的最优中转点）可删
		for(int i=head[u];i;i=nxt[i])
			if(diss[to[i]]>diss[u]+w[i])
				diss[to[i]]=diss[u]+w[i],q.push(node{to[i],diss[to[i]]});
	}
}

int main()
{
	int n,m,s,u,v,w;cin>>n>>m>>s;
	for(int i=1;i<=m;i++) cin>>u>>v>>w,add(u,v,w);
	dij(s);
	for(int i=1;i<=n;i++) cout<<diss[i]<<' ';
	return 0;
}