#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int mod=998244353;
int n,a[1005],b[1005],c[2005][2005],d[1005],f[1005];
 
signed main()
{
    c[0][0]=b[0]=f[2]=f[1]=a[0]=d[0]=1;d[2]=2; 
    for(int i=1;i<=1000;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    for(int i=3;i<=1000;i++) 
        d[i]=((d[i-2]*(i-1)*2)%mod+2*((2*i-2)*(2*i-3)/2%mod-i+1)%mod*f[i-1]%mod)%mod,f[i]=d[i-2]+d[i-1]%mod;
    for(int i=1;i<=1000;i++) b[i]=b[i-1]*2%mod;
    for(int i=1;i<=1000;i++) a[i]=a[i-1]*i%mod;
	int T;cin>>T;
	while(T--)
    {
		cin>>n;
        for(int i=0;i<=n;i++) cout<<b[n]*a[n]%mod*c[n][i]%mod*d[n-i]%mod<<endl;
    } 
    return 0;
}