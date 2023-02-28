#include <bits/stdc++.h>
using namespace std;

// 朴素思路，想办法找到买入点和卖出点，考虑分层图
// 对于“任意走动”，建一张边权为0的图
// 每买入一个物品i，我们建立一条边权为-v_i的边，由第一层指向第二层
// 每卖出一个物品，建立一条边权为v_i的边，由第二层指向第三层
// 最终答案为从第一层的1号到第三层的n号的最长路（用SPFA跑最长路）

const int maxn=3*1e5+5;
int head[maxn],dis[maxn],nxt[maxn],w[maxn],to[maxn],cnt,n,m,e[maxn];
bool vis[maxn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

queue<int> q;

void spfa()
{
	memset(dis,-0x3f,sizeof(dis));
	dis[1]=0;vis[1]=1;q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int i=head[u];i;i=nxt[i])
			if(dis[to[i]]<dis[u]+w[i]) 
			{
				dis[to[i]]=dis[u]+w[i];
				if(!vis[to[i]]) vis[to[i]]=1,q.push(to[i]);
			}
	}
}

int main()
{
	cin>>n>>m;int sum;
	for(int i=1;i<=n;i++) cin>>e[i],sum+=e[i];
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,0),add(x+n,y+n,0),add(x+2*n,y+2*n,0),add(x,y+n,-e[x]),add(x+n,y+2*n,e[x]);
        if(z==2) swap(x,y),add(x,y,0),add(x+n,y+n,0),add(x+2*n,y+2*n,0),add(x,y+n,-e[x]),add(x+n,y+2*n,e[x]); 
	}
	//建立超级源点0表示旅途结束
	add(n,0,0);
    add(n*2,0,sum);
    add(n*3,0,0);
	spfa();
	cout<<dis[0]<<endl;
	return 0;
}