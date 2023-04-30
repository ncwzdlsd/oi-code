#include <bits/stdc++.h>
using namespace std;
//将k个白点隔开 

const int maxn=2e5+5;
int d[maxn],fa[maxn];

int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

struct node{int u,v,w;}gg[maxn];

bool cmp(node a,node b){return a.w<b.w;}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<n;i++) cin>>gg[i].u>>gg[i].v>>gg[i].w,sum+=gg[i].w; 
	int qwq=0,qaq=0;
	int m;cin>>m;
	for(int i=1;i<=m;i++) cin>>qwq;
	int k;cin>>k;
	for(int i=1;i<=k;i++) cin>>qaq,d[qaq]=1;
	sort(gg+1,gg+n,cmp);
	for(int i=1;i<=k;i++)
	{
		int u=gg[i].u,v=gg[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv) {sum-=gg[i].w;continue;}
		else if(!d[fu]||!d[fv])
		{
			sum-=gg[i].w;
			if(!d[fu]) fa[fu]=fv;
			else fa[fv]=fu;
		}
	}
	cout<<sum;
	return 0;
}
