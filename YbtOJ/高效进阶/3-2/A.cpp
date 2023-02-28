#include <bits/stdc++.h>
using namespace std;

// 最小生成树模板

const int maxm=1e5+5;
int n,m,fa[maxm],maxx,cnt;
struct node{int from,to,v;}gg[maxm];

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

bool cmp(node a,node b)
{
	return a.v<b.v;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>gg[i].from>>gg[i].to>>gg[i].v;
	sort(gg+1,gg+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m&&cnt<n-1;i++)
	{
		int uu=find(gg[i].from),vv=find(gg[i].to);
		if(uu!=vv)
		{
			maxx=gg[i].v;
			fa[uu]=vv;
			cnt++;
		}
	}
	cout<<n-1<<' '<<maxx;
	return 0;
}