#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[105][105],C[105][105];
double I[105];

signed main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e9;
	for(int i=1,a,b,c;i<=m;i++) cin>>a>>b>>c,f[a][b]=f[b][a]=c,C[a][b]=C[b][a]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&i!=k)
				{
					if(f[i][j]==f[i][k]+f[k][j]) C[i][j]+=C[i][k]*C[k][j];
					else if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j],C[i][j]=C[i][k]*C[k][j];
				}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&k!=i&&f[i][j]==f[i][k]+f[k][j]) I[k]+=((double)C[i][k]*C[k][j])/C[i][j];
	for(int i=1;i<=n;i++) printf("%.3lf\n",I[i]);
	return 0;
}