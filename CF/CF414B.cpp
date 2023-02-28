#include<bits/stdc++.h>
using namespace std;
int f[2005][2005],ans;
const int mod=1e9+7;
int main()
{
	int n,k;cin>>n>>k;
	for(int i=0;i<=n;i++) f[1][i]=1;
	for(int i=2;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int gg=1;j*gg<=n;gg++)
				f[i][j]=(f[i][j]+f[i-1][j*gg])%mod;
	for(int i=1;i<=n;i++) ans=(ans+f[k][i])%mod;
	cout<<ans;
	return 0;
}