#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3005,maxm=10005,inf=1e9;
double f[maxn][maxn],w[maxm];
int u[maxm],v[maxm];

signed main() 
{
	int n,m;cin>>n>>m;
	for(int i=0;i<m;++i) cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<=n;++i)
	for(int j=1;j<=n;++j)
	  f[i][j]=i?inf:0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j) 
			f[i+1][v[j]]=min(f[i+1][v[j]],f[i][u[j]]+w[j]);
	double ans=1e7,ans1;
	for(int i=1;i<=n;++i) 
		if(f[n][i]<1e11) 
		{
			ans1=-inf;
			for(int j=0;j<n;++j)
				ans1=max(ans1,(f[n][i]-f[j][i])/(n-j));
			ans=min(ans, ans1);
		}
	printf("%.8lf", ans);
	return 0;
}