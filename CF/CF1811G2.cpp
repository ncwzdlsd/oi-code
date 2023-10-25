#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
int inv[maxn],fac[maxn];

int quickpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1,res=res*a%mod;
	}
}

signed main()
{
	return 0;
}