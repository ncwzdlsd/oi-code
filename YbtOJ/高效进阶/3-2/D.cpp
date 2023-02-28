#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int N,c[maxn]/*统计集合点数*/,fa[maxn],ans;

struct node{int u,v,w;}gg[maxn];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

// 对于x、y，假设两点相连边权为w（x、y是两集合的父亲）
// 还原完全图，要在两集合中任意点加边，边数为card(A)*card(B)-1
// 为了保证最小生成树唯一，加边边权最小为w+1

signed main()
{
	cin>>N;
	for(int i=1;i<=N;i++) fa[i]=i,c[i]=1;
	for(int i=1;i<N;i++) cin>>gg[i].u>>gg[i].v>>gg[i].w,ans+=gg[i].w;
	sort(gg+1,gg+N,cmp);
	for(int i=1;i<N;i++)
	{
		int fu=find(gg[i].u),fv=find(gg[i].v);
		ans+=(gg[i].w+1)*(c[fu]*c[fv]-1);
		fa[fu]=fv;c[fv]+=c[fu];
	}
	cout<<ans;
	return 0;
}