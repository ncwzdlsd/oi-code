#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=998244353,maxn=2e6+5;
int fac[maxn],inv[maxn];

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

int C(int n,int m){return fac[n]*inv[n-m]%mod*inv[m]%mod;}

void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i) inv[i]=inv[i+1]*(i+1)%mod;
}

void solve()
{
	int u;cin>>u;
	init(maxn-5);
	int x=1,y=0;
	while(u>x) u-=x,x++;
	y=u;
	int ans=0;
	for(int i=0;i<y;++i) ans=(ans+C(x+y-i-2,i)*(C(x+y-2*i-2,x-i-1)-C(x+y-2*i-2,x-i)+mod)%mod)%mod;
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}