#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=998244353;

int quickpow(int a,int b)
{
	int res=1;
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
	int ans=1;
	int n,m;cin>>n>>m;
	if(n==2) cout<<0,exit(0);
	for(int i=m-n+2;i<=m;i++) ans=ans*i%mod;
	for(int i=1;i<=n-1;i++) ans=ans*quickpow(i,mod-2)%mod;
	ans=ans*(n-2)%mod;
	ans=ans*quickpow(2,n-3)%mod;
	cout<<ans;
	return 0;
}