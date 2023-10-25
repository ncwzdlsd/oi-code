#include <bits/stdc++.h>
using namespace std;

const int maxn=40005;
int nxt[maxn],to[maxn],head[maxn],val[maxn],dis[maxn],vis[maxn],rec[maxn],cnt,n,m;
queue<int> q;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	val[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

bool spfa()
{
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(rec,0,sizeof(rec));
	while(!q.empty()) q.pop(),cout<<"qwq"<<endl;//清空上一次的队列
	q.push(1);
	dis[1]=0,vis[1]=1,rec[1]++;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;//队首已出队
		for(int i=head[u];i;i=nxt[i])
		{
			if(dis[to[i]]>dis[u]+val[i])
			{
				dis[to[i]]=dis[u]+val[i];
				//对于判断是否有负环，用数组rec记录点的入队次数，如果入队次数>n，就证明出现了负环导致没有最短路
				if(!vis[to[i]]) vis[to[i]]=true,rec[to[i]]++,q.push(to[i]);//能更新，压入队列
				if(rec[to[i]]>=n) return true;
			}
		}	
	}
	return false;
}

int main()
{
	int T,u,v,w;cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(head,0,sizeof(head));
		cnt=0;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			add(u,v,w);
			if(w>=0) add(v,u,w);
		}
		spfa();
		if(spfa()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}