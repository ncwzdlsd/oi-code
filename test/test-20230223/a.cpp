#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n,ans=0;cin>>n;
	int tmp,cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>tmp;
		if(tmp>1) ++cnt1;
		if(tmp<1) ++cnt2;
		if(tmp==1) ++cnt3;
	}
	for(int i=0;i<cnt3;i++) ans+=cnt1+i;
	for(int i=1;i<=cnt2;i++) ans+=cnt1+cnt3;
	cout<<ans;
	return 0;
}