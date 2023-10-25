#include <bits/stdc++.h>
using namespace std;

const int INF=2147483647;
const int maxn=200005;
int to[maxn<<1],v[maxn<<1],head[maxn],nxt[maxn<<1],dis[maxn]/*最短路*/,N,M,K,S,P,Q,cnt,a,b,c;
bool zombie[maxn];//inqueue记录是否在优先队列中，zombie记录是否被僵尸占领
queue<int> q2;//find用队列，存储危险城市和僵尸占领的城市

struct node
{
	int id,dis;
	friend bool operator < (node a,node b)
	{
		return a.dis>b.dis;
	}
};
priority_queue<node> q1;//优先队列优化Dijkstra

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void find(int sss)
{
	while(q2.size())
	{
		int xx=q2.front();q2.pop();
		if(dis[xx]==sss) continue;//已经到达僵尸占领的城市可以影响到的最远城市
		for(int i=head[xx];i;i=nxt[i])
		{
			int yy=to[i];
			if(!dis[yy]) {dis[yy]=dis[xx]+1;q2.push(yy);}
		}
	}
	for(int i=1;i<=cnt;i++)//对每个城市计算边权
	{
		int yy=to[i];
		if(yy==N) continue;//终点边权为0
		if(zombie[i]!=0) continue;//僵尸城
		if(dis[yy]==0) v[i]=P;//安全城市
		else v[i]=Q;//危险城市
	}
}

void dij(int ss)
{
	for(int i=1;i<=N;i++) dis[i]=INF;
	q1.push({ss,0});dis[ss]=0;//起点入队，起点到自己的距离为0
	while(!q1.empty())
	{
		node qwq=q1.top();q1.pop();
		int xx=qwq.id,diss=qwq.dis;
		if(diss!=dis[xx]) continue;
		for(int i=head[xx];i;i=nxt[i])
		{
			int yy=to[i],gg=v[i];
			if(dis[yy]>dis[xx]+gg&&zombie[yy]!=1) 
			{dis[yy]=dis[xx]+gg;q1.push({yy,dis[yy]});}
		}
	}
}

int main()
{
	cin>>N>>M>>K>>S;cin>>P>>Q;
	for(int i=1;i<=K;i++) {cin>>a,zombie[a]=1,q2.push(a);}
	for(int i=1;i<=M;i++) {cin>>b>>c,add(b,c),add(c,b);}
	find(S),dij(1);
	cout<<dis[N];
	return 0;
}