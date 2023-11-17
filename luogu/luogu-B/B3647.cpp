#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
int f[maxn][maxn];

int main()
{
	int n,m;cin>>n>>m;
	memset(f,0x3f3f3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,f[u][v]=f[v][u]=w;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cout<<f[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}