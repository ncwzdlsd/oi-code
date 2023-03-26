#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int t;cin>>t;
	while(t--)
	{
		int x,y;cin>>x>>y;
		int minn=min(abs(x),abs(y)),maxx=max(abs(x),abs(y));
		int ans=minn*2+(maxx-minn)*2-1;
		if(abs(x)==abs(y)) cout<<abs(x)*2<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}