#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int nxt[maxn],h[maxn],s[maxn],flag,n;
bool vis[maxn];

int dfs(int now,int nowc)//起始位置 当前糖果数
{
	if(h[now]) return nowc-1+h[now];//当前房间的糖果不能重复累加，要-1
	if(vis[now]==1)
	{
		h[now]=nowc-s[now];flag=now;
		return nowc-1;
	}
	vis[now]=1;s[now]=nowc;
	int ans=dfs(nxt[now],nowc+1);//当前位置符合，继续向下一个位置DFS
	if(flag)
	{
		if(now==flag) flag=0;
		else h[now]=h[flag];
	}
	else h[now]=h[nxt[now]]+1;
	vis[now]=false;
	return ans;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>nxt[i];
	for(int i=1;i<=n;i++) cout<<dfs(i,1)<<endl;
	return 0;
}