#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	int ans,h,now;
	cin>>ans;
	now=ans;
	for(int i=2;i<=n;i++)
	{
		cin>>h;
		if(h>now) ans+=(h-now);
		now=h;
	}
	cout<<ans;
	return 0;
}