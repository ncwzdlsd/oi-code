#include <bits/stdc++.h>
using namespace std;

int f[105][105],g[105][105];

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) f[i][j]=1e9;
	for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,f[u][v]=f[v][u]=w;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int ans=INT_MAX;
	for(int x=1;x<=n;x++)
		for(int y=x+1;y<=n;y++)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) g[i][j]=f[i][j];
			g[x][y]=g[y][x]=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][x]+g[x][j]);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][y]+g[y][j]);
			int sum=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++) sum+=g[i][j];
			ans=min(ans,sum);
		}
	cout<<ans<<'\n';
	return 0;
}