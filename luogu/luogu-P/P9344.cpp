#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e6+5;
int a[maxn],f[maxn];
bool c[maxn];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	int min0=LLONG_MAX,min1=LLONG_MAX;
	for(int i=1;i<=n;i++)
	{
		if(!c[i]) min0=min(min0,f[i-1]+a[i]);
		else min1=min(min1,f[i-1]+a[i]);
		if(!c[i]) f[i]=min0+a[i];
		else f[i]=min1+a[i];
	}
	cout<<f[n]<<'\n';
}

signed main()
{
	int T;cin>>T;
	while(T--) solve();	
	return 0;
}