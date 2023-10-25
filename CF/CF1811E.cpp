#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[10]={0,1,2,3,5,6,7,8,9};

void solve()
{
	int k;cin>>k;
	int cnt=1,ans=0;
	while(k)
		ans+=a[k%9]*cnt,cnt*=10,k/=9;
	cout<<ans<<'\n';
}

signed main()
{
	int t;cin>>t;
	while(t--) solve();
	return 0;
}