#include <bits/stdc++.h>
using namespace std;

const int maxm=2e4+5;
struct edge{int u,v,w;}e[maxm];
int fa[maxm];

bool cmp(edge a,edge b){return a.w<b.w;}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	int n,m,s,t;cin>>n>>m>>s>>t;
	for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,e[i]=(edge){u,v,w},fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		if(find(s)==find(t)) cout<<e[i].w,exit(0);
	}
	return 0;
}