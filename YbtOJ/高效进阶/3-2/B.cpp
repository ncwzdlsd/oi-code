#include <bits/stdc++.h>
using namespace std;

// 超级源点，在每一个节点建发电站，相当于从超级源点向该发电站连边边权为p[i]
// 点权转化为超级源点的边权

const int maxn=1e5+5;
int n,cnt=1/*边数*/,fa[maxn];

struct node{int from,to,vv;}gg[maxn];

bool cmp(node a,node b)
{
	return a.vv<b.vv;
}

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

int main()
{
	cin>>n;
	int w,ans=0;
	for(int i=1;i<=n;i++) cin>>w,gg[cnt++]={0,i,w},gg[cnt++]={i,0,w};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin>>w,gg[cnt++]={i,j,w},gg[cnt++]={j,i,w};
	sort(gg+1,gg+cnt+1,cmp);
	for(int i=0;i<=n;i++) fa[i]=i;
	for(int i=1;i<cnt;i++)
	{
		int u=gg[i].from,v=gg[i].to,ww=gg[i].vv;
		int fu=find(u),fv=find(v);
		if(fu!=fv) fa[fu]=fv,ans+=ww;
	}
	cout<<ans;
	return 0;
}