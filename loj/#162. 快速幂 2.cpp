#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=998244352,maxn=5e6+5;
int a[maxn];

int quickpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1,a=a*a%mod;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int x,n;cin>>x>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cout<<quickpow(x,a[i])<<' ';
	return 0;
}