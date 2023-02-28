#include<bits/stdc++.h>
using namespace std;

const int maxn=200,maxm=3000,mod=998244353;
int n,m,ans=1,s[maxn],a[maxn][maxm],f[maxn][maxm];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++) 
			cin>>a[i][j],s[i]=(s[i]+a[i][j])%mod;
		ans=(ans*(s[i]+1))%mod;
	} 
	ans=(ans+mod-1)%mod;
	for(int i=1;i<=m;i++) 
	{
        memset(f,0,sizeof(f)); 
        f[0][0]=1;
        for(int j=1;j<=n;j++)
        	for(int k=0;k<=((j-1)<<1);k++)
            f[j][k]=(f[j][k]+f[j-1][k]*(s[j]-a[j][i]))%mod,f[j][k+1]=(f[j][k+1]+f[j-1][k])%mod,f[j][k+2]=(f[j][k+2]+f[j-1][k]*a[j][i])%mod; 
        for(int j=n+1;j<=(n<<1);j++) ans=(ans+mod-f[n][j])%mod;
    }
	cout<<ans;
	return 0; 
}