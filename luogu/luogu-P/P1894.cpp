#include <bits/stdc++.h>
using namespace std;

const int maxn=5e4+5;
int head[maxn],nxt[maxn],to[maxn],vis[maxn],cnt,match[505],m,n;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

bool dfs(int now)//找对象
{
	for(int i=head[now];i;i=nxt[i])
	{
		if(vis[to[i]]) continue;
		vis[to[i]]=1;
		if(!match[to[i]]||dfs(match[to[i]]))
		{
			match[to[i]]=now;
			return 1;
		}
	}
	return 0;
}

int main()
{
	cin>>n>>m;
	for(int i=1,s,id;i<=n;i++) 
	{
		cin>>s;
		while(s--) cin>>id,add(i,id);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	cout<<ans;
	return 0;
}