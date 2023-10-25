#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

ll quickpow(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

signed main()
{
	ll n,m;cin>>n>>m;
	ll ans=1;
	for(ll i=n+1;i<=n+m;i++) ans=ans*i%mod;
	for(ll i=1;i<=m;i++) ans=ans*quickpow(i,mod-2)%mod;
	cout<<ans;
	return 0;
}