#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5*1e5+5,maxnn=1e4+5;
int head[maxn],nxt[maxn],to[maxn],cnt,val[maxn],f[maxnn][maxnn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	val[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

signed main()
{
	int n,m,s,u,v,w;cin>>n>>m>>s;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=2147483647;
	for(int i=1;i<=m;i++) cin>>u>>v>>d,add(u,v,d),f[u][v]=f[v][u]=d;
	int ans=2147483647;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=k;i++)
			for(int j=i+1;j<k;j++)
                ans=min(ans,f[i][j]+a[i][k]+a[k][j]);//能否构成环
	
	if(ans==2147483647) cout<<"No solution.";
	else cout<<ans;
	return 0;
}