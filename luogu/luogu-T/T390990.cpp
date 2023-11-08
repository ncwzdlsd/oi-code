#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;cin>>n;
	int tmp=n/3;
	int res=tmp*(tmp-1);
	if(n%3==1) res+=tmp;
	else if(n%3==2) res+=tmp*2;
	res+=(1+tmp)*tmp/2*3-tmp;
	cout<<res;
	return 0;
}