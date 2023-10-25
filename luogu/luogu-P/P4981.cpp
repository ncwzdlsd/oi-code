#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+9;

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
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		cout<<quickpow(n,n-1)<<endl;
	}
	return 0;
}