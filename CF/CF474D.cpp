#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxk=1e5+5,mod=1e9+7;
int f[maxk],sum[maxk];

signed main()
{
	int t,k;cin>>t>>k;
	f[0]=1,sum[0]=1;
	for(int i=1;i<=maxk;i++)
	{
		f[i]=(f[i-1]+(i<k?0:f[i-k]))%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}	
	while(t--)
	{
		int a,b;cin>>a>>b;
		cout<<((sum[b]-sum[a-1]+mod)%mod)<<endl;
	}
	return 0;
}