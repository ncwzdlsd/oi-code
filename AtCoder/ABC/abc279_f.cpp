#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3e5+5;
int fa[maxn],ans[maxn],id[maxn]/*记录节点编号*/,p[maxn]/*记录根节点*/;

int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

signed main()
{
	int N,Q;cin>>N>>Q;
	for(int i=1;i<=N;i++) fa[i]=p[i]=ans[i]=id[i]=i;
	int tot=N,t=N;
	while(Q--)
	{
		int opt;cin>>opt;
		if(opt==1)
		{
			int x,y;cin>>x>>y;
			fa[id[y]]=fa[id[x]];
			id[y]=++tot,fa[tot]=tot,ans[tot]=y;
		}
		else if(opt==2)
		{
			int X;cin>>X;
			p[++t]=id[X];
		}
		else
		{
			int X;cin>>X;
			cout<<ans[find(p[X])]<<endl;
		}
	}
	return 0;
}