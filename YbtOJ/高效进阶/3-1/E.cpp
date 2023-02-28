#include <bits/stdc++.h>
using namespace std;
#define int long long

// 已知一些点，求使其不连通的最小代价（怎么有点儿像Tarjan）
// 特殊并查集，需要支持删边操作，考虑正难则反
// 花费最小代价删边等于花费最大代价建边，按照边权从大到小建图
// 特殊考虑：如果我方节点与敌人节点相连，为了不让其他敌人节点通过我方节点与敌人相连，标记与敌人相连的我方节点为敌人节点

const int maxn=1e6+5;
int fa[maxn],N,M,K,d[maxn],qwq,sum;

int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

struct node
{
	int u,v,w;
}e[maxn];

bool cmp(node a,node b)
{
	return a.w>b.w;
}

signed main()
{
	cin>>N>>M>>K;
	for(int i=0;i<N;i++) fa[i]=i;
	for(int i=1;i<=K;i++) cin>>qwq,d[qwq]=1;
	for(int i=1;i<=M;i++) cin>>e[i].u>>e[i].v>>e[i].w,sum+=e[i].w;
	sort(e+1,e+M+1,cmp);
	for(int i=1;i<=M;i++)
	{
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv) {sum-=e[i].w;continue;}
		else if(!d[fu]||!d[fv])
		{
			sum-=e[i].w;
			if(!d[fu]) fa[fu]=fv;
			else fa[fv]=fu;
		}
	}
	cout<<sum;
	return 0;
}