#include <bits/stdc++.h>
using namespace std;

const int maxn=6e5+5;
int head[maxn],nxt[maxn],to[maxn],w[maxn],cnt,N,K,A,B,C;
bool vis[maxn],oo;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

struct node
{
	int id,dis;
	bool friend operator < (node a,node b){return a.dis>b.dis;}
}
priority_queue<node> q;

void dij()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;q.push(node{1,0});
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
			if(dis[to[i]]>dis[u]+w[i])
				dis[to[i]]=dis[u]+w[i],q.push(node{to[i],dis[to[i]]});
	}
}

int main()
{
	cin>>N>>K>>A>>B>>C;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			cin>>oo;
			if(oo)
			{
				for(int k=1;k<=K;k++)
					add((i-1)*N+j+l*N*N,(i-1)*N+j,A);
				// 注意数组越界
				if(i<N) add((i-1)*N+j,i*N+j+N*N,0);
				if(j<N) add((i-1)*N+j,(i-1)*N+j+1+N*N,0);
				if(i>1) add((i-1)*N+j,(i-2)*N+j+N*N,B);
				if(j>1) add((i-1)*N+j,(i-2)*N+j-1+N*N,B);
			}
			else
			{
				
			}
		}
	return 0;
}