#include <bits/stdc++.h>
using namespace std;

int gg[105][105],maxx.vis[105],out[105];//out存储要输出的解

// 最优性剪枝：如果当前解加上后面的所有解都比当前的最大值小，直接return

bool check(int k)//检验k是否已经被选择或者有仇敌关系
{
	for(int i=1;i<k;i++)
		if(gg[k][i]&&vis[i]) return false;
	return true;
}

void dfs(int x)
{
	if(x>n)//搜索停止
	{
		if(s>maxx) maxx=s;
		for(int i=1;i<=n;i++) out[i]=vis[i];
		return;
	}
	if(s+n-k<=sum) return;//最优性剪枝
	if(check(k))
		vis[k]=1,s++,dfs(k+1),s--,vis[k]=0;
	dfs(k+1);
	return;
}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		gg[u][v]=gg[v][u]=1;
	}
	dfs(1);
	for(int i=1;i<=n;i++) cout<<out[i]<<' ';
	cout<<ans<<endl;
}