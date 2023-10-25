#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=998244353,maxn=5e6+5;
int inv[maxn],p[maxn]/*2的次幂*/,p1[maxn],p2[maxn]/*组合数分数线下方的部分*/,g[maxn];

int quickpow(int a,int b)
{
	int s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return s;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	p[0]=1,p1[0]=1,g[0]=1,g[1]=0;
	for(int i=1;i<=maxn;i++) p[i]=p[i-1]*2%mod;
	for(int i=1;i<=maxn;i++) p1[i]=p1[i-1]*i%mod;
	inv[maxn]=quickpow(p1[maxn],mod-2);
	for(int i=maxn;i;i--) inv[i-1]=inv[i]*i%mod;
	for(int i=2;i<=maxn;i++) g[i]=(g[i-1]+g[i-2]*2*(i-1))%mod*4*i%mod*(i-1)%mod;
	int T;cin>>T;
	while(T--)
	{
		int n,k;cin>>n>>k;
		int ans=p1[n]*inv[n-k]%mod*p1[n]%mod*inv[k]%mod*inv[n-k]%mod*p[k]%mod*g[n-k]%mod;
		cout<<ans<<endl;
	}
	return 0;
}