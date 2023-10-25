#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int fa[maxn];
bool vis[maxn];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		int xx=find(x),yy=find(y);
		if(xx==yy) vis[xx]=1;
		else
		{
			fa[xx]=yy;
			if(vis[xx]||vis[yy]) vis[xx]=vis[yy]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(find(i)==i&&!vis[i]) ans++;
	cout<<ans;
	return 0;
}