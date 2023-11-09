#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;cin>>n;
	int ans,h,now;cin>>now;ans=now;
	for(int i=2;i<=n;i++)
	{
		cin>>h;
		if(h>now) ans+=(h-now);
		now=h;
	}
	cout<<ans;
	return 0;
}