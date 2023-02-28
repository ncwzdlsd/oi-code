#include <bits/stdc++.h>
using namespace std;

const int maxn=20005,maxm=200005;
int nxt[maxm*25],w[maxm*25],to[maxm*25],head[maxm*25],cnt,diss[maxn*25];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[++cnt]=head[x];
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

//Dijkstra模板，今天终于彻底搞明白了
void dij(int s)//s表示源点
{
	memset(diss,0x3f,sizeof(diss));
	diss[s]=0;
	q.push(node{s,0});
	while(!q.empty())
	{
		node gg=q.top();q.pop();
		int u=gg.u,dis=gg.dis;
		if(dis!=diss[u]) continue;
		for(int i=head[u];i;i=nxt[i])
			if(diss[to[i]]>diss[u]+w[i])
			{
				diss[to[i]]=diss[u]+w[i];
				q.push(node{to[i],diss[to[i]]});
			}
	}
}

signed main()
{
	int N,M,K;cin>>N>>M>>K;
	int ss,tt;cin>>ss>>tt;
	for(int i=1;i<=M;i++)
	{
		int a,b,c;cin>>a>>b>>c;add(a,b,c);add(b,a,c);
		for(int j=1;j<=K;j++)
		{
			add(a+N*(j-1),a+N*j,0);
            add(a+N*(j-1),b+N*j,0);
            add(b+N*(j-1),a+N*j,0);
            //建原图+复制图，即每层图都创造一个和第一层图一样的连线
            add(a+N*j,b+N*j,c),
            add(b+N*j,a+N*j,c);
            //建立层与层之间的边，即有高度公路
		}
	}
	for(int i=1;i<=K;++i)
		add(tt+(i-1)*N,tt+i*N,0);
	dij(ss);
	cout<<diss[tt+K*N];
	return 0;
}