#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const int mod=1e9+7,maxn=1e6+5;
int fac[maxn],inv[maxn],f[maxn],g[maxn];

int quickpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}

int C(int n,int m)
{return fac[n]*inv[m]%mod*inv[n-m]%mod;}

signed main()
{
	int n,k;cin>>n>>k;
	fac[0]=1,f[0]=1,g[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    inv[n]=quickpow(fac[n],mod-2);
    for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod; 
    for(int i=1;i<=n;i++)
	{
		if(i<=k) f[i]=fac[i-1]*(g[i-1]+mod)%mod;
		else f[i]=fac[i-1]*(g[i-1]-g[i-k-1]+mod)%mod;
		g[i]=(g[i-1]+f[i]*inv[i])%mod;
	}
	cout<<(fac[n]-fac[n-1]*g[n-1]%mod+mod)%mod;
	return 0;
}