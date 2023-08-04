#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
int a[505][505],b[505][505],c[505][505];

signed main()
{
	int m,n,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=k;j++)
			cin>>b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			for(int l=1;l<=m;l++)
				c[i][j]+=a[i][l]*b[l][j],c[i][j]%=mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(c[i][j]<0) c[i][j]+=mod;
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}