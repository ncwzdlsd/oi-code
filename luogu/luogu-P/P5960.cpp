#include <bits/stdc++.h>
using namespace std;

const int maxn=1e4+5;
int head[maxn],to[maxn],nxt[maxn],w[maxn],dis[maxn],cnt,n,m,tot[maxn];
bool vis[maxn];

void add(int x,int y,int z)
{to[++cnt]=y,w[cnt]=z,nxt[cnt]=head[x],head[x]=cnt;}

queue<int> q;

bool spfa(int s)
{
	dis[s]=0,vis[s]=1,q.push(s);tot[s]++;
	while(!q.empty())
	{
		int x=q.front();q.pop();vis[x]=0;
		for(int i=head[x];i;i=nxt[i])
			if(dis[to[i]]>dis[x]+w[i])
			{
				dis[to[i]]=dis[x]+w[i];
				if(!vis[to[i]])
				{
					vis[to[i]]=1,tot[to[i]]++;q.push(to[i]);
					if(tot[to[i]]==n+1) return 1;
				}
			}
	}
	return 0;
}

int main()
{
	memset(dis,0x3f3f3f,sizeof dis);
	cin>>n>>m;
	for(int i=1;i<=n;i++) add(0,i,0);
	for(int i=1;i<=m;i++)
	{
		int c,cc,y;cin>>c>>cc>>y;
		add(cc,c,y);
	}
	if(spfa(0)) cout<<"NO";
	else for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
	return 0;
}